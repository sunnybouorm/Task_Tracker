/********************************************************************************
** Form generated from reading UI file 'tsd_deleteprompt.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TSD_DELETEPROMPT_H
#define UI_TSD_DELETEPROMPT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_tsd_deletePrompt
{
public:
    QDialogButtonBox *buttonBox;
    QTextEdit *textEdit;

    void setupUi(QDialog *tsd_deletePrompt)
    {
        if (tsd_deletePrompt->objectName().isEmpty())
            tsd_deletePrompt->setObjectName(QStringLiteral("tsd_deletePrompt"));
        tsd_deletePrompt->resize(521, 86);
        buttonBox = new QDialogButtonBox(tsd_deletePrompt);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(160, 50, 161, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::No|QDialogButtonBox::Yes);
        textEdit = new QTextEdit(tsd_deletePrompt);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(50, 10, 411, 31));
        textEdit->setAutoFillBackground(true);

        retranslateUi(tsd_deletePrompt);
        QObject::connect(buttonBox, SIGNAL(accepted()), tsd_deletePrompt, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), tsd_deletePrompt, SLOT(reject()));

        QMetaObject::connectSlotsByName(tsd_deletePrompt);
    } // setupUi

    void retranslateUi(QDialog *tsd_deletePrompt)
    {
        tsd_deletePrompt->setWindowTitle(QApplication::translate("tsd_deletePrompt", "Delete Prompt", 0));
        textEdit->setHtml(QApplication::translate("tsd_deletePrompt", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">Are you sure you want to delete the selected Items?</span></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class tsd_deletePrompt: public Ui_tsd_deletePrompt {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TSD_DELETEPROMPT_H
