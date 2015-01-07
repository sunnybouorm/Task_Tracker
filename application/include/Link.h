/* Date Created : 19/12/2014
 * Author       : Sultan Bou Orm
 * Description  :
 * Links connect to two nodes, pointing to two regions in memory with a unique
 * LID used to identify the link.
 */
#ifndef LINK_H
#define LINK_H

#include<vector>
#include "stdint.h"

#include "Task.h"
#include "Category.h"

class Link{
friend class Link_Manager;
private :
    uint16_t LID;//link ID
    std::pair<Task*, Category*> nodes;
    std::pair<std::string, std::string> nodeTypes;
    Link(Task *tp, Category *cp, const uint16_t &IDval);
    void set_LID(uint16_t &val){LID=val;};
    void print(void);
public:
    Link(){LID=0;};
    uint16_t get_LID(void){return LID;};
    std::pair<Task*, Category*> get_pair() {return nodes;};
};

#endif // LINK_H
