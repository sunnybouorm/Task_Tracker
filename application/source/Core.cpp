/* Date Created : 19/12/2014
 * Author       : Sultan Bou Orm
 */

#include "Core.h"

using namespace std;
using std::chrono::system_clock;


Core::Core(){
    activeTask = &emptyTask;
};

/*
 * Records clock on time for a given task and sets it as the activeTask
 * returns <1=fail> <0=pass>
 * (returns fail if _task is empty or another active task hasn't clocked off)
 */
bool Core::clock_On(Task *_task){
    bool status = 1;
    if( (activeTask->is_Empty()==true) && (_task->is_Empty()==false) )
    {
        status = 0;
        activeTask = _task;
        system_clock::time_point sysTime = system_clock::now();
        clockOnTimeStamp = system_clock::to_time_t ( sysTime );
    }
    return status;
};

/*
 * Records clock off time for the current active task and sets the active task
 * to emptyTask once the operation is complete.
 * The clock off timestamp is appended to the active task's file
 * if the duration from start to finish is less than MIN_RECORD_TIME
 * returns <0=pass> <1=fail>
 * (returns fail when no active task or MIN_RECORD_TIME not satisfied)
 */
bool Core::clock_Off(void){
    bool status = 1;
    if( activeTask->is_Empty() == false ) {
        system_clock::time_point sysTime = system_clock::now();
        std::time_t clockOffTimeStamp;
        clockOffTimeStamp = system_clock::to_time_t ( sysTime );

        if (difftime(clockOffTimeStamp, clockOnTimeStamp) >= MIN_RECORD_TIME )
        {
            status = 0;
            //record data in task file
            //TODO:
        };

        activeTask = &emptyTask;
    }
    return status;
};

Task* Core::get_Active_Task(void){
    return activeTask;
};
