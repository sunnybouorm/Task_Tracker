/* Last updated : 18/12/2014
 * Date Created : 18/12/2014
 * Author       : Sultan Bou Orm
 */

#include <iostream>

#include "File_IO.h"
#include "DEBUG.h"
#include "OS.h"

using namespace std;

//constructors

// member functions
//==============================================================================

//general file functions(Private)
//------------------------------------------------------------------------------
const bool File::exists (const string &fileName){
    fstream file;
    file.open(fileName, fstream::out | fstream::in);//does not create file

    if(file.is_open() ){
        #if defined FIO_STREAMO && defined FIO_EXISTS
        cout << "file <" << fileName << "> exists" << endl;
        #endif // FIO_STREAMO
        file.close();
        return true;
    } else{
        #if defined FIO_STREAMO && defined FIO_EXISTS
//        #ifdef FIO_EXISTS
        cout << "file <" << fileName << "> does not exist" << endl;
        #endif // FIO_STREAMO
        file.close();
        return false;
    }
}

const bool File::exists (const string &fileName, const string &directory){
    const string s = directory + fileName;
    return exists(s);
}

//create a file and return the status as bool : <pass=0>, <fail=1>
const bool File::create(const string &fileName){
    fstream file;
    file.open(fileName, fstream::out);//creates file
    file.close();

    if(exists(fileName)){
        #if defined FIO_STREAMO && defined FIO_CREATE
        cout << "file <" << fileName << "> creation succeeded" << endl;
        #endif // FIO_STREAMO
        return(0);
    } else {
        #if defined FIO_STREAMO && defined FIO_CREATE
        cout << "file <" << fileName << "> creation failed" << endl;
        #endif // FIO_STREAMO
        return(1);
    }
}

const bool File::create(const string &fileName, const std::string &directory){
    const string s = directory + fileName;
    return create(s);
}

//deletes file and returns bool status: <0=pass>,<1=fail>
//note: this function is not secure and may delete the file even if it is in use
const bool File::destroy(const std::string &fileName){
    int status = 1;
    const char* cptr = &fileName[0];
    status = remove(cptr);

    #if defined FIO_STREAMO && defined FIO_DESTROY
    if(status){
        cout << "file <" << fileName << "> deletion failed" << endl;
    } else{
        cout << "file <" << fileName << "> deletion succeeded" << endl;
    }
    #endif // FIO_STREAMO

    return status;
}

const bool File::destroy(const std::string &fileName,
                        const std::string &directory){
    const string s = directory + fileName;
    return destroy(s);
}

/* dump file into a vector<string> delimited by '\n' (removes '\n') */
vector<string> File::file2vect(const string &filename){
    std::fstream fs;
    fs.open(filename, fstream::in);
    vector<string> buffer;
    string line;
    while( getline(fs,line) ){
        buffer.push_back(line);
    }
    fs.close();
    return buffer;
};

/* dump vector<string> into a file adding '\n' after each element
 * if append = true, data is appended to the end of file
 * if append = false, the file is overwritten and truncated
 */
void File::vect2file (const string &filename, const vector<string> &buffer,
    const bool append=false)
{
    //dump modified buffer into meta file
    fstream fs;
    if(append==false){fs.open(filename, fstream::out | fstream::trunc);}
    else{fs.open(filename, fstream::out | fstream::app);}
    for(auto line : buffer){
        fs << line << endl;
    }
    fs.close();
}

//general file functions(Public)
//------------------------------------------------------------------------------
void wipe(void){
    //TODO
};

//meta file functions
//------------------------------------------------------------------------------
/*
 * task meta file format:
 *--------------------------------------------
 * <file start>
 * All categories: <cat1>,<cat2>,...,<catn>,\n
 * Task name: <task1>\n
 * Categories: <cat1>,<cat2>,...,<catn>,\n
 * Task name: <task2>\n
 * Categories: <cat1>,<cat2>,...,<catn>,\n
 * etc...
 * <end of file>
 *--------------------------------------------
 */

/* mf_create:
 * creates a fresh task meta file template if task meta file doesn't exist
 * if task meta file exists does not create a meta file and returns with a pass.
 * returns a bool where: <0=pass>, <1=fail>
 *
 * NOTES:
 * only the first line "All categories: " is set when creating a new file
 */
const bool File::mf_create(){
    fstream fs;
    if(mf_exists()== false){
        //create a fresh task meta file
        bool status = 0;
        status = create(META_FN, META_DIR);
        fs.open(META_DIR + META_FN, fstream::out | fstream::app);
        fs << "All categories: " << endl;
        fs.flush();
        fs.close();
        return status;
    } else {
        return(0);//file already exists, function returns successfully
    }
};

/*
 * deletes the meta file and returns <0=pass> <1=fail>
 */
const bool File::mf_destroy(){
    return destroy(META_DIR + META_FN);
};

/*
 * Removes specified tasks and their associated categories
 * (excluding the "All categories: " section) from the meta file.
 * NOTES:
 * > The user must ensure the meta file format is adhered
 */
