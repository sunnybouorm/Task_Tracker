#ifndef TSD_TASKEDITDIALOG_H
#define TSD_TASKEDITDIALOG_H

#include <QDialog>
#include <QAbstractButton>
#include "Core.h"

namespace Ui {
class tsd_taskEditDialog;
}

class tsd_taskEditDialog : public QDialog
{
    Q_OBJECT

public:
    explicit tsd_taskEditDialog(QWidget *parent = 0);
    ~tsd_taskEditDialog();

    void attachCore(Core *_core);

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);

    void on_taskNameChange_pushbutton_clicked();

private:
    Ui::tsd_taskEditDialog *ui;

    Core *_core;
};

#endif // TSD_TASKEDITDIALOG_H
