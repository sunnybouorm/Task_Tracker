/* Date Created : 17/12/2014
 * Author       : Sultan Bou Orm
 * Description  :
 * Handles the creation and modification of a single task object
 */
#ifndef TASK_H
#define TASK_H

#include<iostream>
#include <vector>

#include "Node.h"

/*
 * NOTES:
 * > Be wary of creating an instance using "Task task()" as the compiler
* compiles it fine with no errors on that line which makes it hard to detect.
 */
class Task : public Node {
friend class Task_Manager;
template<class Task> friend class Node_Manager;
private :
    Task(const std::string &s) : Node(s) { };
public :
    Task() : Node() { };
    void print(void);
};

#endif // TASK_H
