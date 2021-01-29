#include "loginwindow.h"

#include <QApplication>
#include "avlnode.h"
#include "avltree.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    loginWindow w;
    w.show();

    return a.exec();
}
