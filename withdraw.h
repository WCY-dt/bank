#ifndef WITHDRAW_H
#define WITHDRAW_H

#include <QDialog>

namespace Ui
{
    class withdraw;
}

class withdraw : public QDialog
{
    Q_OBJECT

public:
    explicit withdraw(QWidget *parent = nullptr);
    ~withdraw();

private slots:
    void on_deposit_backButton_clicked();

    void on_deposit_okButton_clicked();

private:
    Ui::withdraw *ui;
};

#endif // WITHDRAW_H
