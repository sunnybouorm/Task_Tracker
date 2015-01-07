/* Date Created : 19/12/2014
 * Author       : Sultan Bou Orm
 */
using namespace std;
#include "Task_Manager.h"

//grabs the names of all categories linked to taskName
vector<string> Task_Manager::probe(string taskName){
    vector<string> categories;
    Task *_tsk = fetch(taskName);
    vector<uint16_t> LIDs = _tsk->get_LIDs();
    Link *_link;
    //grab category names and append them to vector
    string category;
    if (LIDs.empty() == false) {
        for(auto LID : LIDs){
            _link = lnkmgr_->get_link(LID);
            if( _link->get_LID() != 0) {
                category = ( (_link->get_pair() ).second->get_name() );
                categories.push_back(category);
            }
        }
    }
    return categories;
};

void Task_Manager::print(){
    cout << "Printing task names from map..." << endl;
    if(Nodes.empty()){
        cout << "<empty>" << endl;
    } else {
        for(auto it = Nodes.begin(); it != Nodes.end();++it){
            cout << "<" << it->first << ">" << endl;
        }
    }
    cout << endl;
}
