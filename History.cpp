#include "History.h"
#include<fstream>
#include<iostream>
#include<sstream>
#include<ctime>
#include<algorithm>


string History::TimeStamp()
{
    time_t rawtime;
    struct tm * timeinfo;
    char buffer[80];

    time (&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(buffer,sizeof(buffer),"%d-%m-%Y %H:%M:%S",timeinfo);
    std::string str(buffer);

    return str;
}

string History::generateTransactionID()
{
    time_t now = time(0);
    ostringstream ss;

    ss<<now;
    return "TRANSAC_" + ss.str();
}

string spaceToUnderscoreDateTime(string str)
{
    replace(str.begin(),str.end(),' ','_');
    return str;
}

string underscore2SpaceDateTime(string str)
{
    replace(str.begin(),str.end(),'_',' ');
    return str;
}

History::History()
{
    //ctor
}

History::History(string transaction, long amount,string customer_id, string username)
{
    this->_transaction = transaction;
    this->_amount = amount;
    this->_date = TimeStamp();
    this->_username = username;
    this->_customer_id = customer_id;
}

void History::create()
{
    ofstream myfile("history.txt", ios::out | ios::app | ios::binary);

    if(myfile.is_open())
    {
        myfile<<generateTransactionID()<<" "<<this->_transaction<<" "<<this->_amount<<" "<<spaceToUnderscoreDateTime(this->_date)<<" "<<this->_customer_id<<" "<<this->_username<<endl;
        myfile.close();
    }
}

void History::display(string id)
{
    ifstream myfile("history.txt");
    string tempTransaction;
    long tempAmount;
    string tempDateTime;
    string tempCustomerId;
    string tempUsername;
    string tempTransactionId;

    if(myfile.is_open())
    {
            cout<<"                                              **** TRANSACTION HISTORY ***** "<<endl;
            cout<<"                                   TRANSACTION ID |   TYPE   | AMOUNT  |  DATE & TIME   |   USER"<<endl;
        while(myfile>>tempTransactionId>>tempTransaction>>tempAmount>>tempDateTime>>tempCustomerId>>tempUsername)
        {
            if(id == tempCustomerId)
            {
                cout<<"                               "<<tempTransactionId<<" | "<<tempTransaction<<" | "<<tempAmount<<" | "<<underscore2SpaceDateTime(tempDateTime)<<" | "<<tempUsername<<endl;
            }
        }
    }
    else
    {
        cout<<"The file is currently in used"<<endl;
    }
}

void History::display()
{
    ifstream myfile("history.txt");
    string tempTransaction;
    long tempAmount;
    string tempDateTime;
    string tempCustomerId;
    string tempUsername;
    string tempTransactionId;

    if(myfile.is_open())
    {
            cout<<"                                             **** TRANSACTION HISTORY ***** "<<endl<<endl<<endl;
            cout<<"                          TRANSACTION ID |CUSTOMER ID |  TYPE   | AMOUNT  |  DATE & TIME   |   USER"<<endl<<endl;
        while(myfile>>tempTransactionId>>tempTransaction>>tempAmount>>tempDateTime>>tempCustomerId>>tempUsername)
        {
            cout<<"                      "<<tempTransactionId<<" | "<<tempCustomerId<<" | "<<tempTransaction<<" | "<<tempAmount<<" | "<<underscore2SpaceDateTime(tempDateTime)<<" | "<<tempUsername<<endl;
        }
    }
    else
    {
        cout<<"The file is currently in used"<<endl;
    }
}

bool History::findOne(string id)
{
    ifstream myfile("history.txt");

    string tempTransaction;
    long tempAmount;
    string tempDateTime;
    string tempCustomerId;
    string tempUsername;
    string tempTransactionId;

    if(myfile.is_open())
    {
        while(myfile>>tempTransactionId>>tempTransaction>>tempAmount>>tempDateTime>>tempCustomerId>>tempUsername)
        {
            if(tempTransactionId == id)
            {
              cout<<"                                      **** TRANSACTION HISTORY FOUND ***** "<<endl<<endl<<endl;
              cout<<"                          TRANSACTION ID |CUSTOMER ID |  TYPE   | AMOUNT  |  DATE & TIME   |   USER"<<endl<<endl;
              cout<<"                      "<<tempTransactionId<<" | "<<tempCustomerId<<" | "<<tempTransaction<<" | "<<tempAmount<<" | "<<underscore2SpaceDateTime(tempDateTime)<<" | "<<tempUsername<<endl;
              return true;
            }
        }
    }
    else
    {
        cout<<"The file is currently in used"<<endl;
    }
    return false;
}
