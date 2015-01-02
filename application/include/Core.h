/* Date Created : 19/12/2014
 * Author       : Sultan Bou Orm
 * Description  :
 * Core program functionality
 */

#ifndef CORE_H
#define CORE_H

#include "Task.h"
#include <chrono>

const uint8_t MIN_RECORD_TIME = 60; //in seconds

class Core {
private :
    Task emptyTask;
    Task *activeTask;
    time_t clockOnTimeStamp;

    //private modifiers
    bool set_active(Task *task);
public :
    Core();

    //public modifiers
    bool clock_On(Task *task);//record clock on time of task
    bool clock_Off();//record clock off time of clocked on task

    //public accessors
    Task* get_Active_Task(void);
};

#endif//CORE_H
