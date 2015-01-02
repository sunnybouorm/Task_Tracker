/* Last updated : 20/12/2014
 * Date Created : 17/12/2014
 * Author       : Sultan Bou Orm
 */
#include "Task.h"

using namespace std;

//member functions

void Task::print(){
    cout << "printing task data..." << endl;
    cout << "Task Name: <" << name << ">" << endl;
    cout << "Task LIDs(size=" << LIDs.size() << "):";
    if(LIDs.empty()){
            cout << " <empty>"<< endl;
    }else{cout << " <";};
    for(auto LID : LIDs){
        cout << LID;
        if(LID == LIDs.back()){
            cout << ">";
        } else {
            cout << ",";
        }
    };
    cout << endl << endl;
};
