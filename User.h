#ifndef USER_H
#define USER_H
#include<string>

using namespace std;

class User
{
    public:
        User();
        User(string uname,string pword);
        bool login();
        bool checkUserIfExists(string username);
        void create();
        void display();
        void update(string id,string value);
        void destroy(string username);
        bool findOne(string username);
    protected:

    private:
        string _username;
        string _password;
};

#endif // USER_H
