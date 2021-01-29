#include "avlnode.h"

AVLNode::AVLNode()
{
    password=account="";
}

AVLNode::AVLNode(const AVLNode &i)
{
    account=i.account;
    password=i.password;
}
AVLNode::AVLNode(QString _account,QString _password){
    account=_account;
    password=_password;
}
bool AVLNode::operator<(AVLNode right)
{
    return account<right.account;
}

bool AVLNode::operator>(AVLNode right)
{
    return account>right.account;
}

bool AVLNode::operator==(AVLNode right)
{
    return account==right.account&&password==right.password;
}

QString AVLNode::toString()
{
    return account+"\n"+password+"\n";
}

void AVLNode::reSet(AVLNode item)
{
    this->account=item.account;
    this->password=item.password;
}

bool AVLNode::isEmpty()
{
    return account==""&&password=="";
}
