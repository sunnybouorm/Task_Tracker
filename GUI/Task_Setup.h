#ifndef TASK_SETUP_H
#define TASK_SETUP_H

#include <QDialog>
#include <QAbstractButton>
#include <vector>
#include <string>

#include "Core.h"
#include "tsd_deleteprompt.h"
#include "tsd_taskeditdialog.h"
#include "tsd_categoryeditdialog.h"

namespace Ui {
class Task_Setup_Dialog;
}

class Task_Setup_Dialog : public QDialog
{
    Q_OBJECT

public:    
    explicit Task_Setup_Dialog(QWidget *parent = 0);
    ~Task_Setup_Dialog();

    void attachCore(Core *_core);

signals:
    void addTask_pushButton_clicked();
    void addCategory_pushButton_clicked();

private slots:
    void on_addTask_pushButton_clicked();
    void on_addCategory_pushButton_clicked();
    void on_deleteSelected_pushButton_clicked();
    void on_buttonBox_clicked(QAbstractButton *button);
    void on_taskName_comboBox_activated(const QString &arg1);
    void on_taskName_comboBox_editTextChanged(const QString &arg1);
    void on_categoryName_comboBox_activated(const QString &arg1);
    void on_categoryName_comboBox_editTextChanged(const QString &arg1);
    void on_task_edit_pushButton_clicked();
    void on_category_edit_pushButton_clicked();

private:
    Ui::Task_Setup_Dialog *ui;
    Core *_core;
    QString taskName_Qs;
    QString categoryName_Qs;

    tsd_deletePrompt tsd_dp;
    tsd_taskEditDialog tsd_ed_tsk;
    tsd_categoryEditDialog tsd_ed_cat;
};

#endif // TASK_SETUP_H
