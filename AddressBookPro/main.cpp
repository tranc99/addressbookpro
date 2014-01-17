#include <QCoreApplication>
#include "addressbook.h"
#include<QtGui>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //QMainW
    AddressBook addressBook;
    addressBook.show();

    return a.exec();
}
