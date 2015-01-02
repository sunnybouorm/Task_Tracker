/*
 * Date Created : 19/12/2014
 * Author       : Sultan Bou Orm
 * Description  :
 */

#ifndef CATEGORY_MANAGER_H
#define CATEGORY_MANAGER_H

#include <map>
#include <vector>
#include <iostream>

#include "Node_Manager.h"

class Category_Manager : public Node_Manager<Category> {
public :
    /*
     * NOTES:
     * > The first element of the map "Nodes" is reserved as an empty object so
     * that pointers passed through functions can be initialized if nothing of
     * interest was found.
     * > WARNING!!!: make sure you DO NOT modify the reserved object, if reserved
     * object is deleted then create another one in its place. The reserved object
     * must have an empty string as its key, its value must be an empty Category
     * object.
     */
    Category_Manager() : Node_Manager<Category>::Node_Manager() { };
    Category_Manager(Link_Manager& lnkmgr) :
        Node_Manager<Category>::Node_Manager(lnkmgr) { };

    //accessors
    //------------------------------------
    void print(void);
};

#endif // CATEGORY_MANAGER_H
