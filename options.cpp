#include "options.h"
#include "ui_options.h"
#include "bank.h"
#include "bankserver.h"
#include "deposit.h"
#include "editprofile.h"
#include "editpasswd.h"
#include "withdraw.h"
#include<QMessageBox>
#include <QDebug>
#include<time.h>

extern bankServer bankserver;

options::options(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::options)
{
    ui->setupUi(this);
}

options::~options()
{
    delete ui;
}

void options::on_options_logoutButton_clicked()
{
    switch(QMessageBox::critical(this, tr("警告"), tr("确认注销吗?"), tr("确认"), tr("取消"), 0, 1))
    {
        case 0:
            bank *bank_windows;
            bank_windows = new bank();
            bank_windows->show();
            this->close();
            break;
        default:
            break;
    }
}

void options::on_options_depositButton_clicked()
{
    deposit *deposit_windows;
    deposit_windows = new deposit();
    deposit_windows->show();
    this->close();
}

void options::on_options_changeButton_clicked()
{
    editprofile *editprofile_windows;
    editprofile_windows = new editprofile();
    editprofile_windows->show();
    this->close();
    delete this;
}

void options::on_options_passwdButton_clicked()
{
    editpasswd *editpasswd_windows;
    editpasswd_windows = new editpasswd();
    editpasswd_windows->show();
    this->close();
    delete this;
}

void options::on_options_lostButton_clicked()
{
    int result=QMessageBox::warning(this, tr(""), tr("确认挂失吗？"), tr("确认"), tr("返回"),0,1);
    switch(result)
    {
        case 0:
            time_t tCurrentTime=time(NULL);
            bankserver.ReportLost(tCurrentTime);
            QMessageBox::information(this, tr(""), tr("账户已挂失！"), tr("确认"), 0);
            bank *bank_windows;
            bank_windows = new bank();
            bank_windows->show();
            this->close();
            break;
    }
}

void options::on_options_withdrawButton_clicked()
{
    withdraw *withdraw_windows;
    withdraw_windows = new withdraw();
    withdraw_windows->show();
    this->close();
}
