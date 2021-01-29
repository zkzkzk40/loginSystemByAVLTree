#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>
#include <avlnode.h>
#include <avltree.h>
QT_BEGIN_NAMESPACE
namespace Ui { class loginWindow; }
QT_END_NAMESPACE

class loginWindow : public QMainWindow
{
    Q_OBJECT

public:
    loginWindow(QWidget *parent = nullptr);
    ~loginWindow();

private slots:
    void on_loginBtn_clicked();

    void on_registerBtn_clicked();

    void on_modifyBtn_clicked();

    void on_removeBtn_clicked();

private:
    const QString PATH=".\\test.txt";
    AVLtree<AVLNode> avl;
    AVLNode temp;
    Ui::loginWindow *ui;
};
#endif // LOGINWINDOW_H
