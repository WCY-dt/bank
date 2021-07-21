#ifndef ACCOUNTLIST_H
#define ACCOUNTLIST_H

#include <QDialog>

namespace Ui {
class accountlist;
}

class accountlist : public QDialog
{
    Q_OBJECT

public:
    explicit accountlist(QWidget *parent = nullptr);
    ~accountlist();

private slots:
    void on_accountlist_backButton_clicked();

    void on_accountlist_searchEdit_textChanged(const QString &arg1);

    void on_dateEdit_dateChanged(const QDate &date);

private:
    Ui::accountlist *ui;

    void SetDefault();
};

#endif // ACCOUNTLIST_H
