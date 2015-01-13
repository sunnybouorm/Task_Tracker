#ifndef TSD_DELETEPROMPT_H
#define TSD_DELETEPROMPT_H

#include <QDialog>
#include <QAbstractButton>
#include "Core.h"

namespace Ui {
class tsd_deletePrompt;
}

class tsd_deletePrompt : public QDialog
{
    Q_OBJECT

public:
    explicit tsd_deletePrompt(QWidget *parent = 0);
    ~tsd_deletePrompt();

    void attachCore(Core *_core);

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);

private:
    Ui::tsd_deletePrompt *ui;
    Core* _core;
};

#endif // TSD_DELETEPROMPT_H
