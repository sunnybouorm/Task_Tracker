/********************************************************************************
** Form generated from reading UI file 'Task_Setup.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASK_SETUP_H
#define UI_TASK_SETUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Task_Setup_Dialog
{
public:
    QGroupBox *groupBox;
    QDialogButtonBox *buttonBox;
    QLineEdit *lineEdit_3;
    QTableWidget *tableWidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout_2;
    QComboBox *taskName_comboBox;
    QLineEdit *categoryName_lineEdit;
    QPushButton *addTask_pushButton;
    QPushButton *addCategory_pushButton;
    QPushButton *edit_pushButton;
    QPushButton *deleteSelected_pushButton;

    void setupUi(QDialog *Task_Setup_Dialog)
    {
        if (Task_Setup_Dialog->objectName().isEmpty())
            Task_Setup_Dialog->setObjectName(QStringLiteral("Task_Setup_Dialog"));
        Task_Setup_Dialog->resize(761, 532);
        groupBox = new QGroupBox(Task_Setup_Dialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 741, 511));
        buttonBox = new QDialogButtonBox(groupBox);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(630, 460, 81, 41));
        buttonBox->setLayoutDirection(Qt::RightToLeft);
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Close);
        lineEdit_3 = new QLineEdit(groupBox);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(20, 470, 521, 20));
        tableWidget = new QTableWidget(groupBox);
        if (tableWidget->columnCount() < 3)
            tableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(10, 20, 711, 311));
        gridLayoutWidget = new QWidget(groupBox);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 340, 301, 91));
        gridLayout_2 = new QGridLayout(gridLayoutWidget);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        taskName_comboBox = new QComboBox(gridLayoutWidget);
        taskName_comboBox->setObjectName(QStringLiteral("taskName_comboBox"));
        taskName_comboBox->setEditable(true);

        gridLayout_2->addWidget(taskName_comboBox, 0, 0, 1, 1);

        categoryName_lineEdit = new QLineEdit(gridLayoutWidget);
        categoryName_lineEdit->setObjectName(QStringLiteral("categoryName_lineEdit"));

        gridLayout_2->addWidget(categoryName_lineEdit, 1, 0, 1, 1);

        addTask_pushButton = new QPushButton(gridLayoutWidget);
        addTask_pushButton->setObjectName(QStringLiteral("addTask_pushButton"));

        gridLayout_2->addWidget(addTask_pushButton, 0, 1, 1, 1);

        addCategory_pushButton = new QPushButton(gridLayoutWidget);
        addCategory_pushButton->setObjectName(QStringLiteral("addCategory_pushButton"));

        gridLayout_2->addWidget(addCategory_pushButton, 1, 1, 1, 1);

        edit_pushButton = new QPushButton(gridLayoutWidget);
        edit_pushButton->setObjectName(QStringLiteral("edit_pushButton"));

        gridLayout_2->addWidget(edit_pushButton, 0, 2, 1, 1);

        deleteSelected_pushButton = new QPushButton(gridLayoutWidget);
        deleteSelected_pushButton->setObjectName(QStringLiteral("deleteSelected_pushButton"));

        gridLayout_2->addWidget(deleteSelected_pushButton, 1, 2, 1, 1);


        retranslateUi(Task_Setup_Dialog);

        QMetaObject::connectSlotsByName(Task_Setup_Dialog);
    } // setupUi

    void retranslateUi(QDialog *Task_Setup_Dialog)
    {
        Task_Setup_Dialog->setWindowTitle(QApplication::translate("Task_Setup_Dialog", "Task and Category Setup", 0));
        groupBox->setTitle(QApplication::translate("Task_Setup_Dialog", "Task and Category Setup", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem->setText(QApplication::translate("Task_Setup_Dialog", "Type", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem1->setText(QApplication::translate("Task_Setup_Dialog", "Hidden", 0));
        taskName_comboBox->setCurrentText(QApplication::translate("Task_Setup_Dialog", "Task Name", 0));
        categoryName_lineEdit->setText(QApplication::translate("Task_Setup_Dialog", "Category Name", 0));
        addTask_pushButton->setText(QApplication::translate("Task_Setup_Dialog", "Add Task", 0));
        addCategory_pushButton->setText(QApplication::translate("Task_Setup_Dialog", "Add Category", 0));
        edit_pushButton->setText(QApplication::translate("Task_Setup_Dialog", "Edit", 0));
        deleteSelected_pushButton->setText(QApplication::translate("Task_Setup_Dialog", "Delete Selected", 0));
    } // retranslateUi

};

namespace Ui {
    class Task_Setup_Dialog: public Ui_Task_Setup_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASK_SETUP_H
