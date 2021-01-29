#pragma once
#include <cstring>
#include <QDebug>
#include <QFile>
#include <iostream>
#include <QTextStream>
#include <QQueue>
using namespace std;
template <class Data>
class AVLtree
{
private:
    class node {
    public:
        Data data;
        node* left, * right, * parent;
        short int balance;//平衡因子
        node(Data d) { data = d; balance = 0; left = right = parent = nullptr; }
    };
    node* root;
    int getHeight(node* theRoot);//求高度
    void inorderAux(node* theRoot,QTextStream txtOutput);//中序遍历
    void LL(node* parent);//左单旋
    void RR(node* parent);//右单旋
    void LR(node* parent);//左右旋
    void RL(node* parent);//右左旋

public:
    AVLtree() { root = nullptr; };
    bool insert(Data item);//插入节点
    Data search(Data item);//查找节点
    void inOrderWrite(QString path);//层次遍历写入文件
    bool remove(Data item);//删除节点
    bool reSetData(Data item);//重新设置节点值
    void readTxt(QString path);//读取文件
};

template <class Data>
bool AVLtree<Data>::insert(Data item) {
    if (!root) {//树空
        root = new node(item);
        return true;
    }
    node* p = root,
        * Parent = nullptr;
    while (p) {//找到插入位置
        Parent = p;
        if (item < p->data) {
            p = p->left;
        }
        else if (item > p->data) {
            p = p->right;
        }
        else return false;
    }
    p = new node(item);
    if (item < Parent->data) {
        Parent->left = p;
    }
    else {
        Parent->right = p;
    }
    p->parent = Parent;

    //重新测试平衡因子并且只需左右旋等等
    while (Parent) {
        if (p == Parent->left) {
            Parent->balance++;
        }
        else if (p == Parent->right) {
            Parent->balance--;
        }

        if (!Parent->balance) {//插入后树平衡
            break;
        }
        else if (Parent->balance == 1 || Parent->balance == -1) {
            p = p->parent;
            Parent = p->parent;
        }
        else {//balance=2||-2
            int Banlance = (Parent->balance > 0 ? 1 : -1);
            if (Banlance == p->balance) {//相同即只需单旋
                if (Banlance == 1)//节点在左边,需要右旋
                    RR(Parent);
                else LL(Parent);
            }
            else {//不同则需双旋
                if (Banlance == 1)//加入的节点在左边
                    LR(Parent);
                else RL(Parent);
            }
            break;
        }
    }
    return true;
}


template<class Data>
int AVLtree<Data>::getHeight(node* theRoot) {
    if (!theRoot) return 0;
    int leftHeight = getHeight(theRoot->left);
    int rightHeith = getHeight(theRoot->right);
    return leftHeight > rightHeith ? leftHeight + 1 : rightHeith + 1;
}

template<class Data>
void AVLtree<Data>::inorderAux(AVLtree::node* theRoot,QTextStream txtOutput)
{
    if (theRoot) {
        inorderAux(theRoot->left);
        txtOutput << theRoot->data.toString();
        inorderAux(theRoot->right);
    }
}

template<class Data>
void AVLtree<Data>::LL(node* parent) {
    node* subR = parent->right;
    node* subR_L = subR->left;
    parent->right = subR_L;
    if (subR_L) {//subR_L非空
        subR_L->parent = parent;
    }
    subR->left = parent;
    //改变parent的父亲节点,Pparent是parent的父节点
    node* Pparent = parent->parent;
    parent->parent = subR;
    subR->parent = Pparent;

    //修改parent的父亲节点指向
    if (!Pparent) {//即改变了根节点
        root = subR;
    }
    else if (Pparent->left == parent) {
        Pparent->left = subR;
    }
    else {
        Pparent->right = subR;
    }
    subR->balance = 0;
    parent->balance = 0;
}

template<class Data>
void AVLtree<Data>::RR(node* parent) {
    node* subR = parent->left;
    node* subR_L = subR->right;
    parent->left = subR_L;
    if (subR_L) {//subR_L非空
        subR_L->parent = parent;
    }
    subR->right = parent;

    //改变parent的父亲节点,Pparent是parent的父节点
    node* Pparent = parent->parent;
    parent->parent = subR;
    subR->parent = Pparent;

    //修改parent的父亲节点指向
    if (!Pparent) {//即改变了根节点
        root = subR;
    }
    else if (Pparent->left == parent) {
        Pparent->left = subR;
    }
    else {
        Pparent->right = subR;
    }
    subR->balance = 0;
    parent->balance = 0;
}

template<class Data>
void AVLtree<Data>::LR(node* parent) {
    LL(parent->left);
    RR(parent);
}

