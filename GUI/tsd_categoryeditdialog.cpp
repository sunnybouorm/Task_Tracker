#include "tsd_categoryeditdialog.h"
#include "ui_tsd_categoryeditdialog.h"

tsd_categoryEditDialog::tsd_categoryEditDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::tsd_categoryEditDialog)
{
    ui->setupUi(this);
}

tsd_categoryEditDialog::~tsd_categoryEditDialog()
{
    delete ui;
}

void tsd_categoryEditDialog::attachCore(Core *_core){
    this->_core = _core;
}
