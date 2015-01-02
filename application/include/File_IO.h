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

const std::string META_FN = "task.meta";
const std::string TASK_EXT = ".task";

class File {
private:
    //task meta data
    std::vector<std::vector<std::string>> taskMetaData;
    std::string META_DIR;//meta file directory
public:
    File(){ };

    //general file functions
    const bool exists(const std::string &fileName);
    const bool exists(const std::string &fileName,
                      const std::string &directory);
    const bool create(const std::string &fileName);
    const bool create(const std::string &fileName,
                      const std::string &directory);
    const bool destroy(const std::string &fileName);
    const bool destroy(const std::string &fileName,
                       const std::string &directory);
    void wipe(void);//deletes all files created by the program //TODO
    void set_META_DIR(std::string dir){META_DIR = dir;};

    //functions applicable to the task meta file ".meta"
    //--------------------------------------------------------------------------
    const bool mf_exists(void){return exists(META_FN, META_DIR);}
    const bool mf_create(); //create a new task meta file template
    void mf_app_tasks(std::vector<std::vector<std::string> >tasks);
    void mf_app_tasks(std::vector<std::string> tasks);
        //append new tasks and their respective categories to the task meta file
    const bool mf_del_tasks(std::vector<std::string> tasks);
    const bool mf_add_cats(std::string task,
        std::vector<std::string> categories);
        //add categories to task meta file
    const bool mf_del_cats(std::vector<std::string> categories);
        //delete categories from task meta file
    const bool mf_wipe(void);//deletes the meta file
    std::vector<std::vector<std::string> > mf_load_all();
        //load all relevant data from task meta file

    //functions applicable to the task files ".task"
    //--------------------------------------------------------------------------

};

#endif // File_IO_H
