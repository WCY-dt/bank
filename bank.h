#ifndef BANK_H
#define BANK_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class bank; }
QT_END_NAMESPACE

class bank : public QMainWindow
{
    Q_OBJECT

public:
    bank(QWidget *parent = nullptr);
    ~bank();

private slots:
    void on_loginButton_clicked();

    void on_createAccountButton_clicked();

    void on_exitButton_clicked();

private:
    Ui::bank *ui;
};
#endif // BANK_H
