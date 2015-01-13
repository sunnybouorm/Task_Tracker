#include "tsd_deleteprompt.h"
#include "ui_tsd_deleteprompt.h"
#include <QDialogButtonBox>

tsd_deletePrompt::tsd_deletePrompt(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::tsd_deletePrompt)
{
    ui->setupUi(this);
}

tsd_deletePrompt::~tsd_deletePrompt()
{
    delete ui;
}

void tsd_deletePrompt::attachCore(Core *_core){
    this->_core = _core;
}


void tsd_deletePrompt::on_buttonBox_clicked(QAbstractButton *button)
{
    QDialogButtonBox::StandardButton stdButton =
        ui->buttonBox->standardButton(button);
    switch(stdButton){
    case QDialogButtonBox::Yes:
        //Confirm changes
        //TODO
        close();
        break;
    case QDialogButtonBox::No:
        //discard changes
        close();
    default:
        break;
    }
}
