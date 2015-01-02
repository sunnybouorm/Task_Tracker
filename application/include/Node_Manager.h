/*
 * Date Created : 24/12/2014
 * Author       : Sultan Bou Orm
 * Description  :
 * Base class for Task_Manager and Category_manager
 */

#ifndef NODE_MANAGER_H
#define NODE_MANAGER_H

#include <map>
#include <vector>
#include <iostream>

#include "Link_Manager.h"

template <class T>
class Node_Manager {
protected :
    std::map <std::string,T> Nodes;
    Link_Manager *lnkmgr_ = NULL;//CAUTION!!!! playing with fire here
    Link_Manager empty_lnkmgr;

    Node_Manager(void);
    Node_Manager(Link_Manager& lnkmgr);

public :

    // public accessors
    //------------------------------------
    bool is_Exist(const std::string &name);
    bool is_Exist(const std::vector<std::string> &names);

    std::vector<std::string> get_names(
        const std::vector<T*> &nodes);
    std::vector<std::string> get_names(void);

    // public modifiers
    void wipe(const std::string &name);
    void wipe(const std::vector<std::string> &names);
    void wipe(void);

    void add(const std::string &name);
    void add(const std::vector<std::string> &names);

    T* fetch(const std::string &name);
    const std::vector<T*> fetch(
        const std::vector<std::string> &names);
    void attach_Link_Manager(Link_Manager& lnkmgr);

};

#include "Node_Manager.hxx"

#endif // NODE_MANAGER_H
