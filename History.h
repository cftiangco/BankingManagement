#ifndef HISTORY_H
#define HISTORY_H
#include<string.h>
#include<string>
#include<stdio.h>

using namespace std;

class History
{
    public:
        History();
        History(string transaction, long amount,string customer_id,string username);
        void create();
        void display(string id);
        void display();
        bool findOne(string id);
        string generateTransactionID();
        string TimeStamp();
    protected:

    private:
        string _transaction;
        long _amount;
        string _date;
        string _username;
        string _customer_id;
};

#endif // HISTORY_H
