/********************************************************************************
** Form generated from reading UI file 'tsd_categoryeditdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TSD_CATEGORYEDITDIALOG_H
#define UI_TSD_CATEGORYEDITDIALOG_H

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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_tsd_categoryEditDialog
{
public:
    QGroupBox *groupBox;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QComboBox *comboBox;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *tsd_categoryEditDialog)
    {
        if (tsd_categoryEditDialog->objectName().isEmpty())
            tsd_categoryEditDialog->setObjectName(QStringLiteral("tsd_categoryEditDialog"));
        tsd_categoryEditDialog->resize(312, 156);
        groupBox = new QGroupBox(tsd_categoryEditDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 281, 131));
        gridLayoutWidget = new QWidget(groupBox);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 30, 241, 41));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(gridLayoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 0, 1, 1, 1);

        comboBox = new QComboBox(gridLayoutWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setEditable(true);

        gridLayout->addWidget(comboBox, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(groupBox);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(50, 90, 161, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(tsd_categoryEditDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), tsd_categoryEditDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), tsd_categoryEditDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(tsd_categoryEditDialog);
    } // setupUi

    void retranslateUi(QDialog *tsd_categoryEditDialog)
    {
        tsd_categoryEditDialog->setWindowTitle(QApplication::translate("tsd_categoryEditDialog", "Dialog", 0));
        groupBox->setTitle(QApplication::translate("tsd_categoryEditDialog", "Edit Category", 0));
        pushButton->setText(QApplication::translate("tsd_categoryEditDialog", "Rename", 0));
        comboBox->setCurrentText(QApplication::translate("tsd_categoryEditDialog", "Category Name", 0));
    } // retranslateUi

};

namespace Ui {
    class tsd_categoryEditDialog: public Ui_tsd_categoryEditDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TSD_CATEGORYEDITDIALOG_H
