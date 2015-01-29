#include "catch.hpp"
#include <vector>

#include "Category_Manager.h"
#include <iostream>

SCENARIO( "Categories can be created and deleted", "[category]" )
{
    GIVEN( "A category manager with 2 categories added" )
    {
        Category_Manager ctgmgr;
        ctgmgr.add("SCHOOL");
        REQUIRE(ctgmgr.is_Exist("SCHOOL") == true);
        ctgmgr.add("HOBBY");
        REQUIRE(ctgmgr.is_Exist("HOBBY") == true);

        GIVEN("An empty category")
        {
            Category emptyCategory;
            WHEN("A category pointer is assigned to an empty category")
            {
                Category* school = &emptyCategory;
                REQUIRE(school->is_Empty() == true);
                AND_WHEN("A category is assigned to the category pointer")
                {
                    school = ctgmgr.fetch("SCHOOL");
                    REQUIRE(school->is_Empty() == false);
                }
            }
        }
        WHEN("Categories are wiped by name")
        {
            ctgmgr.wipe("SCHOOL");
            REQUIRE( ctgmgr.is_Exist("SCHOOL") == false );
            ctgmgr.wipe("HOBBY");
            REQUIRE(ctgmgr.is_Exist("HOBBY") == false );
        }
        WHEN("All categories are wiped")
        {
            ctgmgr.wipe();
            THEN("The reserved empty object must exist")
            {
                REQUIRE(ctgmgr.is_Exist("") == true);
            }
        }
        WHEN("A category that doesn't exist is wiped")
        {
            ctgmgr.wipe("NONEXISTANT");
            REQUIRE( ctgmgr.is_Exist("NONEXISTANT") == false );
        }
    }
}

SCENARIO("Multiple categories can be created and deleted","[category]")
{
    GIVEN("A category manager with a list of categories added")
    {
        Category_Manager ctgmgr;
        std::vector<std::string> names = {"MATH","ENGG","MECH","CSSE","INFS"};

        ctgmgr.add(names);
        REQUIRE(ctgmgr.is_Exist(names) );

        WHEN("All categories are wiped")
            {
                REQUIRE(ctgmgr.is_Exist(names) == true);
                ctgmgr.wipe();
                REQUIRE(ctgmgr.is_Exist(names) == false );
                AND_WHEN("Wiped categories are fetched as empty category objects")
                {
                    for(Category *ctg : ctgmgr.fetch(names) ){
                        REQUIRE(ctg->is_Empty() == true);
                    };
                    REQUIRE(ctgmgr.is_Exist(names) == false );
                }
                AND_WHEN("Categories with duplicate names are added")
                {
                    names = {"MATH","MATH","MECH","MATH","MATH"};
                    ctgmgr.add(names);
                    REQUIRE( ctgmgr.get_names().size() == 3 );
                }
                AND_WHEN("Adding categories")
                {
                    Category *ptr = ctgmgr.fetch("");
                    REQUIRE(ptr->is_Empty());
                    names = {"MATH","ENGG","MECH","CSSE","INFS"};
                    ctgmgr.add(names);
                    THEN("the location of the reserved category object is fixed")
                    {
                        REQUIRE( ptr->is_Empty() == true );
                        ctgmgr.wipe();
                        REQUIRE( ptr->is_Empty() == true );
                    }
                }
                THEN("The reserved object is retained")
                {
                    REQUIRE( ctgmgr.get_names().size() == 1 );
                    REQUIRE( ctgmgr.is_Exist(""));
                }
            }
        WHEN("All categories are wiped by name")
        {
            ctgmgr.wipe(names);
            REQUIRE(ctgmgr.is_Exist(names) == false);
        }
        WHEN("Specific names are wiped")
        {
            names = {"MATH","ENGG","MECH"};
            ctgmgr.wipe(names);
            REQUIRE(ctgmgr.is_Exist(names) == false);
        }
        WHEN("Specific categories are fetched by their name")
        {
            names = {"MATH","ENGG","MECH"};
            std::vector<Category*> categories = ctgmgr.fetch(names);
            REQUIRE(names == ctgmgr.get_names(categories));
        }
    }
}

SCENARIO("Categories can be renamed","[task]")
{
    GIVEN("A category manager with a list of categories added")
    {
        Category_Manager ctgmgr;
        std::vector<std::string> names = {"METH","ENG","MECH","CSSE","INS"};

        ctgmgr.add(names);
        WHEN("Category METH is Changed to MATH")
        {
            ctgmgr.rename("METH","MATH");
            bool arg1 = ctgmgr.is_Exist("METH")==false;
            bool arg2 = ctgmgr.is_Exist("MATH")==true;
            REQUIRE( (arg1&&arg2)==true );
        }

        WHEN("Category ENG is Changed to ENGG")
        {
            ctgmgr.rename("ENG","ENGG");
            bool arg1 = ctgmgr.is_Exist("ENG")==false;
            bool arg2 = ctgmgr.is_Exist("ENGG")==true;
            REQUIRE( (arg1&&arg2)==true );
        }

        WHEN("Category INS is Changed to INFS")
        {
            ctgmgr.rename("INS","INFS");
            bool arg1 = ctgmgr.is_Exist("INS")==false;
            bool arg2 = ctgmgr.is_Exist("INFS")==true;
            REQUIRE( (arg1&&arg2)==true );
        }
    }
}
