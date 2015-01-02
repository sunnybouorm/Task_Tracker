/* Last updated : 18/12/2014
 * Date Created : 18/12/2014
 * Author       : Sultan Bou Orm
 * Description  :
 * Manages Debug macros
 */

#ifndef DEBUG_H
#define DEBUG_H
//usage: comment irrelevant definitions to disable

//FILE_IO
//------------------------------------------------------------------------------

//general file access
#define FIO_STREAMO// enable file I/O stream output to cout
//#define FIO_EXISTS // enables debug for class member function exists
//#define FIO_CREATE // enables debug for class member function create
//#define FIO_DESTROY // enables debug for class member function delete

//task meta file access
#define FIO_MF_APP_TASKS //enable Ostream for mf_app_tasks function to cout


#endif // DEBUG_H