template<class Data>
void AVLtree<Data>::RL(node* parent) {
    RR(parent->right);
    LL(parent);

}

template<class Data>
Data AVLtree<Data>::search(Data item)
{
    node* p=root;
    while(p){
        if(item<p->data){
            p=p->left;
        }
        else if(item>p->data){
            p=p->right;
        }
        else {
            if(item==p->data) return p->data;
            else return  Data() ;
        }
    }
    return Data() ;
}

template<class Data>
void AVLtree<Data>::inOrderWrite(QString path) {
    QFile f(path);
    if(!f.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "Open failed." << "\n";
        return ;
    }
    QTextStream txtOutput(&f);
    QQueue<node*> q;
    q.clear();
    node* p=root;
    while(p){
        txtOutput<<p->data.toString();
        if(p->left)
            q.enqueue(p->left);
        if(p->right)
            q.enqueue(p->right);
        if(q.isEmpty()){
            return;
        }
        p=q.head();
        q.pop_front();
    }
    f.close();
}

template<class Data>
bool AVLtree<Data>::remove(Data item)
{
    if(!root){//空树
        return false;
    }
    //下面这段代码参考课本BST树的删除
    bool find=false;
    node* x=root,*parent=nullptr;
    while(!find&&x){
        if(item<x->data){
            parent=x;
            x=x->left;
        }
        else if(item>x->data){
            parent=x;
            x=x->right;
        }
        else find=true;
    }
    if(!find){
        return false;
    }
    if(x->left&&x->right){
        node* xSucc=x->right;
        parent=x;
        while(xSucc->left){
            parent=x;
            xSucc=xSucc->left;
        }
        x->data=xSucc->data;
        x=xSucc;
    }

    //处理子女不超过1的情况
    node* subtree=x->left;// subtree指向x的子树
    if(!subtree) subtree=x->right;
    if(!parent) root=subtree;//删除根
    else if(parent->left==x){//删除节点在父节点的左子树上
        parent->left=subtree;
        if(subtree) subtree->parent=parent;//更新父节点
        parent->balance--;
    }
    else{//删除节点在父节点的右子树上
        parent->right=subtree;
        if(subtree) subtree->parent=parent;//更新父节点
        parent->balance++;
    }
    delete x;

    //开始更新平衡因子和进行左右旋操作
    //步骤参考插入函数的操作
    while(parent){
        if(parent->left==subtree){
            parent->balance--;
        }
        else {
            parent->balance++;
        }
        // 平衡因子=+-1,表明原树平衡因子为0,不需要操作
        if(parent->balance==1||parent->balance==-1)
            break;
        //平衡因子=0,需要往前遍历检查父节点
        else if(parent->balance==0){
             subtree=parent;
             parent=parent->parent;
        }
        //平衡因子=+-2,需要进行四种操作
        else {
            node* temp;
             if(parent->balance==2){//对应左子树高
                 temp=parent->left;
                 if(temp->balance==0){
                     RR(parent);
                     parent->balance=-1;//右旋后,改变平衡因子
                     parent=parent->parent;//更新parent节点指向
                     parent->balance=1;
                     break;
                 }
                 else if(temp->balance==1){
                     RR(parent);
                     parent=parent->parent;
                 }
                 else {
                     LL(parent);
                     parent=parent->parent;
                 }
             }
             else {//对应右子树高
                 temp=parent->right;
                 if(temp->balance==0){//右子树平衡
                      LL(parent);
                      parent->balance=-1;//左旋后,改变平衡因子
                      parent=parent->parent;//更新parent节点指向
                      parent->balance=1;
                      break;
                 }
                 else if(temp->balance==-1){
                     LL(parent);
                     parent=parent->parent;
                 }
                 else {
                     RL(parent);
                     parent=parent->parent;
                 }
             }
             //更新parent指向,向上遍历
             subtree=parent;
             parent=parent->parent;
        }
    }
    return true;
}

template<class Data>
bool AVLtree<Data>::reSetData(Data item)
{
    node* p=root;
    while(p){
        if(item<p->data){
            p=p->left;
        }
        else if(item>p->data){
            p=p->right;
        }
        else {
            p->data.reSet(item);
            return true;
        }
    }
    return false;
}

template<class Data>
void AVLtree<Data>::readTxt(QString path)
{
    QFile f(path);
    if(!f.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Open failed." ;
        return ;
    }

    QTextStream txtInput(&f);
    QString lineAccount,linePassword;
    while(!txtInput.atEnd())
    {
        lineAccount = txtInput.readLine();
        linePassword = txtInput.readLine();
        this->insert(Data(lineAccount,linePassword));
    }

    f.close();
}


