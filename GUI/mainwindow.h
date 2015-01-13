#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Core.h"
#include "Task_Setup.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow *ui;
    Core *_core;
    Task_Setup_Dialog tsd;
    void init_tsd();// initializes Task and Category setup Dialog

public:
    explicit MainWindow(Core &core,QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_task_toolButton_clicked();

public slots:
    void updateTasks();
    void updateCategories();
    void update();
};

#endif // MAINWINDOW_H
