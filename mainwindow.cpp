#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"downloader.h"
#include<QMessageBox>
#include <QDesktopWidget>
#include "messeg.h"

//extern QString Version;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   //  this->setGeometry(x(),y(),100,100);
//urlline="HTTPS:\\www.test.ru\text1.txt";
    //Проверяем признак обновления
//Flag=0;
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
 Слот передачи данных
*/       myform = new messeg;



 /* Монтируем таймер     */
       tmr = new QTimer(this); // Создаем объект класса QTimer и передаем адрес переменной
       tmr->setInterval(100000); // Задаем интервал таймера
        connect(tmr, SIGNAL(timeout()), this, SLOT(on_pushButton_clicked()));
        connect(tmr, SIGNAL(timeout()), this, SLOT(on_pushButton_3_clicked()));
   Flag==3;
   //  {
   //    connect(tmr, SIGNAL(timeout()), this, SLOT(on_pushButton_5_clicked()));
     //}
      tmr1 = new QTimer(this); // Создаем объект класса QTimer и передаем адрес переменной// проверка запущенного приложения если нет копирование
      tmr1->setInterval(150000);


      // Задаем интервал таймера

      /*
       Проверяем файл !!! основной и в загрузчике!//
        */

     connect(tmr1, SIGNAL(timeout()), this, SLOT(on_pushButton_4_clicked()));
      //  ui->pushButton_3->click();
     //     ui->pushButton_5->click();
     //       ui->pushButton_4->click();
     if (aut == 1)
     {
      // connect(tmr, SIGNAL(timeout()), this, SLOT(on_pushButton_clicked())); // Подключаем сигнал таймера к нашему слоту
      //  connect(tmr, SIGNAL(timeout()), this, SLOT(on_pushButton_3_clicked()));
       //connect(tmr, SIGNAL(timeout()), this, SLOT(on_pushButton_2_clicked()));
              tmr->start();
              tmr1->start();
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

     id=query.value(0).toInt();
//QString s1="UPDATE client SET versionclient = '102' WHERE id = "+query.value(0).toString();
//qDebug() << s1;
     //query.exec(s1);
 //   qDebug() << id;
  //   ui->label_4->setText(query.value(4).toString());
urlFile=query.value(5).toString();
//urlPuth=query.value(10).toString();

    urlPuth=QDir::currentPath()+"/";
   // QString tmp1=QDir::current().absoluteFilePath();
//QFile::exists(urlPuth+"settings.conf");
if (! QFile::exists(urlPuth+"settings.conf")){
   // saveLog("Не найден файл с Настройками!");
    QMessageBox::warning(0,"Ошибка запуска", "Не найден файл settings.conf !");
    return;

}


QSettings settings( urlPuth+"settings.conf", QSettings::IniFormat );
VC = settings.value("Goods_input/version").toString();


//on_pushButton_5_clicked();
 if (query.value(4).toString()!=query.value(6).toString())
{
Flag=0;

 // qDebug() << VC;
//  ui->label_4->setText(VC+" Ваша версия ");
on_pushButton_5_clicked();
qDebug() << query.value(4).toString() << query.value(6).toString() <<"ОБНОВЛЯЕМ ТУ" ;
}
else
{
   Flag=3;
}
 if (query.value(4).toString()!=query.value(11).toString())
{
Flag=1;
on_pushButton_5_clicked();
qDebug() << query.value(4).toInt() << "ОБНОВЛЯЕМ KK" ;
}
else
{
    Flag=3;
}
  // QString Ver = settings->value("database/path").toString();
 //Ver="0";
  // QSettings settings("MySoft", "Star Runner");
  // qDebug() << VC;
   ui->label_4->setText(VC+" Ваша версия ");
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

//file_copy="Goods_Input.exe";
    if (Flag==0)
    {
      file_copy="Goods_Input.exe";
    }
    if (Flag==1)
    {
      file_copy="RR_Cash_Atol.exe";
    }

 QString   path1=urlPuth+"download/"+file_copy;
  QString   path2=urlPuth+file_copy;
  QString   path3=urlPuth+"arhiv/copy_"+ file_copy;


      qDebug() << path1;
  qDebug() << path2;
   qDebug() << path3;
 QFile MyFile(path1);
 QFile destFile("\1.txt");
 urlPuth=QDir::currentPath()+"/";

// QString executable = QDir::currentPath()+"/"+file_copy;
// QProcess *process = new QProcess(this);
 //process->start(executable, QStringList());

 // some code

// if ( process->state() == QProcess::NotRunning )
 //{
     // do something


//QFile::copy("E:\1.txt", "E:\copy_1.text");


     int FileRaz1=QFile(path3).size();
  qDebug () << FileRaz1;
  if ( QFile::exists(path1))
    {
  QFile(path3).remove();
     QFile::copy(path2, path3);
     bool result1 = QFile::copy(path1, path2);
  if (result1 == true)
  {
     QFile(path3).remove();
  }
    QFile(path2).remove();
     bool result = QFile::copy(path1, path2);
  if (result == true)
  {
     QFile(path1).remove();
   }
     //  QFile::copy(path1, path3);

    qDebug() << result;
    path1=urlPuth+"download/"+file_copy;
       path2=urlPuth+file_copy;
        path3=urlPuth+"arhiv/copy_"+ file_copy;
    qDebug() << path1;
// QFile  MyFile(path1);
       urlPuth=QDir::currentPath()+"/";
      }
   // QString executable = QDir::currentPath()+"/"+file_copy;
   // QProcess *process = new QProcess(this);
    //process->start(executable, QStringList());

    // some code

   // if ( process->state() == QProcess::NotRunning )
    //{
        // do something


   //QFile::copy("E:\1.txt", "E:\copy_1.text");



//};
}

