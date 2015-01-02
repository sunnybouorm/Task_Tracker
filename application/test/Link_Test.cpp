#include "catch.hpp"
#include <vector>

#include "Task_Manager.h"
#include "Category_Manager.h"
#include "Link_Manager.h"

// Utility functions
/*
 * Checks whether LIDs within a node(Category/Task) are unique
 */
template <class T>
bool is_Unique(T* node){
    std::vector<uint16_t> LIDs = node->get_LIDs();
    int cnt = 0;
    for(auto i : LIDs){
        for(auto j : LIDs){
            if(i==j){++cnt;}
            if(cnt>1){return false;};
        }
        cnt = 0;
    };
    return true;
}

/*
 * Checks whether an LID in a node(Category/Task) is unique
 */
template <class T>
bool is_Exist(T* node, uint16_t LID){
    std::vector<uint16_t> LIDs = node->get_LIDs();
    for(auto e : LIDs){
        if(LID==e){return true;};
    };
    return false;
}

/*
 * Checks whether LIDs generated for every node(Task/Category)
 * object are unique
 */
template<class M, class T>
bool is_Unique(M& mgr){
    std::vector<std::string> names = mgr.get_names();
    std::vector<T*> nodes = mgr.fetch(names);
    std::vector<uint16_t> LIDs;

    while(nodes.empty() == false){
        T* node_ = nodes.back();
        //check for any duplicate LIDs inside the node
        if (is_Unique<T>(node_) == false){return false;};

        //check for duplicate LIDs with other tasks
        LIDs = node_->get_LIDs();
        for(auto LID : LIDs){
            for(auto e : nodes){
                if(e == nodes.back()){break;};
                if(is_Exist<T>(e,LID)==true){return false;};
            };
        };
        nodes.pop_back();
    };
    return true;
};

SCENARIO("links are created one by one and destroyed by link ID","[link]")
{
    GIVEN("A set of initialized Link, Task, and Category managers")
    {
        Link_Manager lnkmgr;
        Task_Manager tskmgr;
        Category_Manager ctgmgr;
        tskmgr.attach_Link_Manager(lnkmgr);
        ctgmgr.attach_Link_Manager(lnkmgr);
        Task *_tsk;
        Category *_ctg;

        GIVEN("A task and category are added")
        {
            tskmgr.add("T1");
            ctgmgr.add("C1");
            _tsk = (tskmgr.fetch("T1"));
            _ctg = (ctgmgr.fetch("C1"));
            REQUIRE(lnkmgr.is_Linked(*_tsk, *_ctg) == false);

            WHEN("the task and category are linked")
            {
                REQUIRE(lnkmgr.link(_tsk,_ctg)== 0);//check no duplicate link detected
                REQUIRE(lnkmgr.link(_tsk,_ctg)== 1);//check duplicate link detected
                REQUIRE(lnkmgr.is_Linked(*_tsk,*_ctg) == true);
                AND_WHEN("the link is destroyed by link ID")
                {
                    _tsk = (tskmgr.fetch("T1"));
                    _ctg = (ctgmgr.fetch("C1"));
                    lnkmgr.destroy(1);
                    REQUIRE(lnkmgr.is_Linked(*_tsk,*_ctg) == false);
                    AND_WHEN("T1 is relinked to C1")
                    {
                        REQUIRE(lnkmgr.link(_tsk,_ctg)== 0);
                        REQUIRE(lnkmgr.is_Linked(*_tsk,*_ctg) == true);
                        THEN("The lowest unused LID is reassigned")
                        {
                            REQUIRE(_tsk->LID_Exists(1) == true);
                            REQUIRE(_ctg->LID_Exists(1) == true);
                        }
                    }
                }
            }

        }
        WHEN("multiple links are added by the user")
        {
            tskmgr.add( {"T1","T2","T3","T4"} );
            ctgmgr.add( {"C1","C2","C3","C4"} );
            AND_WHEN("T1 is linked to all categories and C2 to all tasks")
            {
                _tsk = (tskmgr.fetch("T1"));
                _ctg = (ctgmgr.fetch("C1"));
                REQUIRE(lnkmgr.link(_tsk,_ctg)== 0);
                _ctg = (ctgmgr.fetch("C2"));
                REQUIRE(lnkmgr.link(_tsk,_ctg)== 0);
                _ctg = (ctgmgr.fetch("C3"));
                REQUIRE(lnkmgr.link(_tsk,_ctg)== 0);
                _ctg = (ctgmgr.fetch("C4"));
                REQUIRE(lnkmgr.link(_tsk,_ctg)== 0);

                _ctg = (ctgmgr.fetch("C2"));
                _tsk = (tskmgr.fetch("T1"));
                REQUIRE(lnkmgr.link(_tsk,_ctg)== 1);
                _tsk = (tskmgr.fetch("T2"));
                REQUIRE(lnkmgr.link(_tsk,_ctg)== 0);
                _tsk = (tskmgr.fetch("T3"));
                REQUIRE(lnkmgr.link(_tsk,_ctg)== 0);
                _tsk = (tskmgr.fetch("T4"));
                REQUIRE(lnkmgr.link(_tsk,_ctg)== 0);
                THEN("Link IDs must be unique")
                {
                    bool isUnique = is_Unique<Task_Manager,Task>(tskmgr);
                    REQUIRE(isUnique==true);
                    isUnique = is_Unique<Category_Manager,Category>(ctgmgr);
                    REQUIRE(isUnique==true);
                }
                AND_WHEN("the node T1 is wiped")
                {
                    tskmgr.wipe("T1");
                    THEN("all associated links are destroyed")
                    {
                        _ctg = (ctgmgr.fetch("C1"));
                        REQUIRE(_ctg->LID_Exists(1) == false);
                        _ctg = (ctgmgr.fetch("C2"));
                        REQUIRE(_ctg->LID_Exists(2) == false);
                        _ctg = (ctgmgr.fetch("C3"));
                        REQUIRE(_ctg->LID_Exists(3) == false);
                        _ctg = (ctgmgr.fetch("C4"));
                        REQUIRE(_ctg->LID_Exists(4) == false);

                        AND_WHEN("T1 is reassigned")
                        {
                            tskmgr.add("T1");
                            THEN("it is not linked to any categories")
                            {
                                _tsk = (tskmgr.fetch("T1"));
                                _ctg = (ctgmgr.fetch("C1"));
                                REQUIRE(lnkmgr.is_Linked(*_tsk, *_ctg) == false);
                                _ctg = (ctgmgr.fetch("C2"));
                                REQUIRE(lnkmgr.is_Linked(*_tsk, *_ctg) == false);
                                _ctg = (ctgmgr.fetch("C3"));
                                REQUIRE(lnkmgr.is_Linked(*_tsk, *_ctg) == false);
                                _ctg = (ctgmgr.fetch("C4"));
                                REQUIRE(lnkmgr.is_Linked(*_tsk, *_ctg) == false);
                            }
                        }
                    }
                }
            }
        }
    }
}

