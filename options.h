/************************************************************************
 * Copyright (C) 2021 Chenyang https://wcy-dt.github.io                 *
 *                                                                      *
 * @file     options.h                                                  *
 * @brief    page for choosing option for the account                   *
 * @author   Chenyang                                                   *
 * @date     2021 - 07                                                  *
 ************************************************************************/

#ifndef OPTIONS_H
#define OPTIONS_H

#include <QDialog>

namespace Ui
{
    class options;
}

class options : public QDialog
{
    Q_OBJECT

public:
    explicit options(QWidget *parent = nullptr);
    ~options();

private slots:
    void on_options_logoutButton_clicked();

    void on_options_depositButton_clicked();

    void on_options_changeButton_clicked();

    void on_options_passwdButton_clicked();

    void on_options_lostButton_clicked();

    void on_options_withdrawButton_clicked();

    void on_options_flowButton_clicked();

private:
    Ui::options *ui;
};

#endif // OPTIONS_H
