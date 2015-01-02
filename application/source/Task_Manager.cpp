/* Date Created : 19/12/2014
 * Author       : Sultan Bou Orm
 */
using namespace std;
#include "Task_Manager.h"

void Task_Manager::print(){
    cout << "printing Task names from map..." << endl;
    if(Nodes.empty()){
        cout << "<empty>" << endl;
    } else {
        for(auto it = Nodes.begin(); it != Nodes.end();++it){
            cout << "<" << it->first << ">" << endl;
        }
    }
    cout << endl;
}
