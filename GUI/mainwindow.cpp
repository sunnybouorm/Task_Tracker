#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{    
    //add a task selection drop down label
    //TODO

    //add a task selection drop down label and a clock on/off button
    //TODO

    //add a text field and button for adding a task
    //TODO

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    //save program state to meta file
    //TODO
    delete ui;
}
