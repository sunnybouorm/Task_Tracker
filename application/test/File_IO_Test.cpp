/* Date Created : 31/12/2014
 * Author       : Sultan Bou Orm
 */

#include "catch.hpp"
#include <vector>
#include <iostream>

#include "File_IO.h"
#include "Task_Manager.h"
#include "Category_Manager.h"


SCENARIO("A meta file is created, edited, and deleted")
{
    GIVEN("an initialised set of data")
    {
        File file;
        Task_Manager tskmgr;
        Category_Manager ctgmgr;

        std::string dir1 = "C:\\Users\\Sunny\\Documents\\codeblocks";
        std::string dir2 = "\\Task_Tracker\\application\\Program files\\";
        std::string dir  = dir1 + dir2;
        file.set_META_DIR(dir);
        CHECK(file.mf_create() == 0);
        CHECK(file.mf_exists() == true);
        WHEN("task data is appeneded to meta file as a double vector")
        {
            tskmgr.add({"Task 1","Task 2","Task 3"});
            std::vector<std::vector<std::string> > dvect =
                {   {"Task 1", "Category 1"}, {"Task 2"},
                    {"Task 3","Category 3", "Category 4"}   };
            file.mf_app_tasks(dvect);
            //TODO
        }
        WHEN("task data is appeneded to meta file as a single vector")
        {
            std::vector<std::string> vect = { "Task 1","Task 2","Task 3" };
            file.mf_app_tasks(vect);
            //TODO
        }
        WHEN("all files are wiped")
        {
            //TODO
        }
    }
}

//TEST(meta_File_IO)
//{
//    File file;
//    Task_Manager tskmgr;
//    Category_Manager ctgmgr;
//
//    file.mf_create();
//    tskmgr.add({"Task 1","Task 2","Task 3"});
//    std::cout << "count=" << file.mf_app_tasks() << std::endl;
//    //test appending meta data with double vector input
//    std::vector<std::vector<std::string> > dvect =
//        { {"Task 1", "Category 1"}, {"Task 2"}, {"Task 3","Category 3", "Category 4"} };
//    file.mf_app_tasks(dvect);
//
//    //test appending meta data with single vector input
//    std::vector<std::string> vect =
//        { "Task 1","Task 2","Task 3" };
//
//
//}
