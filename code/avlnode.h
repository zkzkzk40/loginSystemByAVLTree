#ifndef AVLNODE_H
#define AVLNODE_H
#include <QString>

class AVLNode
{

public:
    QString account,password;
    AVLNode();
    AVLNode(AVLNode const &i);
    AVLNode(QString _account,QString _password);
    bool operator<(AVLNode right);
    bool operator>(AVLNode right);
    bool operator==(AVLNode right);
    QString toString();
    void reSet(AVLNode);
    bool isEmpty();
};





#endif // AVLNODE_H
