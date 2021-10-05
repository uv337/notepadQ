#ifndef NOTEPADQ_H
#define NOTEPADQ_H

#include <QMainWindow>
#include<QDialog>
#include"dialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class notepadq; }
QT_END_NAMESPACE

class notepadq : public QMainWindow
{
    Q_OBJECT

public:
    explicit notepadq(QWidget *parent = 0);
    ~notepadq();
public slots:
      void mReceive(QString sData);

private slots:
    void newDocument();

    void open();

    void save();

    void saveAs();

    void print();

    void exit();

    void copy();

    void cut();

    void paste();

    void undo();

    void redo();

    void selectFont();

    void about();
    void decoder();
   /*  void charCount(); */
    //void  find_and_replace();
     void find();
     void mSend(QString);
     void on_findButton_clicked(QString);

  signals:
     void mdSend(QString data);

private:
    Ui::notepadq *ui;
     QString currentFile;
    QDialog *dialog1;


};

#endif // NOTEPADQ_H
