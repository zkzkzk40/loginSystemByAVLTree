#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "avlnode.h"
#include "avltree.h"
#include <QMessageBox>
loginWindow::loginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::loginWindow)
{
    avl.readTxt(PATH);
    ui->setupUi(this);

}

loginWindow::~loginWindow()
{
    delete ui;
}


void loginWindow::on_loginBtn_clicked()
{
    QString account=ui->accountLineEdit->text(),
            password=ui->passwordLineEdit->text();
    if(account==""||password==""){
        QMessageBox::about(this,"错误","请输入账号密码");
        return;
    }
    temp=avl.search(AVLNode(account,password));
    if(!temp.isEmpty()){
        QMessageBox::about(this,"登录成功","登录成功");
    }
    else {
        QMessageBox::about(this,"登录失败","登录失败");
        return;
    }
}

void loginWindow::on_registerBtn_clicked()
{
    QString account=ui->accountLineEdit->text(),
            password=ui->passwordLineEdit->text();
    if(account==""||password==""){
        QMessageBox::about(this,"错误","请输入账号密码");
        return;
    }
    bool find=avl.insert(AVLNode(account,password));
    if(find){
        QMessageBox::about(this,"注册成功","注册成功");
        avl.inOrderWrite(PATH);
    }
    else {
        QMessageBox::about(this,"注册失败","已有该账号");
    }
}

void loginWindow::on_modifyBtn_clicked()
{
    QString account=ui->accountLineEdit->text(),
            password=ui->passwordLineEdit->text();
    if(account==""||password==""){
        QMessageBox::about(this,"错误","请输入账号密码");
        return;
    }
    if(!temp.isEmpty()){
        bool flag=avl.reSetData(AVLNode(account,password));
         if(flag){
             QMessageBox::about(this,"修改成功","修改成功");
             avl.inOrderWrite(PATH);
         }
         else{
             QMessageBox::about(this,"失败","不能修改账号");
         }
    }
    else {
        QMessageBox::about(this,"错误","请先登录");
    }

}

void loginWindow::on_removeBtn_clicked()
{
    QString account=ui->accountLineEdit->text(),
            password=ui->passwordLineEdit->text();
    if(account==""||password==""){
        QMessageBox::about(this,"错误","请输入账号密码");
        return;
    }
    if(!temp.isEmpty()){
        bool flag=avl.remove(temp);
         if(flag){
             QMessageBox::about(this,"修改成功","成功注销账号:"+temp.account);
             avl.inOrderWrite(PATH);
         }
         else{
             QMessageBox::about(this,"失败","账号已注销");
         }
    }
    else {
        QMessageBox::about(this,"错误","请先登录");
    }
}
