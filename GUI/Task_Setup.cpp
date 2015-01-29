#include <QDialogButtonBox>
#include "ui_Task_Setup.h"
#include "Task_Setup.h"

Task_Setup_Dialog::Task_Setup_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Task_Setup_Dialog)
{
    this->_core = _core;
    ui->setupUi(this);
}

Task_Setup_Dialog::~Task_Setup_Dialog()
{
    delete ui;
}

void Task_Setup_Dialog::on_addTask_pushButton_clicked()
{  
    //add task
    std::string taskName;
    taskName = taskName_Qs.toStdString();
    _core->tskmgr.add(taskName);

    //emit signal
    emit addTask_pushButton_clicked();
}

void Task_Setup_Dialog::on_addCategory_pushButton_clicked()
{
    //add category
    std::string categoryName;
    categoryName = categoryName_Qs.toStdString();
    _core->ctgmgr.add(categoryName);

    //emit signal
    emit addCategory_pushButton_clicked();
}

void Task_Setup_Dialog::on_deleteSelected_pushButton_clicked()
{
    //open a dialog to prompt user
    tsd_dp.setParent(this->window(), Qt::Dialog);
    tsd_dp.setModal(true);
    tsd_dp.attachCore(_core);
    tsd_dp.show();

    //delete selected tasks and categories
    //TODO
}

void Task_Setup_Dialog::on_buttonBox_clicked(QAbstractButton *button)
{
     QDialogButtonBox::StandardButton stdButton =
        ui->buttonBox->standardButton(button);
    switch(stdButton){
    case QDialogButtonBox::Close:
        close();
        break;
    default:
        break;
    }
}

void Task_Setup_Dialog::attachCore(Core *_core){
    this->_core = _core;
}

void Task_Setup_Dialog::on_taskName_comboBox_activated(const QString &arg1)
{
    taskName_Qs = arg1;
}

void Task_Setup_Dialog::on_taskName_comboBox_editTextChanged(const QString &arg1)
{
    taskName_Qs = arg1;
}

void Task_Setup_Dialog::on_categoryName_comboBox_activated(const QString &arg1)
{
    categoryName_Qs = arg1;
}

void Task_Setup_Dialog::on_categoryName_comboBox_editTextChanged(const QString &arg1)
{
    categoryName_Qs = arg1;
}

void Task_Setup_Dialog::on_task_edit_pushButton_clicked()
{
    tsd_ed_tsk.setParent(this->window(), Qt::Dialog);
    tsd_ed_tsk.setModal(true);
    tsd_ed_tsk.attachCore(_core);
    tsd_ed_tsk.show();
}

void Task_Setup_Dialog::on_category_edit_pushButton_clicked()
{
    tsd_ed_cat.setParent(this->window(), Qt::Dialog);
    tsd_ed_cat.setModal(true);
    tsd_ed_cat.attachCore(_core);
    tsd_ed_cat.show();
}