SCENARIO("multiple links are created and destroyed by reference to their object(s)",
         "[link]")
{
    GIVEN("A set of initialized Link, Task, and Category managers")
    {
        Link_Manager lnkmgr;
        Task_Manager tskmgr(lnkmgr);
        Category_Manager ctgmgr(lnkmgr);

        std::vector<Task*> _tsks;
        std::vector<Category*> _ctgs;
        Task *_tsk;
        Category *_ctg;
        std::vector<std::string> names;
        tskmgr.add({"T1","T2","T3","T4"});
        ctgmgr.add({"C1","C2","C3","C4"});

        WHEN("Task T1 is linked to all categories")
        {
            names = {"T1"};
            _tsks = tskmgr.fetch(names);
            _ctgs = ctgmgr.fetch({"C1","C2","C3","C4"});
            REQUIRE(lnkmgr.link(_tsks,_ctgs)== 0);
            REQUIRE(lnkmgr.is_Linked(_tsks,_ctgs) == true);
            THEN("all links generated have unique LIDs")
            {
                bool isUnique = is_Unique<Task_Manager,Task>(tskmgr);
                REQUIRE(isUnique == true);
                isUnique = is_Unique<Category_Manager,Category>(ctgmgr);
                REQUIRE(isUnique == true);
            }
            AND_WHEN("C4 is unlinked from T1")
            {
                _tsk = tskmgr.fetch("T1");
                _ctg = ctgmgr.fetch("C4");
                REQUIRE(lnkmgr.unlink(_tsk,_ctg) == 0 );
                REQUIRE(lnkmgr.is_Linked(_tsks,_ctgs) == false);
            }
            AND_WHEN("T1 is unlinked from C1 and C2")
            {
                names = {"T1"};
                _tsks = tskmgr.fetch(names);
                names = {"C1","C2"};
                _ctgs = ctgmgr.fetch(names);
                REQUIRE(lnkmgr.is_Linked(_tsks,_ctgs) == true);
                REQUIRE(lnkmgr.unlink(_tsks,_ctgs) == 0 );
                REQUIRE(lnkmgr.is_Linked(_tsks,_ctgs) == false);
                THEN("C3 is still linked to T1")
                {
                    _tsk = tskmgr.fetch("T1");
                    _ctg = ctgmgr.fetch("C3");
                    REQUIRE(lnkmgr.is_Linked(_tsk,_ctg) == true);
                }
            }
        }
        WHEN("T2 is linked to all categories")
        {
            names = {"T2"};
            _tsks = tskmgr.fetch(names);
            names = {"C1","C2","C3","C4"};
            _ctgs = ctgmgr.fetch(names);
            CHECK (lnkmgr.is_Linked(_tsks,_ctgs) == false);
            CHECK(lnkmgr.link(_tsks,_ctgs)== 0);
            CHECK (lnkmgr.is_Linked(_tsks,_ctgs) == true);
            AND_WHEN("T2 is unlinked from all categories")
            {
                names = {"T2"};
                _tsks = tskmgr.fetch(names);
                names = {"C1","C2","C3","C4"};
                _ctgs = ctgmgr.fetch(names);
                _tsk = tskmgr.fetch("T2");
                lnkmgr.unlink<Task>(_tsk);
                CHECK(lnkmgr.is_Linked(_tsks,_ctgs) == false);
            }
        }

    }
}
