/* Date Created : 19/12/2014
 * Author       : Sultan Bou Orm
 * Description  :
 */

using namespace std;
#include <iostream>

#include "Link_Manager.h"
//member functions
/*
 * Generates a unique link ID, 0 is reserved to signify that no
 * unique ID was found
 */
uint16_t Link_Manager::generate_LID(void){
    //iterate through LIDs starting from 1 until a unique LID is found
    uint16_t LID = 1;
    const uint16_t uint32_max = -1;
    if(Links.empty()){
        LID = 1;
        return LID;
    } else {
        while( (Links.count(LID) != 0) && (LID != uint32_max) ){
            ++LID;
        }
        if(LID != uint32_max){
            return LID;
        }
    }
    return LID = 0;//no unique IDs found
};

/*
 * Checks if a link between two objects already exists
 * returns true if a link exists, false otherwise
 */
bool Link_Manager::is_Linked(Task &tr, Category &cr){
    const vector<uint16_t> trLIDs = tr.get_LIDs();
    const vector<uint16_t> crLIDs = cr.get_LIDs();

    for(const auto& trkey : trLIDs){
        for(auto crkey : crLIDs){
            if (trkey == crkey){
                return true;
            };
        };
    };
    return false;
};

bool Link_Manager::is_Linked(Task *tp, Category *cp){
    return is_Linked(*tp,*cp);
};

/*
 * Checks if a link between all task objects and category objects specified
 * exists returns true if all objects are linked, false otherwise
 */
bool Link_Manager::is_Linked(vector<Task*> tps, vector<Category*> cps){
    for(auto tp : tps){
        for(auto cp : cps){
            //if false returned then an unlinked object was detected
            if( is_Linked(tp,cp) == false ){return false;};
        };
    };
    return true;//all specified objects are linked
};

/*
 * Creates a link between a task and a category object.
 * returns bool <0=pass>, <1=fail>
 */
bool Link_Manager::link(Task *tp, Category *cp){
    //check if duplicate link already exists
    uint16_t LID = 0;
    if(is_Linked(*tp,*cp)==false){
        LID = generate_LID();
    };

    //begin LID assignment
    if(LID!=0){
        Link lnk(tp, cp, LID);
        bool status = tp->add_LID(LID);
        if(status == 1){return 1;};//duplicate LID detected in task
        status = cp->add_LID(LID);
        if(status == 1){return 1;};//duplicate LID detected in category
        Links.insert(pair<uint16_t,Link>(LID,lnk));
        return 0;
    };

    return 1;//duplicate link detected, return failure
};

/*
 * Creates a link between specified task and category objects.
 * returns bool <0=pass>, <1=fail>
 */
bool Link_Manager::link(const std::vector<Task*> tps,
    const std::vector<Category*> cps)
{
    bool status = 0;
    for(auto tp : tps){
      for(auto cp : cps){
        if (link(tp,cp) == 1){status = 1;};
      };
    };
    return status;
};

/*
 * Destroys a single link by its LID and removes LID from associated Nodes
 */
void Link_Manager::destroy(const uint16_t LID){
    //remove LID from associated nodes
    const auto it = Links.find(LID);
    if(it != Links.end()){
        const Link &link = it->second;
        Task &task = *(link.nodes.first);
        task.delete_LID(LID);
        Category &category = *(link.nodes.second);
        category.delete_LID(LID);
    };
    //remove LID from link manager
    Links.erase(LID);
};

/*
 * Destroys links with matching LIDs and removes LIDs from associated Nodes
 */
void Link_Manager::destroy(const std::vector<uint16_t> LIDs){
    for(auto& LID : LIDs){
        destroy(LID);
    }
};

void Link_Manager::print(void){
    cout << "printing Link IDs from map..." << endl;
    if(Links.empty()){
        cout << "<empty>" << endl;
    } else {
        for(auto it = Links.begin(); it != Links.end();++it){
            cout << "<" << it->first << ">" << endl;
        }
    }
    cout << endl;
};

/*
 * Removes a SINGLE identical LID and destroys asscoiated links between a
 * specified task and category object.
 * returns <0=pass> <1=fail>
 * NOTES:
 * > WARNING!!!: Ensure LIDs are unique within each object since this function
 * only removes a single occurence of a matching LID between two seperate
 * objects and does not take into account duplicate LIDs in a single object.
 */
bool Link_Manager::unlink(Task *tp, Category *cp){
    vector<uint16_t> tskLIDs = tp->get_LIDs();
    vector<uint16_t> ctgLIDs = cp->get_LIDs();

    for(auto tskLID : tskLIDs){
        for(auto ctgLID : ctgLIDs){
            if(tskLID == ctgLID){
                destroy(tskLID);
                return 0;//matching LID removed successfully
            };
        };
    };
    return 1;//no matching LID found
};

/*
 * Removes a SINGLE identical LID between each task and category specified
 * and destroys asscoiated links between the specified task and category objects
 * returns <0=pass> <1=fail>, fails when a single pair of (Task,Catgory) objects
 * have no identical Link ID.
 * NOTES:
 * > WARNING!!!: Ensure LIDs are unique within each object since this function
 * only removes a single occurence of a matching LID between two seperate
 * objects and does not take into account duplicate LIDs in a single object.
 */
bool Link_Manager::unlink(vector<Task*> tps, vector<Category*> cps){
    bool status = 0;
    for(auto tp : tps){
        for(auto cp : cps){
            if (unlink(tp,cp) == 1) {status = 1;};
        };
    };
    return status;
};
