/* Last updated : 18/12/2014
 * Date Created : 18/12/2014
 * Author       : Sultan Bou Orm
 */
#include <iostream>
#include <fstream>

#include "File_IO.h"
#include "DEBUG.h"

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
 * All categories: <cat1>,<cat2>,...,<catn>\n
 * Task name: <task1>\n
 * Categories: <cat1>,<cat2>,...,<catn>\n
 * Task name: <task2>\n
 * Categories: <cat1>,<cat2>,...,<catn>\n
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

/* tm_add_tasks:
 * appends new tasks to the task meta file, and returns <0=pass>,<1=fail>
 * valid input formats:
 * >(1) a vector of vectors containing strings, the first element of each
 * vector would contain the task, the rest contain categories that belong to
 * their respective task.
 * { <task1,cat1,cat2,...catn>, <task2,cat1,cat2,...catn>,...}
 * >(2) a vector of strings where all elements are tasks with no associated
 * categories to be added.
 *
 * NOTES:
 * > This function is not secure, it does not check if the file is in use.
 * So be wary of any potential race conditions.
 * > Be wary of duplicates, this method does not check for prexisting tasks,
 * hence this method is only suitable for adding NEW tasks, it is NOT suitable
 * for the modification of predefined tasks.
 */

void File::mf_app_tasks(vector<vector<string> > tasks){
    if (tasks.empty() == false ){
        ofstream fs;
        fs.open(META_DIR + META_FN, ofstream::out | ofstream::app);
        for(auto vect : tasks){
            //skip to next vector if task name empty
            if(vect.begin() != vect.end()){
                //fetch task name followed by associated categories
                for(auto it = vect.begin(); it != vect.end(); ++it){
                    if(it == vect.begin()){
                        fs << "Task name: " << *it << endl;
                        fs << "Categories: ";
                        if(vect.begin() == (vect.end()-1) ){
                            fs << endl;//newline since no categories detected
                        }
                    } else if( (it->empty() ) == false ) {
                        fs << *it;
                        if(it != (vect.end()-1) ){
                            fs << ",";
                        } else {
                            fs << endl;
                        }
                    }
                }
            }
        }
        fs.close();
    }
};

void File::mf_app_tasks(vector<string> tasks){
    vector<vector<string>> dvect;//double vector
    vector<string> temp_buff;
    for(auto task : tasks){
        temp_buff.push_back(task);
        dvect.push_back(temp_buff);
        temp_buff.pop_back();
    }
    mf_app_tasks(dvect);
};
