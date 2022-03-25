#include "user.h"

User::User(string username, string password)
{
    this->username = username;
    this->password = password;
}

const string &User::getUsername() const
{
    return username;
}

void User::setUsername(const string &newUsername)
{
    username = newUsername;
}
