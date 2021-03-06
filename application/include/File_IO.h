/* Last updated : 18/12/2014
 * Date Created : 18/12/2014
 * Author       : Sultan Bou Orm
 * Description  :
 * Manages Files relevant to the program
 * Notes:
 * > A task meta file stores meta data related to tasks. It is used primarily to
 * save the state of the program to recover data after quitting the application.
 */
#ifndef FILE_IO_H
#define FILE_IO_H

#include<iostream>
#include<vector>
#include<map>
#include <fstream>

const std::string META_FN = "meta.meta";
const std::string TASK_EXT = ".task";

class File {
private:
    //task meta data
    std::string META_DIR;//meta file directory
    std::string TASK_DIR;//task file directory

    //general file functions
    //--------------------------------------------------------------------------
    void vect2file (const std::string &filename,
        const std::vector<std::string> &buffer,
        const bool append);

    //Utility functions
    //--------------------------------------------------------------------------
    std::vector<std::string> parse_CSV(const std::string &line,
        std::vector<std::string> svect={} );
        //parses comma seperated values into a vector
public:
    File(){ };

    //general file functions
    //--------------------------------------------------------------------------
    bool exists(const std::string &fileName);
    bool exists(const std::string &fileName,
                      const std::string &directory);
    bool create(const std::string &fileName);
    bool create(const std::string &fileName,
                      const std::string &directory);
    bool destroy(const std::string &fileName);
    bool destroy(const std::string &fileName,
                       const std::string &directory);
    std::vector<std::string> file2vect(const std::string &filename);
    std::vector<std::string> file2vect(const std::string &filename,
        const std::string &directory);
        //parses all lines using '\n' as delimiter appending them into a vector

    //functions applicable to the task meta file ".meta"
    //--------------------------------------------------------------------------
    void set_META_DIR(const std::string &dir){META_DIR = dir;};
    std::string get_META_DIR(){return META_DIR;};
    bool mf_exists(){return exists(META_FN, META_DIR);}
    bool mf_create(); //create a new task meta file template
    bool mf_destroy();//deletes the meta file
        //append new tasks and their respective categories to the task meta file

    void mf_delete_tasks(const std::vector<std::string> &tasks);
        //deletes specified tasks and all associated categories
    void mf_delete_categories(const std::vector<std::string> &categories,
        const std::vector<std::string> tasks={});
        //deletes specified categories from specified tasks

    void mf_write(const std::string &task,
        const std::vector<std::string> categories={},
        const bool overwrite=false);
        //writes specified tasks and categories to meta file

    void mf_write_categories(const std::vector<std::string> &categories,
        const bool overwrite=false);
        //writes categories to the "All categories: " label in meta file

    std::map<std::string, std::vector<std::string> > mf_map();
        //map all relevant data from meta file

    //functions applicable to the task files ".task"
    //--------------------------------------------------------------------------
    void set_TASK_DIR(const std::string &dir){TASK_DIR = dir;};
    std::string get_TASK_DIR(){return TASK_DIR;};
    bool tf_exists(const std::string &filename);
    void tf_create(const std::string &filename);
    void tf_destroy(const std::string &filename);
    void tf_write(const std::string &filename,
        const std::vector<std::pair<std::string,std::string> > &timeStamps);
        //appends time stamp data to task file in appropriate task file format
    std::vector<std::pair<std::string,std::string> > tf_extract(
        const std::string &filename); //exctracts all time stamps from task file
};

#endif // File_IO_H
