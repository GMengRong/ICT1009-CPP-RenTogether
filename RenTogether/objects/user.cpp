#include "user.h"
#include <QDebug>

User::User(QString username, QString password)
{
    this->username = username;
    this->password = password;
}

const QString &User::getUsername() const
{
    return username;
}

void User::setUsername(const QString &newUsername)
{
    username = newUsername;
}

const QString &User::getPassword() const
{
    return password;
}

void User::setPassword(const QString &newPassword)
{
    password = newPassword;
}

void User::printUser()
{
    qDebug() << username << " " << password;
}
