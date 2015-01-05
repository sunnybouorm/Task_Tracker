/*
 * Date Created : 27/12/2014
 * Author       : Sultan Bou Orm
 * Description  :
 * Template member function definitions for Node_Manager.h
 */

#ifndef NODE_MANAGER_HXX
#define NODE_MANAGER_HXX

#include "Node_Manager.h"

template<class T> Node_Manager<T>::Node_Manager(void){
    lnkmgr_ = &empty_lnkmgr;
    T empty_object;
    const std::string name = "";
    Nodes.insert(std::pair<std::string,T>(name,empty_object));
};

template<class T> Node_Manager<T>::Node_Manager(Link_Manager& lnkmgr){
    lnkmgr_ = &lnkmgr;
    lnkmgr_ = &empty_lnkmgr;
    T empty_object;
    const std::string name = "";
    Nodes.insert(std::pair<std::string,T>(name,empty_object));
};

/*
 * Attaches a Link_Manager class to this instance of Node_Manager
 */
template<class T> void Node_Manager<T>::attach_Link_Manager(Link_Manager& lnkmgr){
    lnkmgr_ = &lnkmgr;
};

/*
 * fetches a pointer to a <T> object with matching name, if no such object
 * exists a pointer to an empty Category object is returned.
 */
template <typename T>
T* Node_Manager<T>::fetch(const std::string &name)
{
    T *ptr;
    if(Nodes.count(name) != 0){
        ptr = &(Nodes.find(name)->second);
    } else{
        ptr = &(Nodes[""]);//point to reserved empty object
    };
    return ptr;
};

/*
 * Fetches <T> objects associated with matching names, names that do not
 * exist are stored as pointers to empty objects. The solution vector stores
 * data in the same order as the names vector.
 * NOTES:
 * This method does not delete the reserved empty object, ensure that the
 * empty object is not removed or manipulated. There must always be an empty
 * object with an empty string as a key in the map "Nodes" otherwise some
 * pointers might become uninitialized and you will know pain.
 */
template <typename T>
const std::vector<T*> Node_Manager<T>::fetch(
    const std::vector<std::string> &names)
{
    std::vector<T*> solution;
    for(auto name : names){
        solution.push_back(fetch(name));
    }
    return solution;
};

/*
 * Gets the names of the objects of type <T> refered to in the vector nodes.
 * Stores names in a manner that retains the original order of the argumnet
 * "nodes". Be wary of passing duplicates as this method is not
 * secure and will not ensure uniqueness of the names returned.
 */
template <typename T>
std::vector<std::string> Node_Manager<T>::get_names(const std::vector<T*> &nodes)
{
    std::vector<std::string> names;
    for(auto node : nodes){
        names.push_back(node->get_name());
    }
    return names;
};

/*
 * Gets the names of all <T> objects in this instance of Node_Manager.
 * The order returned is in the same order the objects are stored in
 * "map<T> Nodes".
 * NOTES:
 * > Ensure the map Nodes has no duplicates as this method is not secure and
 * will not ensure uniqueness of the names returned.
 */
template <typename T>
std::vector<std::string> Node_Manager<T>::get_names(void)
{
    std::vector<std::string> names;
    for(auto node : Nodes){//Careful "Nodes" is map<T>
        names.push_back(node.first);
    }
    return names;
};

/*
 * wipe() removes objects from the map "Nodes" and any associated links based on
 * input parameters, wipe MUST retain a reserved object with an empty string as
 * key and an empty object as its value. Otherwise some pointers from other
 * functions might go uninitialized and bad things happen.
 */
template <typename T>
void Node_Manager<T>::wipe(const std::string &name)
{
    if(name.empty() == false){
        const auto it = Nodes.find(name);
        if(it != Nodes.end()){//does not proceed if name not found
            T &node = it->second;
            std::vector<uint16_t> LIDs = node.get_LIDs();
            //get link manger to delete all Links associated with Node
            //and matching LIDs contained in linked nodes
            Link_Manager& lnkmgr = *lnkmgr_;
            lnkmgr.destroy(LIDs);
            node.delete_LIDs();
            Nodes.erase(name);
        }
    };
};

template <typename T>
void Node_Manager<T>::wipe(const std::vector<std::string> &names)
{
    for(auto& name : names){
        wipe(name);
    };
};

template <typename T>
void Node_Manager<T>::wipe(void)
{
    std::vector<std::string> names;
    std::string name;
    for(auto it = Nodes.begin(); it!=Nodes.end(); ++it){
        name = it->first;
        names.push_back(name);
    }
    wipe(names);
};

/*
 * Adds a single category to the map Nodes, granted that name is
 * not an empty string as that key is reserved for uninitialized pointers that
 * don't have any objects on the map to point to.
 * WARNING!!!: Ensure that the reserved object is NOT modified or deleted. The
 * reserved object has an empty string as its key and an empty <T> object
 * as its value.
 */
template <typename T>
void Node_Manager<T>::add(const std::string &name)
{
    //check whether node with that name exists
    if ( (Nodes.count(name) == 0) && (name.empty() == false) ){
        T node(name);
        Nodes.insert(std::pair<std::string,T>(name,node));
    }
};

template <typename T>
void Node_Manager<T>::add(const std::vector<std::string> &names)
{
    for(auto e : names){
        add(e);
    }
};

/*
 * NOTES:
 * > It is up to you to ensure that names are unique, in this case
 * it doesn't matter since any count value > 0 returns true. But keep in mind
 * that duplicates can pass through this function undetected.
 * > An empty string passed as name will point to a reserved <T> object
 */
template <typename T>
bool Node_Manager<T>::is_Exist(const std::string &name)
{
    return Nodes.count(name);
};

template <typename T>
bool Node_Manager<T>::is_Exist(const std::vector<std::string> &names)
{
    for(auto name : names){
        if(is_Exist(name) == false){
            return false;
        };
    }
    return true;
};

#endif // NODE_MANAGER_HXX
