/* Date Created : 19/12/2014
 * Author       : Sultan Bou Orm
 * Description  :
 * Core program functionality
 */

#ifndef CORE_H
#define CORE_H

#include <chrono>

#include "File_IO.h"
#include "Task_Manager.h"
#include "Category_Manager.h"
#include "Link_Manager.h"

class Core {
private :
    Task emptyTask;
    Task *activeTask;
    time_t clockOnTimeStamp;
    uint8_t MIN_RECORD_TIME = 60; //in seconds
    //utility functions
    std::string tt2UTC(time_t &tt,
        std::string formatString = "%m/%d/%y %H:%M:%S");//converts time_t to UTC
    //modifiers
    bool set_active(Task *task);
public :
    Link_Manager lnkmgr;
    Task_Manager tskmgr;
    Category_Manager ctgmgr;
    File file;

    Core();

    //public modifiers
    void set_MIN_RECORD_TIME(const uint8_t &t){MIN_RECORD_TIME = t;}
    bool clock_On(Task *task);//record clock on time of task
    bool clock_Off();//record clock off time of clocked on task
    void save_prog_state();
    void load_prog_state();

    //public accessors
    Task* get_Active_Task();
    uint8_t get_MIN_RECORD_TIME(){return MIN_RECORD_TIME;}
};

#endif//CORE_H