void File::mf_delete_tasks(const std::vector<std::string> &tasks)
{
    if( tasks.empty() == false ) {
        //dump meta file into buffer
        vector<string> buffer = file2vect(META_DIR+META_FN);
        std::fstream fs;
        fs.open(META_DIR+META_FN, fstream::in);

        //delete each specified task found and associated categories
        size_t pos;
        for(auto line=buffer.begin(); line!=buffer.end();++line){
            for(auto task : tasks){
                pos = line->find("Task name: " + task);
                if(pos!=string::npos){
                    //erase task lines and associated category lines
                    buffer.erase(line,line+2);
                    --line;
                }
            }
        }
        fs.close();

        //dump modified buffer into meta file (overwrites existing file)
        vect2file(META_DIR+META_FN,buffer);

    }
};

/*
 * Removes specified categories belonging to the specified tasks
 * (excluding the "All categories: " section) from the meta file unless no tasks
 * are provided, in which case all specified categories in the file
 * (including the "All categories: " section) are removed from the metafile.
 * NOTES:
 * > The user must ensure the meta file format is adhered
 */
void File::mf_delete_categories(const std::vector<std::string> &categories,
    const std::vector<std::string> tasks={})
{
    bool remAllCat = false;//signals the removal of all categories
    if(tasks.empty() == true){
        remAllCat = true;
    }
    if( categories.empty() == false ) {
        //dump meta file into buffer
        vector<string> buffer = file2vect(META_DIR+META_FN);
        std::fstream fs;
        fs.open(META_DIR+META_FN, fstream::in);

        //delete each specified Category found under specified tasks unless
        //tasks is empty
        size_t pos,pos1,pos2,pos3;
        bool harvest = false;//signals to allow category deletion
        for(auto line=buffer.begin(); line!=buffer.end();++line){
            pos1 = line->find("All categories: ");
            pos2 = line->find("Task name: ");
            pos3 = line->find("Categories: ");

            //search for categories under specified tasks granted tasks is not
            //empty, otherwise delete all specified categories in the file
            if( (pos2!=string::npos) && (remAllCat==false) ){
                for(auto task : tasks){
                    if(line->find(task)!=string::npos){harvest = true;}
                }
            } else if( ( (pos1!=string::npos) || (pos3!=string::npos) ) &&
                ((harvest==true) || (remAllCat==true)) )
            {
                for(auto category : categories){
                    //find matching category
                    pos = line->find(category);
                    if(pos != string::npos){
                        //erase matching category and associated delimiter
                        line->erase(pos, category.size() + 1 );
                    }
                }
                harvest = false;
            }
        }
        fs.close();

        //dump modified buffer into meta file (overwrites existing file)
        vect2file(META_DIR+META_FN,buffer);
    }
};

/*
 * Writes task and category data to meta file based on specified tasks and
 * categories. If overwrite parameter is passed as true the categories for an
 * existing tasks are overwritten. When overwrite is false any new categories
 * for an existing task are appended to the end of the line with the delimiter.
 * If a task does not exist then task data and associated categories are
 * appended to the end of the file following the meta file format.
 * NOTES:
 * > the user must ensure that the meta file format is adhered before using this
 * function
 */
void File::mf_write(std::vector<std::string> tasks,
        const std::vector<std::string> &categories, const bool overwrite=false)
{
    //dump meta file into buffer1
    vector<string> buffer1 = file2vect(META_DIR+META_FN);
    vector<string> buffer2;//used to push_back data to buffer 1 to avoid
                           //invalidating the iterator
    std::fstream fs;
    fs.open(META_DIR+META_FN, fstream::in);

    //locate tasks and categories
    size_t pos1,pos2;
    string temp;
    for(auto line=buffer1.begin(); line!=buffer1.end();++line){
        pos1 = line->find("All categories: ");
        pos2 = line->find("Task name: ");
        //check if on task name label
        if(pos2!=string::npos){
            for (auto task=tasks.begin(); task!=tasks.end(); ++task){
                //check if a specified task exists
                if( line->find(*task) != string::npos){
                    ++line;//move to "Categories: " label
                    tasks.erase(task);//task is no longer a candidate
                    --task;//decrement iterator to make its position valid
                    if(overwrite == false){
                        for(auto category : categories){
                            if(line->find(category)==string::npos){
                                line->append(category + ",");
                            }
                        }
                    } else { //rewrite categories for task
                        line->erase(12,line->size());
                        for(auto category : categories){
                            line->append(category + ",");
                        }
                    }
                }
            }
        } else if(pos1!=string::npos){
            //check if categories exists and append new categories
            for(auto category : categories){
                if (line->find(category) == string::npos){
                    line->append(category + ",");
                }
            }
        }
    }

    //append new task and associated categories
    for(auto task : tasks){
        temp  = "Task Name: " + task;
        buffer2.push_back(temp);

        temp = "Categories: ";
        for(auto category : categories){
            temp += category + ",";
        }
        buffer2.push_back(temp);
    }
    buffer1.insert( buffer1.end(), buffer2.begin(), buffer2.end() );

    fs.close();

    //dump modified buffer into meta file (overwriting existing file)
    vect2file(META_DIR+META_FN,buffer1);

}
