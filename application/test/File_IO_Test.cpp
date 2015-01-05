/* Date Created : 31/12/2014
 * Author       : Sultan Bou Orm
 */

#include "catch.hpp"
#include <vector>
#include <iostream>

#include "File_IO.h"
#include "Task_Manager.h"
#include "Category_Manager.h"


SCENARIO("A meta file is created and destroyed")
{
    GIVEN("an initialised set of data")
    {
        File file;
        std::string dir1 = "C:\\Users\\Sunny\\Documents\\codeblocks";
        std::string dir2 = "\\Task_Tracker\\application\\Program files\\";
        std::string dir  = dir1 + dir2;
        file.set_META_DIR(dir);
        REQUIRE(file.mf_create() == 0);
        REQUIRE(file.mf_exists() == true);
        WHEN("meta file is destroyed")
        {
            file.mf_destroy();
            REQUIRE(file.mf_exists() == false);
        }
    }
}

SCENARIO("tasks and categories are added/removed from the meta file")
{
    GIVEN("A meta file category manager and task manager")
    {
        Task_Manager tskmgr;
        Category_Manager ctgmgr;
        File file;
        std::string dir1 = "C:\\Users\\Sunny\\Documents\\codeblocks";
        std::string dir2 = "\\Task_Tracker\\application\\Program files\\";
        std::string dir  = dir1 + dir2;
        file.set_META_DIR(dir);
        REQUIRE(file.mf_create() == 0);
        WHEN("A task with no categories is added")
        {
            //TODO
            AND_WHEN("A new task with no categories is added")
            {
                //TODO
                //delete the meta file after use
                file.mf_destroy();
            }
        }
        GIVEN("A task with a category")
        {
            //TODO
            WHEN("A task with the same name is ADDDED")
            {
                //TODO
                THEN("The additional categories will be added to the task")
                {
                    //TODO
                }
                //delete the meta file after use
                file.mf_destroy();
            }
            WHEN("A task with the same name is WRITTEN")
            {
                //TODO
                THEN("The task will be overwritten")
                {
                    //TODO
                }
                //delete the meta file after use
                file.mf_destroy();
            }
            WHEN("The specified task is deleted")
            {
                //TODO
                THEN("The task must not exist in the meta file")
                {
                    //TODO
                }
                //delete the meta file after use
                file.mf_destroy();
            }
            WHEN("The specified category is deleted")
            {
                //TODO
                THEN("The category must not exist in the meta file")
                {
                    //TODO
                }
                //delete the meta file after use
                file.mf_destroy();
            }
            //delete the meta file after use
            file.mf_destroy();
        }

        GIVEN("Multiple tasks with multiple categories in the meta file")
        {
            //TODO
            WHEN("A specific Category is deleted from all tasks")
            {
                //TODO
                THEN("The category must not exist in the metafile")
                {
                    //TODO
                }
                //delete the meta file after use
                file.mf_destroy();
            }
            WHEN("A specific Category is deleted from specific tasks")
            {
                //TODO
                THEN("The category must not exist in the specified tasks")
                {
                    //TODO
                }
                //delete the meta file after use
                file.mf_destroy();
            }
        }
    }
}
