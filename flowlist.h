#ifndef FLOWLIST_H
#define FLOWLIST_H

#include <QDialog>

namespace Ui
{
    class flowlist;
}

class flowlist : public QDialog
{
    Q_OBJECT

public:
    explicit flowlist(QWidget *parent = nullptr);
    ~flowlist();

private slots:
    void on_accountlist_backButton_clicked();

    void on_accountlist_searchEdit_textChanged(const QString &arg1);

    void on_accountlist_exportButton_clicked();

private:
    Ui::flowlist *ui;

    void SetDefault();
};

#endif // FLOWLIST_H
