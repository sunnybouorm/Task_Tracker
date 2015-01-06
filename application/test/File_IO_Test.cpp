/* Date Created : 31/12/2014
 * Author       : Sultan Bou Orm
 */

#include "catch.hpp"
#include <vector>
#include <iostream>

#include "File_IO.h"
#include "Task_Manager.h"
#include "Category_Manager.h"


SCENARIO("A meta file is created and destroyed","[fileIO]")
{
    GIVEN("an initialised set of data")
    {
        File file;
        std::string dir = "C:\\Users\\Sunny\\Documents\\codeblocks";
        dir += "\\Task_Tracker\\application\\Program files\\";
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

SCENARIO("tasks and categories are added/removed from the meta file","[fileIO]")
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
        std::string META_DIR = file.get_META_DIR();
        REQUIRE(file.mf_create() == 0);
        std::vector<std::string> matchBuff;
        std::vector<std::string> fileBuff;
        std::vector<std::string> tasks;
        std::vector<std::string> categories;
        bool overwrite;
        std::string str;

        WHEN("A task with no categories is added")
        {
            matchBuff.clear();
            matchBuff.push_back("All categories: ");
            matchBuff.push_back("Task name: task1");
            matchBuff.push_back("Categories: ");
            tasks = {"task1"};
            file.mf_write(tasks);
            fileBuff = file.file2vect(META_DIR+META_FN);
            REQUIRE(fileBuff==matchBuff);

            AND_WHEN("A new task with no categories is added")
            {
                matchBuff.push_back("Task name: task2");
                matchBuff.push_back("Categories: ");
                tasks = {"task2"};
                file.mf_write(tasks);
                fileBuff = file.file2vect(META_DIR+META_FN);
                REQUIRE(fileBuff==matchBuff);

                //delete the meta file after use
                file.mf_destroy();
            }
        }
        GIVEN("A task with a category")
        {
            matchBuff.clear();
            matchBuff.push_back("All categories: category1,");
            matchBuff.push_back("Task name: task1");
            matchBuff.push_back("Categories: category1,");
            tasks = {"task1"};
            categories = {"category1"};
            overwrite = false;
            file.mf_write(tasks,categories,overwrite);
            fileBuff = file.file2vect(META_DIR+META_FN);
            REQUIRE(fileBuff==matchBuff);

            WHEN("A task with the same name is written with overwrite=false")
            {
                matchBuff.clear();
                matchBuff.push_back("All categories: category1,category2,");
                matchBuff.push_back("Task name: task1");
                matchBuff.push_back("Categories: category1,category2,");
                tasks = {"task1"};
                categories = {"category2"};
                overwrite = false;
                file.mf_write(tasks,categories,overwrite);

                THEN("The additional categories will be added to the task")
                {
                    fileBuff = file.file2vect(META_DIR+META_FN);
                    REQUIRE(fileBuff==matchBuff);
                }
                //delete the meta file after use
                file.mf_destroy();
            }
            WHEN("A task with the same name is written with overwrite=true")
            {
                matchBuff.clear();
                matchBuff.push_back("All categories: category1,category2,");
                matchBuff.push_back("Task name: task1");
                matchBuff.push_back("Categories: category2,");
                tasks = {"task1"};
                categories = {"category2"};
                overwrite = true;
                file.mf_write(tasks,categories,overwrite);
                THEN("The task will be overwritten")
                {
                    fileBuff = file.file2vect(META_DIR+META_FN);
                    REQUIRE(fileBuff==matchBuff);
                }
                //delete the meta file after use
                file.mf_destroy();
            }
            WHEN("A specific task is deleted")
            {
                matchBuff.clear();
                matchBuff.push_back("All categories: category1,");
                tasks = {"task1"};
                file.mf_delete_tasks(tasks);
                THEN("The task must not exist in the meta file")
                {
                    fileBuff = file.file2vect(META_DIR+META_FN);
                    REQUIRE(fileBuff==matchBuff);
                }
                //delete the meta file after use
                file.mf_destroy();
            }
            WHEN("A specific category is deleted")
            {
                matchBuff.clear();
                matchBuff.push_back("All categories: ");
                matchBuff.push_back("Task name: task1");
                matchBuff.push_back("Categories: ");
                categories = {"category1"};
                file.mf_delete_categories(categories);
                THEN("The category must not exist in the meta file")
                {
                    fileBuff = file.file2vect(META_DIR+META_FN);
                    REQUIRE(fileBuff==matchBuff);
                }
                //delete the meta file after use
                file.mf_destroy();
            }
            //delete the meta file after use
            file.mf_destroy();
        }

        GIVEN("Multiple tasks with multiple categories in the meta file")
        {
            matchBuff.clear();
            str = "All categories: category1,category2,category3,";
            matchBuff.push_back(str);
            matchBuff.push_back("Task name: task1");
            str = "Categories: category1,category2,category3,";
            matchBuff.push_back(str);
            matchBuff.push_back("Task name: task2");
            matchBuff.push_back(str);
            matchBuff.push_back("Task name: task3");
            matchBuff.push_back(str);
            tasks = {"task1","task2","task3"};
            categories = {"category1","category2","category3"};
            overwrite = false;
            file.mf_write(tasks,categories,overwrite);
            fileBuff = file.file2vect(META_DIR+META_FN);
            REQUIRE(fileBuff==matchBuff);

            WHEN("A category is deleted from all tasks")
            {
                //TODO
                matchBuff.clear();
                str = "All categories: category1,category3,";
                matchBuff.push_back(str);
                matchBuff.push_back("Task name: task1");
                str = "Categories: category1,category3,";
                matchBuff.push_back(str);
                matchBuff.push_back("Task name: task2");
                matchBuff.push_back(str);
                matchBuff.push_back("Task name: task3");
                matchBuff.push_back(str);
                categories = {"category2"};
                file.mf_delete_categories(categories);

                THEN("The category must not exist in the metafile")
                {
                    fileBuff = file.file2vect(META_DIR+META_FN);
                    REQUIRE(fileBuff==matchBuff);
                }
                //delete the meta file after use
                file.mf_destroy();
            }
            WHEN("Specific Categories are deleted from specific tasks")
            {
                matchBuff.clear();
                str = "All categories: category1,category2,category3,";
                matchBuff.push_back(str);
                matchBuff.push_back("Task name: task1");
                matchBuff.push_back("Categories: category2,");
                matchBuff.push_back("Task name: task2");
                str = "Categories: category1,category2,category3,";
                matchBuff.push_back(str);
                matchBuff.push_back("Task name: task3");
                matchBuff.push_back("Categories: category2,");
                tasks = {"task1","task3"};
                categories = {"category3","category1"};
                file.mf_delete_categories(categories,tasks);
                THEN("The categories must not exist in the specified tasks")
                {
                    fileBuff = file.file2vect(META_DIR+META_FN);
                    REQUIRE(fileBuff==matchBuff);
                }
                //delete the meta file after use
                file.mf_destroy();
            }
        }
    }
}

