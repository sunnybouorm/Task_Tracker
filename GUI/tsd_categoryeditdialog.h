#ifndef TSD_CATEGORYEDITDIALOG_H
#define TSD_CATEGORYEDITDIALOG_H

#include <QDialog>
#include "Core.h"

namespace Ui {
class tsd_categoryEditDialog;
}

class tsd_categoryEditDialog : public QDialog
{
    Q_OBJECT

public:
    explicit tsd_categoryEditDialog(QWidget *parent = 0);
    ~tsd_categoryEditDialog();
    void attachCore(Core *_core);

private:
    Ui::tsd_categoryEditDialog *ui;
    Core *_core;
};

#endif // TSD_CATEGORYEDITDIALOG_H
