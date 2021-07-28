/************************************************************************
 * Copyright (C) 2021 Chenyang https://wcy-dt.github.io                 *
 *                                                                      *
 * @file     creataccount.h                                             *
 * @brief    page for creating accout                                   *
 * @author   Chenyang                                                   *
 * @date     2021 - 07                                                  *
 ************************************************************************/

#ifndef CREATEACCOUNT_H
#define CREATEACCOUNT_H

#include <QDialog>

namespace Ui
{
    class createaccount;
}

class createaccount : public QDialog
{
    Q_OBJECT

public:
    explicit createaccount(QWidget *parent = nullptr);
    ~createaccount();

private slots:
    void on_login_backButton_clicked();

    void on_login_okButton_clicked();

    void on_login_confirmPasswdInput_textEdited(const QString &arg1);

    void on_login_typeCombobox_currentIndexChanged(int index);

    void on_login_passwdInput_textEdited(const QString &arg1);

private:
    Ui::createaccount *ui;
};

#endif // CREATEACCOUNT_H
