#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"downloader.h"
#include<QMessageBox>
#include <QDesktopWidget>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   //  this->setGeometry(x(),y(),100,100);
urlline="HTTPS:\\www.test.ru\text1.txt";
    //Проверяем признак обновления

    if (ui->checkBox->isChecked())
    {
      aut=1;
    }
    else {aut=0;}

   // QRect rect = frameGeometry();
  //    rect.moveLeft(QDesktopWidget().availableGeometry().center());


    QRect rect = QApplication::desktop()->availableGeometry();
   // move(rect.bottomLeft());
    int screenHeight = rect.height();
    int screenWidth = rect.width();
   qDebug() << screenHeight;
    // move(rect.center());
    this->setGeometry(screenWidth-250,screenHeight-300,800,600);
   //this.setGeometry(QRect(screenHeight-300, screenHeight-300,this.frameGeometry().width(),this.frameGeometry().height()))
    this -> setTrayIconActions();
    this -> showTrayIcon();

/*
 Монтируем таймер
*/

       tmr = new QTimer(this); // Создаем объект класса QTimer и передаем адрес переменной
       tmr->setInterval(10000); // Задаем интервал таймера
     if (aut == 1)
     {
       connect(tmr, SIGNAL(timeout()), this, SLOT(on_pushButton_clicked())); // Подключаем сигнал таймера к нашему слоту
      //  connect(tmr, SIGNAL(timeout()), this, SLOT(on_pushButton_3_clicked()));
       //connect(tmr, SIGNAL(timeout()), this, SLOT(on_pushButton_2_clicked()));
              tmr->start();
     }
}

MainWindow::~MainWindow()
{
    delete ui;




connect(trayIcon,SIGNAL(activated(QSystemTrayIcon::ActivationReason)),this,SLOT(showHide(QSystemTrayIcon::ActivationReason)));
}

void MainWindow::on_pushButton_clicked()
{ //   QSqlDatabase dbs = QSqlDatabase::addDatabase("QMYSQL");
// dbs = new QSqlDataBase();     //    dbs = QSqlDatabase::addDatabase("QMYSQL", "query");

QString s=ui->lineEdit->text();
db = QSqlDatabase::addDatabase("QMYSQL");
//dbs = new QSqlDataBase();
        db.setHostName("mysql89.1gb.ru");
        db.setDatabaseName(ui->lineEdit->text());
        db.setUserName(ui->lineEdit_2->text());
        db.setPassword(ui->lineEdit_3->text());

        if(db.open())
           {
               qDebug("Connected!");

         ui->pushButton_3->click();
           }
           else
           {
               qDebug("Connection Failed!");
           }

          // dbs.close();
}

/* Метод, который обрабатывает событие закрытия окна приложения
 * */
void MainWindow::showHide(QSystemTrayIcon::ActivationReason r)
{
  /*    //если нажато левой кнопкой продолжаем
    if (!this->isVisible())
    {  //если окно было не видимо - отображаем его
        this->show();
    } else
    {
        this->hide();  //иначе скрываем*/
      }




void MainWindow::on_pushButton_2_clicked()
{/*
    if (!this->isVisible())
    {  //если окно было не видимо - отображаем его
        this->show();
    } else
    {
        this->hide();  //иначе скрываем
      }*/
db.close();
}

void MainWindow::on_pushButton_3_clicked()
{
    QSqlQuery query("SELECT * FROM client ");
     query.next();
     ui->label_4->setText(query.value(4).toString());
}

void MainWindow::showTrayIcon()
{
    // Создаём экземпляр класса и задаём его свойства...
    trayIcon = new QSystemTrayIcon(this);
    QIcon trayImage("try.png");
    trayIcon -> setIcon(trayImage);
    trayIcon -> setContextMenu(trayIconMenu);

    // Подключаем обработчик клика по иконке...
    connect(trayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(trayIconActivated(QSystemTrayIcon::ActivationReason)));

    // Выводим значок...
    trayIcon -> show();
}


// Методы обработки кликов по иконке в системном трее:
void MainWindow::trayActionExecute()
{
    QMessageBox::information(this, "TrayIcon", "Закрылся");
}

void MainWindow::trayIconActivated(QSystemTrayIcon::ActivationReason reason)
{
    switch (reason)
    {
        case QSystemTrayIcon::Trigger:
        case QSystemTrayIcon::DoubleClick:
            this -> trayActionExecute();
            break;
        default:
            break;
    }
}
// Контекстное меню, нашего значка

