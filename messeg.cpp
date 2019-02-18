#include "messeg.h"
#include "ui_messeg.h"
#include "mainwindow.h"
#include "QDesktopWidget"
messeg::messeg(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::messeg)
{
    ui->setupUi(this);
    QRect rect = QApplication::desktop()->availableGeometry();
   // move(rect.bottomLeft());
    int screenHeight = rect.height();
    int screenWidth = rect.width();
   qDebug() << screenHeight;
    // move(rect.center());
    this->setGeometry(screenWidth-300,screenHeight-200,300,200);
}

messeg::~messeg()
{
    delete ui;
}

void messeg::on_pushButton_clicked()
{


}

void messeg::getData(QString data){
    urlPuth = data;
       qDebug() << urlPuth;
}
