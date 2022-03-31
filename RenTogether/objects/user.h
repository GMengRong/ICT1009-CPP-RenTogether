#ifndef USER_H
#define USER_H

#include <string>
#include <QString>

using namespace std;

class User
{

private:
    QString username;
    QString password;

public:
    User(QString, QString);

    const QString &getUsername() const;
    void setUsername(const QString &newUsername);

    const QString &getPassword() const;
    void setPassword(const QString &newPassword);

    void printUser();
};

#endif // USER_H
