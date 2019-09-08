#ifndef CUSTOMER_H
#define CUSTOMER_H
#include<string>
#include "History.h"

using namespace std;

class Customer : public History
{
    public:
        Customer();
        Customer(string fullname,string dateOfBirth,string address,string contact,string amount);
        string getID();
        string id;
        string fullname;
        string dateOfBirth;
        string address;
        string contact;
        string amount;
        void create();
        void display();
        //void findOne(long id);
        bool findOne(string id);
        bool update(string id,string address,string contact);
        bool destory(string id);
        void withdraw(string id,long amount);
        void desposit(string id, long amount);
        long getTotalDeposite(string id);
        void reciept(string customerId,string transactionType,string typeText,int amount);
    protected:

    private:
};

#endif // CUSTOMER_H
