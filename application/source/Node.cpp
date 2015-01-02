/* Date Created : 20/12/2014
 * Author       : Sultan Bou Orm
 */
#include "Node.h"

using namespace std;

//constructors
Node::Node(const string &s) : name(s) { };

//member functions

/*
 * Adds a unique LID to vector and returns <0=pass>,<1=fail>
 */
bool Node::add_LID(const uint16_t &IDval){
    //check if LID exists
    if(LIDs.empty()){
       LIDs.push_back(IDval);
    }else{
        for(auto LID : LIDs){
            if(IDval==LID){
                return 1; //LID already exists
            } else {
                LIDs.push_back(IDval);
                return 0;
            }
        };
    };
    return 0;
};

/*
 * NOTES:
 * > Only deletes a single occurance of IDval, hence you must ensure that all
 * LID values are unique to avoid heartache.
 */
void Node::delete_LID(const uint16_t &IDval){
    for(auto it=LIDs.begin(); it != LIDs.end(); ++it){
        if(IDval == *it){
            LIDs.erase(it);
            break;
        };
    };
};

void Node::delete_LIDs(const std::vector<uint16_t> &IDvals){
    for(auto IDval : IDvals){
        delete_LID(IDval);
    };
};

void Node::delete_LIDs(){
    LIDs.clear();
};

bool Node::LID_Exists(uint16_t IDval){
    for(auto LID : LIDs){
        if(IDval == LID){
            return true;//IDval exists in node
        };
    };
    return false;//IDval does not exist in node
};
