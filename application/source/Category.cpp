/* Last updated : 20/12/2014
 * Date Created : 17/12/2014
 * Author       : Sultan Bou Orm
 */
#include "Category.h"

using namespace std;

//member functions

void Category::print(){
    cout << "Printing category data..." << endl;
    cout << "Category name: <" << name << ">" << endl;
    cout << "Category LIDs(size=" << LIDs.size() << "):";
    if(LIDs.empty()){
            cout << " <empty>"<<endl;
    }else{cout << " <";};
    for(auto LID : LIDs){
        cout << LID;
        if(LID == LIDs.back()){
            cout << ">";
        } else {
            cout << ",";
        }
    };
    cout << endl << endl;;
};
