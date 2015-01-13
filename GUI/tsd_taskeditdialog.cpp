#include "tsd_taskeditdialog.h"
#include "ui_tsd_taskeditdialog.h"

tsd_taskEditDialog::tsd_taskEditDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::tsd_taskEditDialog)
{
    ui->setupUi(this);
}

tsd_taskEditDialog::~tsd_taskEditDialog()
{
    delete ui;
}

void tsd_taskEditDialog::attachCore(Core *_core){
    this->_core = _core;
}


void tsd_taskEditDialog::on_buttonBox_clicked(QAbstractButton *button)
{
    QDialogButtonBox::StandardButton stdButton =
        ui->buttonBox->standardButton(button);
    switch(stdButton){
    case QDialogButtonBox::Apply:
        //Confirm changes
        //TODO
        close();
        break;
    case QDialogButtonBox::Cancel:
        //discard changes
        close();
    default:
        break;
    }
}


void tsd_taskEditDialog::on_taskNameChange_pushbutton_clicked()
{
    //Rename the task
    //TODO
}
