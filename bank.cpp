#include "bank.h"
#include "bankserver.h"
#include "ui_bank.h"
#include "login.h"
#include "createaccount.h"
#include<QDialog>
#include<QMessageBox>
#include <QString>
#include <QDebug>

extern bankServer bankserver;

bank::bank(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::bank)
{
    ui->setupUi(this);
}

bank::~bank()
{
    delete ui;
}


void bank::on_loginButton_clicked()
{
    login *login_windows;
    login_windows = new login();
    login_windows->show();
    this->close();
}

void bank::on_createAccountButton_clicked()
{
    createaccount *createaccount_windows;
    createaccount_windows = new createaccount();
    createaccount_windows->show();
    this->close();
}

void bank::on_exitButton_clicked()
{
    switch(QMessageBox::critical(this, tr("警告"), tr("确认退出系统吗?"), tr("确认"), tr("取消"), 0, 1))
    {
        case 0:
            this->close();
            break;
        default:
            break;
    }
}