#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql/QSqlDriver>
#include <QtSql/QSqlTableModel>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QtSql>
#include <QCloseEvent>
#include <QSystemTrayIcon>
#include <QAction>
#include "Downloader.h"
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkInterface>
#include<messeg.h>
extern QString Version;
//extern QString urlPuth;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
   QSqlDatabase       db;
   int Flag;
   int aut;
 //   QSqlTableModel  *model;
      QString urlline;
      QString urlFile;
      QString urlPuth,VC,file_copy;
   protected:
    /* Виртуальная функция родительского класса в нашем классе
     * переопределяется для изменения поведения приложения,
     *  чтобы оно сворачивалось в трей, когда мы этого хотим
     */


private slots:
    void on_pushButton_clicked();
    void showHide(QSystemTrayIcon::ActivationReason);
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
// Для трея
       void changeEvent(QEvent*);
       void trayIconActivated(QSystemTrayIcon::ActivationReason reason);
       void trayActionExecute();
       void setTrayIconActions();
       void showTrayIcon();
       void on_pushButton_4_clicked();

       void on_checkBox_clicked();

       void on_pushButton_5_clicked();

       void on_pushButton_6_clicked();

       void on_pushButton_7_clicked();

       void on_lineEdit_4_returnPressed();

private:
    Ui::MainWindow *ui;
    QTimer *tmr;
    QTimer *tmr1;
     Downloader m_downloader;
       // Для трея
        QSystemTrayIcon *trayIcon;
        QMenu *trayIconMenu;
        QAction *minimizeAction;
        QAction *restoreAction;
        QAction *quitAction;

         QSettings *settings = new QSettings("settings.conf",QSettings::IniFormat);
          int FileRaz1,id;
          int FileRaz2;
           messeg *myform;
};

#endif // MAINWINDOW_H
