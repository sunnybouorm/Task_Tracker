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
#include "FILE_DIRECTORIES.h"
#include "Core.h"
#include "Task_Manager.h"


void wait_sec(time_t seconds){
    Sleep(seconds * 1000);
};

SCENARIO("A task is clocked and unclocked","[core]")
{
    GIVEN("An initialized Core")
    {
        Core core;
        core.file.set_TASK_DIR(TASK_DIR);
        core.set_MIN_RECORD_TIME(1);//1 second
        Task *_tsk;
        THEN("the active task is initially empty")
        {
            _tsk = core.get_Active_Task();
            REQUIRE( _tsk->is_Empty() == true );
        }
        WHEN("Task1 is added and clocked on")
        {
            core.tskmgr.add("Task 1");
            _tsk = core.tskmgr.fetch("Task 1");
            REQUIRE(core.clock_On(_tsk) == 0);
            THEN("the active task is set to task 1")
            {
                _tsk = core.get_Active_Task();
                REQUIRE( _tsk->get_name() == "Task 1" );
            }
            AND_WHEN("minimum record time is NOT satisfied")
            {
                REQUIRE( core.clock_Off() == 1);
                THEN("the active task is set to the empty task")
                {
                    _tsk = core.get_Active_Task();
                    REQUIRE( _tsk->is_Empty() == true );
                }
            }
            AND_WHEN("the minimum record time IS satisfied")
            {
                wait_sec(core.get_MIN_RECORD_TIME() );
                REQUIRE( core.clock_Off() == 0);
            }
        }
        //destroy generated task file when done
        core.file.tf_destroy("Task 1");
    }
}

SCENARIO("recording time data to a single task file","[core]")
{
    GIVEN("An initialized Core")
    {
        Core core;
        core.file.set_TASK_DIR(TASK_DIR);
        core.set_MIN_RECORD_TIME(1);//1 second
        Task *_tsk;

        WHEN("A Task is clocked off successfuly")
        {
            core.tskmgr.add("Task 1");
            _tsk = core.tskmgr.fetch("Task 1");
            REQUIRE(core.clock_On(_tsk) == 0);
            wait_sec(core.get_MIN_RECORD_TIME() );
            REQUIRE( core.clock_Off() == 0);

            THEN("An entry must be made in associated .task file")
            {
                std::vector<std::string> svect =
                    core.file.file2vect("Task 1.task",TASK_DIR);
                REQUIRE( svect.size() == 1 ) ;
                //destroy generated task file when done
                core.file.tf_destroy("Task 1");
            }
            AND_WHEN("The same task is clocked off again unsuccessfully")
            {
                REQUIRE(core.clock_On(_tsk) == 0);
                REQUIRE(core.clock_Off() == 1);
                THEN("No additional entries must must be made in the .task file")
                {
                    std::vector<std::string> svect =
                    core.file.file2vect("Task 1.task",TASK_DIR);
                    REQUIRE( svect.size() == 1 ) ;
                    //destroy generated task file when done
                    core.file.tf_destroy("Task 1");
                }
            }
            AND_WHEN("The same task is clocked off again successfully")
            {
                REQUIRE(core.clock_On(_tsk) == 0);
                wait_sec(core.get_MIN_RECORD_TIME() );
                REQUIRE( core.clock_Off() == 0);
                THEN("A new entry must must be made in the associated .task file")
                {
                    std::vector<std::string> svect =
                    core.file.file2vect("Task 1.task",TASK_DIR);
                    REQUIRE( svect.size() == 2 ) ;
                    //destroy generated task file when done
                    core.file.tf_destroy("Task 1");
                }
            }
        }
    }
}

