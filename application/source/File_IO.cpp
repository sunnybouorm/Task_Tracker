/* Last updated : 18/12/2014
 * Date Created : 18/12/2014
 * Author       : Sultan Bou Orm
 */

#include <iostream>

#include "File_IO.h"
#include "DEBUG.h"
#include "OS.h"

using namespace std;

/*
 * Utility function used to parse a string of comma seperated values and
 * return the split elements as a vector of strings
 */
vector<string> File::parse_CSV(const string &line, vector<string> svect/*={}*/ ){
    string str;
    string buff;
    for(auto c : line){
        if(c!=','){
            buff.push_back(c);
        } else {
            svect.push_back(buff);
            buff.clear();
        }
    }
    return svect;
}

//general file functions
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

/*
 * Dump file into a vector<string> delimited by '\n' (removes '\n')
 * WARNING!!:
 * User must ensure that the appropriate file extension is supplied
 */
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

vector<string> File::file2vect(const std::string &filename,
        const std::string &directory)
{
    return file2vect(directory+filename);
}

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
 * <etc...>
 * <end of file>
 *--------------------------------------------
 * > Notes:
 * "<" and ">" are used to indicate an element and are not included in the file
 * <file start> and <end of file> and <etc...> are tags and not included in file
 * The meta file is essentially a text file used to save program data so that
 * the program's state can be recovered after quitting the application.
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
    const std::vector<std::string> tasks/*={}*/)
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
 * Writes task and category data to meta file based on the specified task and
 * categories. If overwrite parameter is passed as true the categories of an
 * existing task are overwritten. When overwrite is false any new categories
 * for an existing task are appended to the end of the line with the delimiter.
 * If a task does not exist then task data and associated categories are
 * appended to the end of the file following the meta file format.
 * NOTES:
 * > the user must ensure that the meta file format is adhered before using this
 * function
 */
