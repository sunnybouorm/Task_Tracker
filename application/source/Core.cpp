/* Date Created : 19/12/2014
 * Author       : Sultan Bou Orm
 */

#include "Core.h"

using namespace std;
using std::chrono::system_clock;


Core::Core(){
    tskmgr.attach_Link_Manager(lnkmgr);
    ctgmgr.attach_Link_Manager(lnkmgr);
    activeTask = &emptyTask;
};

/*
 * Converts time_t to UTC using gmtime and returns a string of the specified
 * format. Default format is "DD/MM/YY HH:MM:SS" 24 hour
 */
string Core::tt2UTC(time_t &tt, string formatString/*= "%D %T"*/){
    struct tm *timeInfo;
    timeInfo = gmtime( &tt );
    uint8_t killCount = -1;//protection from getting stuck in infinite loop
    uint8_t cnt = 0;
    string buffer;
    formatString += '\a';//redundant character since some formats like %p
                         //may become an empty string
    buffer.resize(20);
    int len = strftime(&buffer[0],buffer.size(),formatString.c_str(),timeInfo);
    while( (len == 0) && (cnt!= killCount) ){
        buffer.resize(buffer.size()*2);
        len = strftime(&buffer[0],buffer.size(),formatString.c_str(),timeInfo);
        ++cnt;
    }
    if(len!=0){
        buffer.resize(len-1); //remove the trailing redundant character '\a'
    } else {
        buffer.clear();//return an empty string if formatting failed
    }
    return buffer;
}

/*
 * Records clock on time for a given task and sets it as the activeTask
 * returns <1=fail> <0=pass>
 * (returns fail if _task is empty or another active task hasn't clocked off)
 */
bool Core::clock_On(Task *_task){
    bool status = 1;
    if( (activeTask->is_Empty()==true) && (_task->is_Empty()==false) )
    {
        status = 0;
        activeTask = _task;
        system_clock::time_point sysTime = system_clock::now();
        clockOnTimeStamp = system_clock::to_time_t ( sysTime );
    }
    return status;
};

/*
 * Records clock off time for the current active task and sets the active task
 * to emptyTask once the operation is complete.
 * The clock off timestamp is appended to the active task's file
 * if the duration from start to finish is less than MIN_RECORD_TIME
 * returns <0=pass> <1=fail>
 * (returns fail when no active task or MIN_RECORD_TIME not satisfied)
 */
bool Core::clock_Off(void){
    bool status = 1;
    if( activeTask->is_Empty() == false ) {
        system_clock::time_point sysTime = system_clock::now();
        std::time_t clockOffTimeStamp;
        clockOffTimeStamp = system_clock::to_time_t ( sysTime );

        if (difftime(clockOffTimeStamp, clockOnTimeStamp) >= MIN_RECORD_TIME )
        {
            //record timestamps in task file
            status = 0;
            string ton = tt2UTC(clockOnTimeStamp);
            string toff = tt2UTC(clockOffTimeStamp);
            if( (ton.empty()==true) || (toff.empty()==true) ){
                status = 1;
                return status;//string formating failed
            }
            pair<string,string> UTCPair (ton,toff);
            vector <pair<string,string> >timeStamps;
            timeStamps.push_back(UTCPair);
            string filename = activeTask->get_name();
            file.tf_write(filename,timeStamps);
        };
        activeTask = &emptyTask;//revoke task's active status
    }
    return status;
};

Task* Core::get_Active_Task(void){
    return activeTask;
};

/*
 * Saves the current state of the program to the meta file
 */
void Core::save_prog_state(){
    //get all category names and overwire all categories label in meta file
    std::vector<std::string> categories;
    categories = ctgmgr.get_names();
    file.mf_write_categories(categories,true);
    //get each task name and associated category names then write them to
    //the existing meta file with overwite=false
    std::vector<std::string> tasks;
    tasks = tskmgr.get_names();
    for(auto task : tasks){
        categories = tskmgr.probe(task);
        if(categories.empty() == false){
            file.mf_write(task,categories);
        }
    }
};

/*
 * Loads saved program state from meta file and assigns processed data to the
 * program
 */
void Core::load_prog_state(){
    //parse the meta file into a map
    map<string, vector<string> > metaMap = file.mf_map();

    //add all categories
    vector<string> categories = metaMap["allCat"];
    ctgmgr.add(categories);

    //add all tasks
    vector<string> tasks = metaMap["allTsk"];
    tskmgr.add(tasks);

    //link all categories and tasks that need to be linked
    vector<Task*> tps;
    vector<Category*> cps;
    for(auto task : tasks){
        tps.push_back( tskmgr.fetch(task) );
        categories = metaMap[task];
        cps = ctgmgr.fetch(categories);
        lnkmgr.link(tps,cps);
        tps.clear();
        cps.clear();
    }
};
