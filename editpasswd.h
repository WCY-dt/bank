/************************************************************************
 * Copyright (C) 2021 Chenyang https://wcy-dt.github.io                 *
 *                                                                      *
 * @file     editpasswd.h                                               *
 * @brief    page for editing password                                  *
 * @author   Chenyang                                                   *
 * @date     2021 - 07                                                  *
 ************************************************************************/

#ifndef EDITPASSWD_H
#define EDITPASSWD_H

#include <QDialog>

namespace Ui
{
    class editpasswd;
}

class editpasswd : public QDialog
{
    Q_OBJECT

public:
    explicit editpasswd(QWidget *parent = nullptr);
    ~editpasswd();

private slots:
    void on_login_backButton_clicked();

    void on_login_okButton_clicked();

    void on_login_passwdInput_textEdited(const QString &arg1);

    void on_login_confirmPasswdInput_textEdited(const QString &arg1);

private:
    Ui::editpasswd *ui;
};

#endif // EDITPASSWD_H