void MainWindow::setTrayIconActions()
{
    // Setting actions...
    minimizeAction = new QAction("Свернуть", this);
    restoreAction = new QAction("Восстановить", this);
    quitAction = new QAction("Выход", this);

    // Connecting actions to slots...
    connect (minimizeAction, SIGNAL(triggered()), this, SLOT(hide()));
    connect (restoreAction, SIGNAL(triggered()), this, SLOT(showNormal()));
    connect (quitAction, SIGNAL(triggered()), qApp, SLOT(quit()));

    // Setting system tray's icon menu...
    trayIconMenu = new QMenu(this);
    trayIconMenu -> addAction (minimizeAction);
    trayIconMenu -> addAction (restoreAction);
    trayIconMenu -> addAction (quitAction);
}
void MainWindow::changeEvent(QEvent *event)
{
    QMainWindow::changeEvent(event);
    if (event -> type() == QEvent::WindowStateChange)
    {
        if (isMinimized())
        {
            this -> hide();
        }
    }
}


void MainWindow::on_pushButton_4_clicked()
{
 QString   path1=QDir::currentPath()+"/1.txt";
  QString   path2=QDir::currentPath()+"/arhiv/copy1.txt";
 qDebug() << path1;
 QFile MyFile(path1);
 QFile destFile("\1.txt");
//QFile::copy("E:\1.txt", "E:\copy_1.text");
bool result = QFile::copy(path1, path2);
    qDebug() << result;

}

void MainWindow::on_checkBox_clicked()
{
    if(ui->checkBox->isChecked())
    {
    aut=1;
    }
    else {aut=0;}
}

void MainWindow::on_pushButton_5_clicked()
{   QString   path2=QDir::currentPath()+"/download/";
    m_downloader.get(path2, urlline);
}

void MainWindow::on_pushButton_6_clicked()
{
    QString   TextInfo,VersB,FileUp;
   int START=0;
    QSqlQuery query("SELECT * FROM client");
    while (query.next())
    {
        quint64 bytesTotal64 = QStorageInfo::root().bytesTotal()/1000/1000;
        QString text;
        QString hash_string = text.setNum(bytesTotal64) + "-" + QSysInfo::buildCpuArchitecture();
        QString hash = QString("%1").arg(QString(QCryptographicHash::hash(hash_string.toUtf8(), QCryptographicHash::Md5).toHex()));
        hash = hash.toUpper();

        if((query.value("lic_key").toString() == hash) && (START == 0)){

            START=1;
            VersB = query.value("version").toString();
            FileUp = query.value("fileup").toString();
            QString company = query.value("company").toString();
            TextInfo = TextInfo + "\n \n Зарегистрировано: \n" + company;
            TextInfo = TextInfo + "\n \n Лицензия: \n" + hash;
            ui->label_4->setText(TextInfo);
        }
    }

    if(START == 0){
        TextInfo = TextInfo + " Лицензия не найдена.";
        ui->label_4->setText(TextInfo);
    }
}

void MainWindow::on_pushButton_7_clicked()
{
   // QSqlDatabase dbmysql;
  //   dbmysql = QSqlDatabase::addDatabase("QMYSQL");
    int START=0;
    if(START == 0){
        QNetworkInterface *network = new QNetworkInterface();
        foreach(QNetworkInterface interface, network->allInterfaces())
        {
            //qDebug() << "-------------------------";

            quint64 bytesTotal64 = QStorageInfo::root().bytesTotal()/1000/1000;
            QString text;
            QString hash_string = text.setNum(bytesTotal64) + "-" + QSysInfo::buildCpuArchitecture();

            QString hash = QString("%1").arg(QString(QCryptographicHash::hash(hash_string.toUtf8(), QCryptographicHash::Md5).toHex()));
            QString mac = interface.hardwareAddress();
            QString name = interface.humanReadableName() + " (" + interface.name() + ")";

            //ui->lineEdit_dev->setText(hash.toUpper());

            if((mac != "") && (mac != "00:00:00:00:00:00:00:E0")){
                QString strCr = "INSERT INTO `query` (`type`,`hash`,`mac`,`name`,`hash_string`,`company`) VALUES ('%1', '%2', '%3', '%4','%5','%6');";
                QString strCreate=strCr.arg("Запрос").arg(hash.toUpper()).arg(mac).arg(name).arg(hash_string).arg(ui->lineEdit->text());
                QSqlQuery query2(strCreate, db);
            }
        }
        QMessageBox::information(0, "Information", "Запрос сформирован. \nСообщите название организации менеджеру для регистрации.");
    }
}