void MainWindow::on_checkBox_clicked()
{
    if(ui->checkBox->isChecked())
    {
    aut=1;
    qDebug() << "Пароль верен";
   ui->pushButton->setEnabled(false);
   ui->pushButton_2->setEnabled(false);
   ui->pushButton_3->setEnabled(false);
   ui->pushButton_4->setEnabled(false);
   ui->pushButton_5->setEnabled(false);
   ui->pushButton_6->setEnabled(false);
   ui->pushButton_7->setEnabled(false);
   ui->pushButton_8->setEnabled(false);
   ui->lineEdit->setEnabled(false);
   ui->lineEdit_2->setEnabled(false);
   ui->lineEdit_3->setEnabled(false);

  // connect(tmr, SIGNAL(timeout()), this, SLOT(on_pushButton_clicked())); // Подключаем сигнал таймера к нашему слоту
  //  connect(tmr, SIGNAL(timeout()), this, SLOT(on_pushButton_3_clicked()));
   //connect(tmr, SIGNAL(timeout()), this, SLOT(on_pushButton_2_clicked()));
          tmr->start();
          tmr1->start();
    }
    else {
       aut=0;
          tmr->stop();
          tmr1->stop();

    }
}

// Процедура обработки обращения к запуску функции загрузки файлоов
void MainWindow::on_pushButton_5_clicked()
{
    QString  path2;
      path2=urlPuth+"download/";
      qDebug() << Flag << " Результат флага";
 // Загружаем Товароучетку ....
      if (Flag==0)
    {
   //  path2=urlPuth+"download/";
      //if (!QFile(mtl_file).exists()) return false
   if (QFile(QDir::currentPath()+"/"+"Goods_Input.exe").exists())
  {       QFile(QDir::currentPath()+"/"+"Goods_Input.exe").close();
          file_copy="Goods_Input.exe";
          urlline="http://cd.oe22.ru/iitron/Goods_Input.exe";
            //+urlFile;
            qDebug() <<   urlline << path2;
    m_downloader.get(path2, urlline);
// connect(ui->pushButton_5, SIGNAL(clicked(urlPuth)), myform, SLOT(GetData(urlPuth)));
    connect (restoreAction, SIGNAL(triggered()), this, SLOT(showNormal()));
    ui->pushButton_4->setEnabled(true);
    messeg *w = new messeg;
    w->show();
      QSqlQuery query;
      QString s1="UPDATE client SET versionclient = '"+VC+"' WHERE id = "+QVariant(id).toString();
    qDebug() << s1;
      query.exec(s1);
      }
    }
  // QTime timer;
   //timer.start () ;

  /* for(;timer.elapsed() < 100000;)
   {
       qApp->processEvents(0);
   }*/
 // Загружаем КК ....
   if (Flag==1)
   {

      if (QFile(QDir::currentPath()+"/"+"RR_Cash_Atol.exe").exists())
   {      QFile(QDir::currentPath()+"/"+"RR_Cash_Atol.exe").close();
          file_copy="RR_Cash_Atol.exe";
          urlline="http://cd.oe22.ru/iitron/RR_Cash_Atol.exe";
            //+urlFile;
            qDebug() <<   urlline << path2 << "ГДЕ!!!!!";
    m_downloader.get(path2, urlline);
// connect(ui->pushButton_5, SIGNAL(clicked(urlPuth)), myform, SLOT(GetData(urlPuth)));
    connect (restoreAction, SIGNAL(triggered()), this, SLOT(showNormal()));
    ui->pushButton_4->setEnabled(true);
    messeg *w = new messeg;
    w->show();
      QSqlQuery query;
      QString s1="UPDATE client SET versionserv = '"+VC+"' WHERE id = "+QVariant(id).toString();
    qDebug() << s1;
      query.exec(s1);
      }
}
 // query.exec("UPDATE client SET versionclient = '102' WHERE id = 84");
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

void MainWindow::on_lineEdit_4_returnPressed()
{
if (ui->lineEdit_4->text()=="12345")
{
    qDebug() << "Пароль верен";
   ui->pushButton->setEnabled(true);
   ui->pushButton_2->setEnabled(true);
   ui->pushButton_3->setEnabled(true);
   ui->pushButton_4->setEnabled(true);
   ui->pushButton_5->setEnabled(true);
   ui->pushButton_6->setEnabled(true);
   ui->pushButton_7->setEnabled(true);
   ui->pushButton_8->setEnabled(true);
   ui->lineEdit->setEnabled(true);
   ui->lineEdit_2->setEnabled(true);
   ui->lineEdit_3->setEnabled(true);
}
else if (ui->lineEdit_4->text()=="11111")
{
    ui->pushButton_8->setEnabled(true);
}

}
