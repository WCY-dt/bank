/************************************************************************
 * Copyright (C) 2021 Chenyang https://wcy-dt.github.io                 *
 *                                                                      *
 * @file     editprofile.h                                              *
 * @brief    page for editing profile                                   *
 * @author   Chenyang                                                   *
 * @date     2021 - 07                                                  *
 ************************************************************************/

#ifndef EDITPROFILE_H
#define EDITPROFILE_H

#include <QDialog>

namespace Ui
{
    class editprofile;
}

class editprofile : public QDialog
{
    Q_OBJECT

public:
    explicit editprofile(QWidget *parent = nullptr);
    ~editprofile();

private slots:
    void on_login_typeCombobox_currentIndexChanged(int index);

    void on_login_backButton_clicked();

    void on_login_okButton_clicked();

private:
    Ui::editprofile *ui;
};

#endif // EDITPROFILE_H
