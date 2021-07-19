#include "withdraw.h"
#include "ui_withdraw.h"
#include"options.h"
#include "bankserver.h"
#include<QMessageBox>
#include<QPlainTextEdit>
#include <QDebug>

extern bankServer bankserver;

withdraw::withdraw(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::withdraw)
{
    ui->setupUi(this);
    ui->deposit_moneyInput->setText("0");
    ui->deposit_moneyInput->setFocus();
}

withdraw::~withdraw()
{
    delete ui;
}

void withdraw::on_deposit_backButton_clicked()
{
    options *options_windows;
    options_windows = new options();
    options_windows->show();
    this->close();
}

void withdraw::on_deposit_okButton_clicked()
{
    switch(QMessageBox::warning(this, NULL,
                                tr("确认取出")+(ui->deposit_moneyInput->text())+tr("元吗?"),
                                tr("确认"), tr("取消"), 0, 1))
    {
        case 0:
            if(bankserver.Withdraw((ui->deposit_moneyInput->text()).toDouble(),
                               (ui->login_employeeInput->text()).toStdString()))
            {
            QMessageBox::information(this, NULL,
                                 tr("成功存入")+(ui->deposit_moneyInput->text())+tr("元！"),
                                 tr("确认"));
            options *options_windows;
            options_windows = new options();
            options_windows->show();
            this->close();
            }
            else
            {
                ui->deposit_moneyInput->setText("0");
                ui->deposit_moneyInput->setFocus();
                QMessageBox::information(this, NULL,tr("余额不足！"),tr("确认"));
            }
            break;
    }
}
