#ifndef DEPOSIT_H
#define DEPOSIT_H

#include <QDialog>

namespace Ui
{
    class deposit;
}

class deposit : public QDialog
{
    Q_OBJECT

public:
    explicit deposit(QWidget *parent = nullptr);
    ~deposit();

private slots:
    void on_deposit_okButton_clicked();

    void on_deposit_backButton_clicked();

private:
    Ui::deposit *ui;
};

#endif // DEPOSIT_H