SCENARIO("Saving program state to a .meta file","[core]")
{
    GIVEN("An initialized Core")
    {
        Core core;
        core.file.set_META_DIR(META_DIR);
        WHEN("A task is linked to a category and the state is saved")
        {
            //Task 1 is linked to Category 1
            core.tskmgr.add("Task 1");
            core.ctgmgr.add("Category 1");
            Task *tp;
            Category *cp;
            tp = core.tskmgr.fetch("Task 1");
            cp = core.ctgmgr.fetch("Category 1");
            core.lnkmgr.link(tp,cp);
            core.save_prog_state();
            THEN("The saved data must be correct")
            {
                std::vector<std::string> matchBuff;
                matchBuff.push_back("All categories: Category 1,");
                matchBuff.push_back("Task name: Task 1");
                matchBuff.push_back("Categories: Category 1,");
                std::vector<std::string> fileBuff =
                    core.file.file2vect("meta.meta",META_DIR);
                REQUIRE(fileBuff == matchBuff);
            }
            AND_WHEN("More tasks and categories are added and the state saved")
            {
                //Task 2 is linked to categories 1 and 3
                core.ctgmgr.add("Category 2");
                core.ctgmgr.add("Category 3");
                core.tskmgr.add("Task 2");
                tp = core.tskmgr.fetch("Task 2");
                cp = core.ctgmgr.fetch("Category 1");
                core.lnkmgr.link(tp,cp);
                cp = core.ctgmgr.fetch("Category 3");
                core.lnkmgr.link(tp,cp);

                //Task 3 is linked to categories 1, 2 and 3
                core.tskmgr.add("Task 3");
                tp = core.tskmgr.fetch("Task 3");
                cp = core.ctgmgr.fetch("Category 1");
                core.lnkmgr.link(tp,cp);
                cp = core.ctgmgr.fetch("Category 2");
                core.lnkmgr.link(tp,cp);
                cp = core.ctgmgr.fetch("Category 3");
                core.lnkmgr.link(tp,cp);

                //Category 4 is not linked to any tasks
                core.ctgmgr.add("Category 4");

                core.save_prog_state();
                THEN("The saved data must be correct")
                {
                    std::vector<std::string> matchBuff;
                    matchBuff.push_back("All categories: Category 1,Category 2,Category 3,Category 4,");
                    matchBuff.push_back("Task name: Task 1");
                    matchBuff.push_back("Categories: Category 1,");
                    matchBuff.push_back("Task name: Task 2");
                    matchBuff.push_back("Categories: Category 1,Category 3,");
                    matchBuff.push_back("Task name: Task 3");
                    matchBuff.push_back("Categories: Category 1,Category 2,Category 3,");

                    std::vector<std::string> fileBuff =
                        core.file.file2vect("meta.meta",META_DIR);
                    REQUIRE(fileBuff == matchBuff);
                }
            }
        }
    }
}

SCENARIO("Loading program state from a .meta file","[core]")
{
    GIVEN("An initialized Core")
    {
        Core core;
        core.file.set_META_DIR(META_DIR);

        WHEN("The program state is loaded from the meta file")
        {
            core.load_prog_state();
            THEN("All data loaded must be present in the program")
            {
                //CHECK if all tasks and categories are loaded from the previous
                //save_prog_state() command
                std::vector<std::string> tasks;
                tasks.push_back("Task 1");
                tasks.push_back("Task 2");
                tasks.push_back("Task 3");
                std::vector<std::string> categories;
                categories.push_back("Category 1");
                categories.push_back("Category 2");
                categories.push_back("Category 3");
                categories.push_back("Category 4");
                REQUIRE(core.tskmgr.is_Exist(tasks) == true);
                REQUIRE(core.ctgmgr.is_Exist(categories) == true);

                //CHECK if links have loaded correctly
                Task *tp;
                Category *cp;

                tp = core.tskmgr.fetch("Task 1");
                cp = core.ctgmgr.fetch("Category 1");
                REQUIRE(core.lnkmgr.is_Linked(tp,cp) == true);
                cp = core.ctgmgr.fetch("Category 2");
                REQUIRE(core.lnkmgr.is_Linked(tp,cp) == false);
                cp = core.ctgmgr.fetch("Category 3");
                REQUIRE(core.lnkmgr.is_Linked(tp,cp) == false);
                cp = core.ctgmgr.fetch("Category 4");
                REQUIRE(core.lnkmgr.is_Linked(tp,cp) == false);

                tp = core.tskmgr.fetch("Task 2");
                cp = core.ctgmgr.fetch("Category 1");
                REQUIRE(core.lnkmgr.is_Linked(tp,cp) == true);
                cp = core.ctgmgr.fetch("Category 2");
                REQUIRE(core.lnkmgr.is_Linked(tp,cp) == false);
                cp = core.ctgmgr.fetch("Category 3");
                REQUIRE(core.lnkmgr.is_Linked(tp,cp) == true);
                cp = core.ctgmgr.fetch("Category 4");
                REQUIRE(core.lnkmgr.is_Linked(tp,cp) == false);

                tp = core.tskmgr.fetch("Task 3");
                cp = core.ctgmgr.fetch("Category 1");
                REQUIRE(core.lnkmgr.is_Linked(tp,cp) == true);
                cp = core.ctgmgr.fetch("Category 2");
                REQUIRE(core.lnkmgr.is_Linked(tp,cp) == true);
                cp = core.ctgmgr.fetch("Category 3");
                REQUIRE(core.lnkmgr.is_Linked(tp,cp) == true);
                cp = core.ctgmgr.fetch("Category 4");
                REQUIRE(core.lnkmgr.is_Linked(tp,cp) == false);

            }
        }
        //delete meta file when done
        core.file.mf_destroy();
    }
}
