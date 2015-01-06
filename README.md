Task_Tracker
============
I am writing this program for myself as a hobby project to learn some C++, QT4/5, and get familiar with github for version control. If I anyone uses this code I take no responsibilty for any porblems that may occur from using this software.

> Program Description:
===========================
>> Summary:
The program is meant to aid the user with time management, the user clocks on and off from selected tasks and usage statistics are generated in the form of a pie chart and bar chart to help provide insight on where time was spent and be able to visually compare time spent on tasks.

>> Usage:
The program is not ready to be used as no user interface has been implemented yet.

> Development tools:
===========================
* The program is written in C++ with Code::Blocks IDE and GNU GCC compiler with C++11 enabled
* Catch is used for Unit testing but its source is not included in the project, that would have to be downloaded to gain access to "catch.hpp" which is all that is required to run the tests.

> Progress:
===========================
>> Milestones:
* Create a Graphical User Interface for the application
* Create a Command Line Interface if required (optional)
* Get the application to work on both Linux and Windows operating systems

>> Completed:
* None

>> Features and Ideas
===========================
>>> Adding and editing tasks:
The user starts by adding tasks with the option to place a task under several categories. For instance adding a task "calculus" under categories "math" and "study". The user can then proceed to edit or delete categories and tasks.

>>> Deleting tasks and Categories
Deleting a task does not delete any associated categories, likewise deleting categories does not delete associated tasks. To delete all tasks belonging to a specific category or set of categories a special command would be required.

>>> Clocking on and Off
Once the user has added a minimum of one task then the user can proceed to select a task from a drop down list and toggle between clocking on and clocking off by pressing a button. The clock on and clock off times are recorded in a task file with the extension ".task". Every task has a specific ".task" file associated with it that is used to preserve the state of the program after quiting the application.
Furthermore, there can be only a single active task at any given time, a task is deemed active the moment it is clocked on. The user will have to clock off to revoke its active status.

>>> Hiding tasks and categories from selection 
Tasks that are hidden are not displayed in the drop down list for clocking on and off, However they can still be selected and displayed in usage statistics.

>>> Task selection filters
A category drop down list can be used to filter available tasks by category, a text search field can be used to find a task by name even if it is hidden. A checkbox for viewing all hidden tasks and categories would be useful.

>>> Usage Statics
Usage statstics would be provided primarily by a pie chart and bar chart. A custom date interval can be set for the pie chart along with a specific set of tasks selected.
The bar chart can be configured to display a custom start and end date interval with selected tasks for comparison, y axis would show time spent and x axis would show the date whose interval can be adjusted between daily, monthly, and yearly.

>>> Hiding tasks and categories from Usage Statistics

>>> plotting Pie chart and bar graph in a seperate window

> Program Status:
===========================
The program is not complete, many elements are missing. For starters there is no user interface, at the moment some logic has been implemented with regards to adding and deleting tasks and categories, file_IO, Linking tasks and categories together, and clocking on and off.