SCENARIO("A .task file is created and deleted","[fileIO]")
{
    GIVEN("An initialized File class object")
    {
        File file;
        std::string dir = "C:\\Users\\Sunny\\Documents\\codeblocks";
        dir += "\\Task_Tracker\\application\\Program files\\task files\\";
        file.set_TASK_DIR(dir);
        WHEN("A task file is created")
        {
            file.tf_create("task1");
            THEN("The task file must exist")
            {
                REQUIRE( file.tf_exists("task1") == true );
            }
            AND_WHEN("The task file is deleted")
            {
                file.tf_destroy("task1");
                THEN("The task file must not exist")
                {
                    REQUIRE( file.tf_exists("task1") == false );
                }
            }
        }
    }
}

SCENARIO("Timestamps are appended to a .task file and extracted","[fileIO]")
{
    GIVEN("An initialized File class object")
    {
        File file;
        std::string dir = "C:\\Users\\Sunny\\Documents\\codeblocks";
        dir += "\\Task_Tracker\\application\\Program files\\task files\\";
        file.set_TASK_DIR(dir);
        std::string filename = "task1";
        std::string TASK_DIR = file.get_TASK_DIR();
        file.tf_create(filename);
        std::vector<std::string> matchBuff;
        std::vector<std::string> fileBuff;

        WHEN("Data is appeneded to a task file")
        {
            std::vector<std::pair<std::string,std::string> > timeStamps;
            std::string ts1 = "06 01 2015 16:42:00";
            std::string ts2 = "06 01 2015 17:42:00";
            std::pair<std::string,std::string> timeStamp (ts1,ts2);
            timeStamps.push_back(timeStamp);
            timeStamp.first  = "07 01 2015 10:42:00";
            timeStamp.second = "07 01 2015 12:42:00";
            timeStamps.push_back(timeStamp);
            file.tf_write(filename,timeStamps);
            THEN("That data must exist in the task file")
            {
                matchBuff.clear();
                matchBuff.push_back("06 01 2015 16:42:00 & 06 01 2015 17:42:00");
                matchBuff.push_back("07 01 2015 10:42:00 & 07 01 2015 12:42:00");
                fileBuff = file.file2vect(filename+TASK_EXT, TASK_DIR);
                REQUIRE(fileBuff == matchBuff);
            }
            AND_WHEN("Data is extracted from the file")
            {
                std::vector<std::pair<std::string,std::string> > data;
                data = file.tf_extract(filename);
                THEN("The data must be valid")
                {
                    REQUIRE(data == timeStamps);
                }
            }
            //delete task file when done
            file.tf_destroy(filename);
        }
    }
}
