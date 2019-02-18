#ifndef MESSEG_H
#define MESSEG_H

#include <QWidget>

namespace Ui {
class messeg;
}

class messeg : public QWidget
{
    Q_OBJECT

public:
    explicit messeg(QWidget *parent = nullptr);
    ~messeg();

private slots:
    void on_pushButton_clicked();
public slots:
    void getData(QString data);
private:
    Ui::messeg *ui;
    QString urlPuth;
};

#endif // MESSEG_H
