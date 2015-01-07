/* Date Created : 19/12/2014
 * Author       : Sultan Bou Orm
 * Description  :
 */
#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H

#include <vector>
#include <iostream>
#include <map>

#include "Node_Manager.h"
class Task_Manager : public Node_Manager<Task> {
public:
    /*
     * NOTES:
     * > The first element of the map "Tasks" is reserved as an empty object so that
     * pointers passed through functions can be initialized if nothing of interest
     * was found.
     * > WARNING!!!: make sure you DO NOT modify the reserved object, if reserved
     * object is deleted then create another one in its place. The reserved object
     * must have an empty string as its key, its value must be an empty Task object.
     */
    Task_Manager() : Node_Manager<Task>() { };
    Task_Manager(Link_Manager &lnkmgr) : Node_Manager<Task>(lnkmgr) { };

    //accessors
    //------------------------------------
    std::vector<std::string> probe(std::string taskName);
        //grabs the names of all categories linked to taskName
    void print(void);
};

#endif//TASK_MANAGER_H
