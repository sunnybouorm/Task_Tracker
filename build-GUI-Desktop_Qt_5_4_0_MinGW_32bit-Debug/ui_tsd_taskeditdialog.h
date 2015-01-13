/********************************************************************************
** Form generated from reading UI file 'tsd_taskeditdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TSD_TASKEDITDIALOG_H
#define UI_TSD_TASKEDITDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_tsd_taskEditDialog
{
public:
    QDialogButtonBox *buttonBox;
    QTableWidget *tableWidget;
    QLineEdit *lineEdit;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_2;
    QPushButton *taskNameChange_pushbutton;

    void setupUi(QDialog *tsd_taskEditDialog)
    {
        if (tsd_taskEditDialog->objectName().isEmpty())
            tsd_taskEditDialog->setObjectName(QStringLiteral("tsd_taskEditDialog"));
        tsd_taskEditDialog->resize(611, 370);
        buttonBox = new QDialogButtonBox(tsd_taskEditDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(440, 320, 171, 32));
        buttonBox->setLayoutDirection(Qt::RightToLeft);
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Apply|QDialogButtonBox::Cancel);
        tableWidget = new QTableWidget(tsd_taskEditDialog);
        if (tableWidget->columnCount() < 3)
            tableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(10, 60, 491, 241));
        lineEdit = new QLineEdit(tsd_taskEditDialog);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(10, 30, 361, 20));
        gridLayoutWidget = new QWidget(tsd_taskEditDialog);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 310, 221, 41));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit_2 = new QLineEdit(gridLayoutWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        gridLayout->addWidget(lineEdit_2, 0, 0, 1, 1);

        taskNameChange_pushbutton = new QPushButton(gridLayoutWidget);
        taskNameChange_pushbutton->setObjectName(QStringLiteral("taskNameChange_pushbutton"));

        gridLayout->addWidget(taskNameChange_pushbutton, 0, 1, 1, 1);


        retranslateUi(tsd_taskEditDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), tsd_taskEditDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), tsd_taskEditDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(tsd_taskEditDialog);
    } // setupUi

    void retranslateUi(QDialog *tsd_taskEditDialog)
    {
        tsd_taskEditDialog->setWindowTitle(QApplication::translate("tsd_taskEditDialog", "Edit", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("tsd_taskEditDialog", "Category", 0));
        lineEdit->setText(QApplication::translate("tsd_taskEditDialog", "Select Relevant Categories", 0));
        lineEdit_2->setText(QApplication::translate("tsd_taskEditDialog", "Task Name", 0));
        taskNameChange_pushbutton->setText(QApplication::translate("tsd_taskEditDialog", "Change Name", 0));
    } // retranslateUi

};

namespace Ui {
    class tsd_taskEditDialog: public Ui_tsd_taskEditDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TSD_TASKEDITDIALOG_H
