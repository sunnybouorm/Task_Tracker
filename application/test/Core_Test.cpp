/* Date Created : 30/12/2014
 * Author       : Sultan Bou Orm
 */

#include "catch.hpp"
#include <vector>
#include <iostream>

#include "OS.h"
#include <stdlib.h> //for using the function sleep
#ifdef WINDOWS
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <dos.h>
#include <windows.h>
#endif // WINDOWS

#include "TEST_CASE_DEBUG_FILE.h"
#include "Core.h"
#include "Task_Manager.h"


void wait_sec(time_t seconds){
    Sleep(seconds * 1000);
};

SCENARIO("A task is clocked and unclocked","[core]")
{
    GIVEN("a set of initialized data")
    {
        Core core;
        Task *_tsk;
        Task_Manager tskmgr;
        THEN("the active task is initially empty")
        {
            _tsk = core.get_Active_Task();
            REQUIRE( _tsk->is_Empty() == true );
        }
        WHEN("Task1 is added and clocked on")
        {
            tskmgr.add("Task 1");
            _tsk = tskmgr.fetch("Task 1");
            REQUIRE(core.clock_On(_tsk) == 0);
            THEN("the active task is set to task 1")
            {
                _tsk = core.get_Active_Task();
                REQUIRE( _tsk->get_name() == "Task 1" );
            }
            AND_WHEN("minimum record time is NOT satisfied")
            {
                CHECK( core.clock_Off() == 1);
                THEN("the active task is set to the empty task")
                {
                    _tsk = core.get_Active_Task();
                    CHECK( _tsk->is_Empty() == true );
                }
            }
            AND_WHEN("the minimum record time IS satisfied")
            {
                #ifdef ALLOW_SLEEP_DELAYS
                _tsk = tskmgr.fetch("Task 1");
                wait_sec(MIN_RECORD_TIME);
                CHECK( core.clock_Off() == 0);
                #endif // ALLOW_SLEEP_DELAYS
            }
        }
    }
}

SCENARIO("recording time data to a single task file")
{
//TODO
}

SCENARIO("recording time data to multiple task files")
{
//TODO
}
