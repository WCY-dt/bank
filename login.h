#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>

namespace Ui
{
    class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();

private slots:
    void on_login_okButton_clicked();

    void on_login_backButton_clicked();

    void on_login_accountInput_textChanged(const QString &arg1);

private:
    Ui::login *ui;
};

#endif // LOGIN_H