void File::mf_write(const string &task,
    const vector<string> categories/*={}*/,
    const bool overwrite/*=false*/)
{
    bool append = true;//flag indicating whether the task exists in meta file
    //dump meta file into buffer1
    vector<string> buffer1 = file2vect(META_DIR+META_FN);

    //locate task and categories
    size_t pos1,pos2;
    string temp;
    for(auto line=buffer1.begin(); line!=buffer1.end();++line){
        pos1 = line->find("All categories: ");
        pos2 = line->find("Task name: ");
        //check if on task name label
        if(pos2!=string::npos){
            //check if specified task exists
            if( line->find(task) != string::npos){
                append = false;
                ++line;//move to "Categories: " label
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
        } else if(pos1!=string::npos){
            //check if categories exists and append new categories
            for(auto category : categories){
                if (line->find(category) == string::npos){
                    line->append(category + ",");
                }
            }
        }
    }

    if(append == true){
        //append new task and associated categories
        temp  = "Task name: " + task;
        buffer1.push_back(temp);

        temp = "Categories: ";
        for(auto category : categories){
            temp += category + ",";
        }
        buffer1.push_back(temp);
    }

    //dump modified buffer into meta file (overwriting existing file)
    vect2file(META_DIR+META_FN,buffer1);

}

/*
 * Writes category data to meta file's all categories label. If overwrite
 * parameter is passed as false then new categories are appended to the all
 * categories label. When overwrite is true the all categories label
 * is overwritten
 * NOTES:
 * > the user must ensure that the meta file format is adhered before prior to
 * using this function
 */
void File::mf_write_categories(const std::vector<std::string> &categories,
    const bool overwrite/*=false*/)
{
    //dump meta file into buffer1
    vector<string> buffer1 = file2vect(META_DIR+META_FN);

    //modify contents in "All categories: "
    if(overwrite == false){
        //append non existant categories
        for(auto category : categories){
            if( ( buffer1.begin() )->find(category) == string::npos){
                ( buffer1.begin() )->append(category + ",");
            }
        }
    } else{
        string line = "All categories: ";
        for(auto category : categories){
            if(category.empty() == false){
                line += category + ",";
            }
        }
        buffer1.insert(buffer1.begin(),line);
        if(buffer1.size() > 1){
            buffer1.erase(buffer1.begin()+1);
        }
    }

    //dump modified buffer into meta file (overwriting existing file)
    vect2file(META_DIR+META_FN,buffer1);
};

/*
 * Maps all relevant data from meta file
 * map keys:
 * key(literal)  = "allCat" contains all category names
 * key(literal)  = "allTsk" contains all task names
 * key(variable) = taskName contains all categories linked to taskName specified
 */
map<string, vector<string> > File::mf_map(){
    map<string, vector<string> > metaMap;
    metaMap["allCat"];
    metaMap["allTsk"];
    ifstream mf;//meta file
    if(mf_exists() == true){
        mf.open(META_DIR+META_FN);
        string line;
        string buff;
        string taskName;
        vector<string> svect;
        vector<string> taskNames;

        while(getline(mf,line) ) {

            if( line.find("All categories: ")!=string::npos ) {
                line.erase(0,16);//erase the label
                svect = parse_CSV(line);
                metaMap["allCat"] = svect;
            } else if(line.find("Task name: ")!=string::npos) {
                //store task names to map to "allTsk" when done iterating
                svect.clear();
                taskName = line.substr(11);
                taskNames.push_back(taskName);
            } else if(line.find("Categories: ")!=string::npos) {
                line.erase(0,12);//erase the label
                svect.clear();
                svect = parse_CSV(line);
                    //append all categories associated with added task
                metaMap[taskName] = svect;
            }
        }
        //map all task names acquired from the meta file to "allTsk"
        metaMap["allTsk"] = taskNames;
        mf.close();
    }
    return metaMap;
}

//task file functions
//------------------------------------------------------------------------------
/*
 * task meta file format:
 *--------------------------------------------
 * <file start>
 * <clockOnTime1> & <clockOffTime1>\n
 * <clockOnTime2> & <clockOffTime2>\n
 * <clockOnTime3> & <clockOffTime3>\n
 * <etc...>
 * <end of file>
 *--------------------------------------------
 * clockOnTime and clockOffTime format: "DD/MM/YYYY HH:MM:SS" 24 hour
 * example: "02/27/1990 01:02:03"
 * > Notes:
 * Clock on/off times are stored as global time (UTC)
 * "<" and ">" are used to indicate an element and are not included in the file
 * <file start> and <end of file> and <etc...> are tags and not included in file
 * The task file is essentially a text file used to save program data so that
 * the program's state can be recovered after quitting the application.
 */

/*
 * Checks if task file in TASK_DIR exists and returns
 * true if the file exists and false otherwise
 */
bool File::tf_exists(const std::string &filename){
    return exists(filename+TASK_EXT, TASK_DIR);
};

void File::tf_create(const string &filename){
    create(filename+TASK_EXT,TASK_DIR);
};

void File::tf_destroy(const string &filename){
    destroy(filename+TASK_EXT,TASK_DIR);
};

/*
 * appends clock on and clock off data intervals in appropriate task file format
 */
void File::tf_write(const string &filename,
    const vector<pair<string,string> > &timeStamps)
{
    fstream tf;//task file
    tf.open(TASK_DIR+filename+TASK_EXT,fstream::out | fstream::app);
    for(auto timeStamp : timeStamps) {
        tf << timeStamp.first << " & " << timeStamp.second << endl;
    }
    tf.close();
};

/*
 * Extracts all time stamp data from the specified task file and returns
 * the data in a vector in the following format:
 * {<pair 1>,<pair 2>,..,<pair n>}
 * where each pair contains : (<clockOnTime>,<clockOffTime>)
 * NOTES:
 * > The user must ensure that the .task file format is adhered prior to using
 * this function
 */
vector<pair<string,string> > File::tf_extract(const string &filename)
{
    vector<pair<string,string> > data;
    ifstream tf;//task file
    tf.open(TASK_DIR+filename+TASK_EXT);

    string line;
    pair<string,string> timeStamps;
    while(getline(tf,line) ) {
        //split string into pairs using " & " as a delimiter
        size_t pos = line.find("&");
        timeStamps.first = line.substr(0,pos-1);//clockOnTime
        timeStamps.second = line.substr(pos+2);//clockOffTime
        data.push_back(timeStamps);
    }

    tf.close();
    return data;
}
