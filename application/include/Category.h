/* Last updated : 20/12/2014
 * Date Created : 19/12/2014
 * Author       : Sultan Bou Orm
 * Description  :
 */

#ifndef CATEGORY_H
#define CATEGORY_H

#include<iostream>
#include <vector>

#include "Node.h"

class Category : public Node {
friend class Category_Manager;
template<class Category> friend class Node_Manager;
private :
    Category(const std::string &s) : Node(s) { };
public :
    Category() : Node() { };
    void print(void);
};

#endif
