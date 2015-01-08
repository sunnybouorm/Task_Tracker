/* Date Created : 20/12/2014
 * Author       : Sultan Bou Orm
 * Description  :
 * Base class used for the creation of task and category objects
 */

#ifndef NODE_H
#define NODE_H

#include<iostream>
#include<vector>

/*
 * NOTES:
 * > Be wary of creating an instance "Node node(void)" as the compiler often
 * compiles it fine with no errors on that line which makes it hard to detect
 * most likely confusing it for a function call.
 * > A node is considered empty if it has no name
 */
class Node {
friend class Task;
friend class Category;
friend class Link_Manager;
protected:
    std::string name;
    std::vector<uint16_t> LIDs;
    Node() { };
    Node(const std::string &s);

    void set_name(const std::string &s) { name = s;};
    bool add_LID(const uint16_t &IDval);
    void delete_LID(const uint16_t &IDval);
    void delete_LIDs(const std::vector<uint16_t> &IDvals);
    void delete_LIDs(void);
public :
    std::vector<uint16_t> get_LIDs(void){ return LIDs;};
    bool LID_Exists(uint16_t IDval);//checks if an LID exists in LIDs
    std::string get_name(void){return name;}
    bool is_Empty(void){return name.empty();};
        //checks whether node has a name
};

#endif //NODE_H
