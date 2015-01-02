/* Date Created : 19/12/2014
 * Author       : Sultan Bou Orm
 */
using namespace std;
#include "Category_Manager.h"

void Category_Manager::print(){
    cout << "printing Category names from map..." << endl;
    if(Nodes.empty()){
        cout << "<empty>" << endl;
    } else {
        for(auto it = Nodes.begin(); it != Nodes.end();++it){
            cout << "<" << it->first << ">" << endl;
        }
    }
    cout << endl;
};
