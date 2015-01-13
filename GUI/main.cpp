#include "mainwindow.h"
#include "Task_Setup.h"
#include <QApplication>

#include "directories.h"
#include "Core.h"

int main(int argc, char *argv[])
{
    //setup application core
    Core core;
    core.file.set_META_DIR(META_DIR);
    core.file.set_TASK_DIR(TASK_DIR);

    //load program state from meta file
    core.load_prog_state();

    //setup GUI
    QApplication a(argc, argv);
    MainWindow w(core);
    w.show();

    return a.exec();
}
