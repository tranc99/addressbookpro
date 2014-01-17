#include "addressbook.h"
#include<QtGui>
#include<QString>

AddressBook::AddressBook(QWidget *parent) : QWidget(parent)
{
    QLabel *nameLabel = new QLabel(tr("Name:"));
    nameLine = new QLineEdit;
    nameLabel->show();
    //qApp->

    QLabel *addressLabel = new QLabel(tr("Address:"));
    addressText = new QTextEdit;

    nameLine->setReadOnly(true);

    addressText->setReadOnly(true);

    addButton = new QPushButton(tr("&Add"));
    addButton->show();
    submitButton = new QPushButton(tr("&Submit"));
    submitButton->hide();
    cancelButton = new QPushButton(tr("&Cancel"));
    cancelButton->hide();


    //connect using signals and slots, set up to invoke certain functionality
    connect(addButton, SIGNAL(clicked()), this, SLOT(addContact()));
    connect(submitButton, SIGNAL(clicked()), this, SLOT(submitContact()));
    connect(cancelButton, SIGNAL(clicked()), this, SLOT(cancel()));

    QVBoxLayout *buttonLayout1 = new QVBoxLayout;
    buttonLayout1->addWidget(addButton, Qt::AlignTop);
    buttonLayout1->addWidget(submitButton);
    buttonLayout1->addWidget(cancelButton);
    buttonLayout1->addStretch();

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(nameLabel, 0, 0);
    mainLayout->addWidget(nameLine, 0, 1);
    mainLayout->addWidget(addressLabel, 1, 0, Qt::AlignTop);
    mainLayout->addWidget(addressText, 1, 1);
    mainLayout->addLayout(buttonLayout1, 1, 2);



    setLayout(mainLayout);
    setWindowTitle(tr("Tristram's Address Book"));




}

void AddressBook::addContact()
{
    oldName = nameLine->text();
    oldAddress = addressText->toPlainText();

    nameLine->clear();
    addressText->clear();

    nameLine->setReadOnly(false);
    nameLine->setFocus(Qt::OtherFocusReason);
    addressText->setReadOnly(false);

    addButton->setEnabled(false);
    submitButton->show();
    cancelButton->show();

}

void AddressBook::submitContact()
{
    QString name = nameLine->text();
    QString address = addressText->toPlainText();

    if(name.isEmpty() || address.isEmpty())
    {
        QMessageBox::information(this, tr("Empty Field"),
                                 tr("Please enter a name and address."));
        return;
    }

    //check if the contact already exists i.e. this contact is a duplicate
    if(!contacts.contains(name))
    {
        contacts.insert(name, address);
        QMessageBox::information(this, tr("Contact added successfully"), tr("\"%1\" has been added to your contacts").arg(name));
    } else {
        QMessageBox::information(this, tr("Unsuccessful"),
                                 tr("\"%1\" is already in your contacts.").arg(name));
        return;
    }

    if (contacts.isEmpty()) {
        nameLine->clear();
        addressText->clear();
    }

    nameLine->setReadOnly(true);
    addressText->setReadOnly(true);
    addButton->setEnabled(true);
    submitButton->hide();
    cancelButton->hide();

}

void AddressBook::cancel()
{
    nameLine->setText(oldName);
    nameLine->setReadOnly(true);

    addressText->setText(oldAddress);
    addressText->setReadOnly(true);

    addButton->setEnabled(true);
    submitButton->hide();
    cancelButton->hide();
}
