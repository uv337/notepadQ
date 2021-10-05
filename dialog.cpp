#include "dialog.h"
#include "ui_dialog.h"
#include<QDebug>
#include<QMessageBox>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
     //connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(dReceive()));
     connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(dSend()));

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::dReceive(QString data){

    //qDebug() << data;
    ui->textBrowser->setText(data);
}
void Dialog::dSend(){
   //connect(this, SIGNAL(dmSend(QString)), this->parent(), SLOT(mReceive(QString)));
connect(this, SIGNAL(dmSend(QString)),parent(), SLOT(mReceive(QString)));
    //qDebug() << data;
QString sData= ui->lineEdit->text();

   emit dmSend(sData);
  // QMessageBox::information(this, "sData : ", sData_P);

}
