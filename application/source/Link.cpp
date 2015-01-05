/* Last updated : 20/12/2014
 * Date Created : 19/12/2014
 * Author       : Sultan Bou Orm
 * Description  :
 */

#include<iostream>
#include "stdint.h"

#include "Link.h"


using namespace std;

//constructors
/*
 * NOTES:
 * > LID of zero is reserved and cannot be assigned to any Links
 * > Constructor only warns about LID and hence is not secure
 */
Link::Link(Task *tp, Category *cp, const uint16_t &IDval) {
    if (IDval == 0){
        cerr << "WARNING!: <LID=0> is reserved!" << endl;
    } else{
        LID = IDval;
        nodes.first  = tp;
        nodes.second = cp;
        nodeTypes.first  = "Task*";
        nodeTypes.second = "Category*";
    }
};

//member functions
/*
 * NOTES:
 * > make sure objects in nodes have a get_name() function
 * > don't forget to add nodeTypes when creating a new Link Constructor
 */
void Link::print(void){
    cout << "printing link object data..." << endl;
    cout << "LID = <" << LID << ">" << endl;
    cout << "<type1,type2> : <" << nodeTypes.first << "," << nodeTypes.second
         << ">" << endl;
    cout << "<name1,name2> : " << "<" << nodes.first->get_name() << ","
         << nodes.second->get_name() << ">" << endl;
    cout << endl;
};
