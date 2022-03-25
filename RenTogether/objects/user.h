#ifndef USER_H
#define USER_H
#include <string>

using namespace std;

class User
{

private:
    string username;
    string password;

public:
    User(string username, string password);
    const string &getUsername() const;
    void setUsername(const string &newUsername);
};

#endif // USER_H
