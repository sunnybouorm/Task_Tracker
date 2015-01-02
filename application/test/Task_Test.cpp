#include "catch.hpp"
#include <vector>

#include "Task_Manager.h"
#include <iostream>

SCENARIO( "Tasks can be created and deleted", "[task]" )
{

    GIVEN( "A task manager with 2 tasks added" )
    {
        Task_Manager tskmgr;
        tskmgr.add("MATH");
        REQUIRE(tskmgr.is_Exist("MATH") == true );
        tskmgr.add("SCIENCE");
        REQUIRE(tskmgr.is_Exist("SCIENCE") == true );

        GIVEN("An empty task")
        {
            Task emptyTask;
            WHEN("A task pointer is assigned to an empty task")
            {
                Task* math = &emptyTask;
                REQUIRE(math->is_Empty() == true);
                AND_WHEN("A task is assigned to the task pointer")
                {
                    math = tskmgr.fetch("MATH");
                    REQUIRE(math->is_Empty() == false);
                }
            }
        }
        WHEN("Tasks are wiped by name")
        {
            tskmgr.wipe("MATH");
            REQUIRE( tskmgr.is_Exist("MATH") == false );
            tskmgr.wipe("SCIENCE");
            REQUIRE(tskmgr.is_Exist("SCIENCE") == false );
        }
        WHEN("All tasks are wiped")
        {
            tskmgr.wipe();
            THEN("The reserved empty object must exist")
            {
                REQUIRE(tskmgr.is_Exist("") == true);
            }
        }
        WHEN("A task that doesn't exist is wiped")
        {
            tskmgr.wipe("NONEXISTANT");
            REQUIRE( tskmgr.is_Exist("NONEXISTANT") == false );
        }
    }
}

SCENARIO("Multiple tasks can be created and deleted","[task]")
{
    GIVEN("A taskmanager with a list of tasks added")
    {
        Task_Manager tskmgr;
        std::vector<std::string> names = {"MATH","ENGG","MECH","CSSE","INFS"};

        tskmgr.add(names);
        REQUIRE(tskmgr.is_Exist(names) );

        WHEN("All tasks are wiped")
            {
                REQUIRE(tskmgr.is_Exist(names) == true);
                tskmgr.wipe();
                REQUIRE(tskmgr.is_Exist(names) == false );
                AND_WHEN("Wiped tasks are fetched as empty task objects")
                {
                    for(Task *tsk : tskmgr.fetch(names) ){
                        REQUIRE(tsk->is_Empty() == true);
                    };
                    REQUIRE(tskmgr.is_Exist(names) == false );
                }
                AND_WHEN("Tasks with duplicate names are added")
                {
                    names = {"MATH","MATH","MECH","MATH","MATH"};
                    tskmgr.add(names);
                    REQUIRE( tskmgr.get_names().size() == 3 );
                }
                AND_WHEN("Adding tasks")
                {
                    Task *ptr = tskmgr.fetch("");
                    REQUIRE(ptr->is_Empty());
                    names = {"MATH","ENGG","MECH","CSSE","INFS"};
                    tskmgr.add(names);
                    THEN("the location of the reserved task object is fixed")
                    {
                        REQUIRE( ptr->is_Empty() == true );
                        tskmgr.wipe();
                        REQUIRE( ptr->is_Empty() == true );
                    }
                }
                THEN("The reserved object is retained")
                {
                    CHECK( tskmgr.get_names().size() == 1 );
                    CHECK( tskmgr.is_Exist(""));
                }
            }
        WHEN("All tasks are wiped by name")
        {
            tskmgr.wipe(names);
            REQUIRE(tskmgr.is_Exist(names) == false);
        }
        WHEN("Specific names are wiped")
        {
            names = {"MATH","ENGG","MECH"};
            tskmgr.wipe(names);
            REQUIRE(tskmgr.is_Exist(names) == false);
        }
        WHEN("Specific tasks are fetched by their name")
        {
            names = {"MATH","ENGG","MECH"};
            std::vector<Task*> tasks = tskmgr.fetch(names);
            REQUIRE(names == tskmgr.get_names(tasks));
        }
    }
}
