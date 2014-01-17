#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H
#include <QWidget>
#include <QtGui>
#include <QMap>

class AddressBook : public QWidget
{
    Q_OBJECT

public:
    AddressBook(QWidget *parent = 0);


private:
    QPushButton *addButton;
    QPushButton *submitButton;
    QPushButton *cancelButton;
    QLineEdit *nameLine;
    QTextEdit *addressText;

    QMap<QString, QString> contacts;
    QString oldName;
    QString oldAddress;

public slots:
    void addContact();
    void submitContact();
    void cancel();



};




#endif // ADDRESSBOOK_H
