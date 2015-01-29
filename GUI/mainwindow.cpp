#include "mainwindow.h"
#include "ui_mainwindow.h"

//Constructors/Deconstructors
MainWindow::MainWindow(Core &core, QWidget *parent/*=0*/) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    _core = &core;

    init_tsd(); // initialize Task and Category setup Dialog

    ui->setupUi(this);

    update();//update all entries in mainWindow
}

MainWindow::~MainWindow()
{
    //save program state to meta file
    _core->save_prog_state();
    delete ui;
}

void MainWindow::init_tsd()
{
    tsd.setModal(true);
    tsd.attachCore(_core);
    tsd.setParent(this->window(),Qt::Dialog);

    //setup signal and slot connections
    QObject::connect(&tsd, SIGNAL(addTask_pushButton_clicked()),
                     this, SLOT(updateTasks()) );
    QObject::connect(&tsd, SIGNAL(addCategory_pushButton_clicked()),
                     this, SLOT(updateCategories()) );
}

//Class member functions
void MainWindow::on_task_toolButton_clicked()
{
    //open Task and Category setup dialog window
    tsd.show();
}

void MainWindow::updateTasks()
{
    //Load all tasks in application _core to the activeTask_comboBox
    ui->activeTask_comboBox->clear();
    std::vector<std::string> taskNames = _core->tskmgr.get_names();
    for(std::string taskName : taskNames){
        ui->activeTask_comboBox->addItem(QString::fromStdString(taskName) );
    }
}

void MainWindow::updateCategories()
{
    //Load all Categories in application _core to the activeCategory_comboBox
    ui->categoryFilter_comboBox->clear();
    ui->categoryFilter_comboBox->addItem("None");
    std::vector<std::string> categoryNames = _core->ctgmgr.get_names();
    for(std::string categoryName : categoryNames){
        if(categoryName.empty()==false){
            ui->categoryFilter_comboBox->addItem(QString::fromStdString(categoryName) );
        }
    }
}

void MainWindow::update()
{
    updateTasks();
    updateCategories();
}
