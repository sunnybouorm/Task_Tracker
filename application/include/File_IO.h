/* Last updated : 18/12/2014
 * Date Created : 18/12/2014
 * Author       : Sultan Bou Orm
 * Description  :
 * Manages Files relevant to the program
 * Notes:
 * > A task meta file stores meta data related to tasks. It is used primarily to
 * save the state of the program to recover data if the process is restarted.
 */
#ifndef FILE_IO_H
#define FILE_IO_H

#include<iostream>
#include<vector>
#include<map>

#include <fstream>

const std::string META_FN = "meta.meta";
const std::string TASK_EXT = ".task";

constexpr int STREAM_SIZE = 256;

class File {
private:
    //task meta data
    std::vector<std::vector<std::string>> taskMetaData;
    std::string META_DIR;//meta file directory

    //general file functions
    //--------------------------------------------------------------------------
    std::vector<std::string> file2vect(const std::string &filename);
    void vect2file (const std::string &filename,
        const std::vector<std::string> &buffer,
        const bool append);
public:
    File(){ };

    //general file functions
    //--------------------------------------------------------------------------
    const bool exists(const std::string &fileName);
    const bool exists(const std::string &fileName,
                      const std::string &directory);
    const bool create(const std::string &fileName);
    const bool create(const std::string &fileName,
                      const std::string &directory);
    const bool destroy(const std::string &fileName);
    const bool destroy(const std::string &fileName,
                       const std::string &directory);
    void wipe();//deletes all files created by the program //TODO
    void set_META_DIR(const std::string dir){META_DIR = dir;};

    //functions applicable to the task meta file ".meta"
    //--------------------------------------------------------------------------
    const bool mf_exists(){return exists(META_FN, META_DIR);}
    const bool mf_create(); //create a new task meta file template
    const bool mf_destroy();//deletes the meta file
        //append new tasks and their respective categories to the task meta file

    void mf_delete_tasks(const std::vector<std::string> &tasks);//TODO
        //deletes specified tasks and all associated categories
    void mf_delete_categories(const std::vector<std::string> &categories,
        const std::vector<std::string> tasks);
        //deletes specified categories from specified tasks

    void mf_write(std::vector<std::string> tasks,
        const std::vector<std::string> &categories, const bool overwrite);

    const std::vector<std::vector<std::string> > mf_load_all();//TODO
        //load all relevant data from task meta file

    //functions applicable to the task files ".task"
    //--------------------------------------------------------------------------

};

#endif // File_IO_H
