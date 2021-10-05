#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QString>
#include "notepadq.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();


private:
    Ui::Dialog *ui;


private    slots:
     void dReceive(QString data);
      void dSend();
         signals:
 void dmSend(QString sData);

};

#endif // DIALOG_H
