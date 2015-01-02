/* Last updated : 20/12/2014
 * Date Created : 19/12/2014
 * Author       : Sultan Bou Orm
 * Description  :
 */
#ifndef LINK_MANAGER_H
#define LINK_MANAGER_H

#include <map>

#include "Link.h"

class Link_Manager{
private :
    std::map <const uint16_t, Link> Links;
    uint16_t generate_LID(void);//generates a unique link ID
public :

    //accessors
    bool is_Linked(Task &tr, Category &cr);//checks if a link already exists
    bool is_Linked(Task *tp, Category *cp);
    bool is_Linked(std::vector<Task*> tps, std::vector<Category*> cps);
    void print(void);

    //modifiers
    bool link(Task *tp, Category *cp);//creates a link between two objects
    bool link(std::vector<Task*> tps, std::vector<Category*> cps);

    bool unlink(Task *tp, Category *cp);
    bool unlink(std::vector<Task*> tps, std::vector<Category*> cps);
    template<typename T>
    void unlink(T* node);//unlinks all LIDs from node

    void destroy(uint16_t LID);//destroys a single link by LID
    void destroy(std::vector<uint16_t> LIDs);//destorys multiple links by LID
};

/*
 * unlinks all LIDs and links associated with specified node(task/category)
 * WARNING!!!: ensure that a valid type is passed, in this case Category or Task
 * objects.
 */
template<typename T> void Link_Manager::unlink(T* node){
    std::vector<uint16_t> LIDs = node->get_LIDs();
    destroy(LIDs);
};

#endif // LINK_MANAGER_H
