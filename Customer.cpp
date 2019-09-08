#include "Customer.h"
#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
#include<ctime>
#include<sstream>
#include<windows.h>

using namespace std;

string spaceToUnderscore(string str)
{
    replace(str.begin(),str.end(),' ','_');
    return str;
}

string underscore2Space(string str)
{
    replace(str.begin(),str.end(),'_',' ');
    return str;
}


string generateID()
{
    time_t now = time(0);
    ostringstream ss;

    ss<<now;
    return ss.str();
}

string Customer::getID()
{
    return generateID();
}

Customer::Customer()
{

}

Customer::Customer(string fullname,string dateOfBirth,string address,string contact,string amount)
{
    this->id = generateID();
    this->fullname = spaceToUnderscore(fullname);
    this->dateOfBirth = dateOfBirth;
    this->address = spaceToUnderscore(address);
    this->contact = contact;
    this->amount = amount;
}

void Customer::create()
{
    ofstream myfile("customer.txt",ios::out | ios::app | ios::binary);
    myfile.seekp(0,ios::beg);
    if(myfile.is_open())
    {
        myfile<<this->id<<" "<<this->fullname<<" "<<this->dateOfBirth<<" "<<this->address<<" "<<this->contact<<" "<<this->amount<<endl;
        myfile.close();

    }
    else
    {
        cout<<"Unable to create new customer";
    }
}
void Customer::display()
{
    ifstream myfile("customer.txt");
    long id;
    string fullname,dateOfBirth,address,contact;
    long amount;

    if(myfile.is_open())
    {
        while(myfile>>id>>fullname>>dateOfBirth>>address>>contact>>amount)
        {
            cout<<"      "<<id<<" | "<<underscore2Space(fullname)<<" | "<<dateOfBirth<<" | "<<underscore2Space(address)<<" | "<<contact<<" | "<<amount<<endl;
            cout<<"      --------------------------------------------------------------------------------------------------"<<endl;
        }
    }
    else
    {
        cout<<"Unable to display customers";
    }
}

bool Customer::findOne(string id)
{
    ifstream myfile("customer.txt");
    string getId;
    string fullname,dateOfBirth,address,contact;
    long amount;
    bool isFound = false;

    if(myfile.is_open())
    {
        while(myfile>>getId>>fullname>>dateOfBirth>>address>>contact>>amount)
        {
            if(id == getId)
            {
                isFound = true;
                break;
            }
            else
            {
                isFound = false;
            }
        }
    }
    else
    {
        cout<<"Unable to display customers";
    }

    if(isFound)
    {
        //cout<<getId<<" | "<<underscore2Space(fullname)<<" | "<<dateOfBirth<<" | "<<underscore2Space(address)<<" | "<<contact<<" | "<<amount<<endl;
        cout<<"                 _________________________________________________________________________________"<<endl;
        cout<<"                | Account Number: "<<getId<<endl;
        cout<<"                | Customer Full Name: "<<underscore2Space(fullname)<<endl;
        cout<<"                | Date of Birth: "<<dateOfBirth<<endl;
        cout<<"                | Complete Address: "<<underscore2Space(address)<<endl;
        cout<<"                | Contact No.: "<<contact<<endl;
        cout<<"                | Total Amount Deposited: "<<amount<<endl;
        cout<<"                |_________________________________________________________________________________"<<endl;
    }
    else
    {
        cout<<endl<<endl<<endl;
        cout<<"                   .................................No Record Found......................................."<<endl;
    }
    return isFound;
}

bool Customer::update(string id,string address,string contact)
{
    ifstream filein("customer.txt");
    ofstream fileout("temp_customer.txt");

    string tempId;
    string tempFullname,tempDateOfBirth,tempAddress,tempContact;
    long tempAmount;
    string tempText;


    if(!filein || !fileout)
    {
        cout<<"unable to update file";
        return false;
    }
    else
    {

        while(filein>>tempId>>tempFullname>>tempDateOfBirth>>tempAddress>>tempContact>>tempAmount)
        {
            if(tempId == id)
            {
                fileout<<id<<" "<<tempFullname<<" "<<tempDateOfBirth<<" "<<spaceToUnderscore(address)<<" "<<spaceToUnderscore(contact)<<" "<<tempAmount<<endl;
            }
            else
            {
                fileout<<tempId<<" "<<tempFullname<<" "<<tempDateOfBirth<<" "<<tempAddress<<" "<<tempContact<<" "<<tempAmount<<endl;
            }
        }
    }
    filein.close();
    fileout.close();

    ofstream out("customer.txt");
    ifstream in("temp_customer.txt");

    out << in.rdbuf();

    return true;
}

bool Customer::destory(string id)
{
    ifstream filein("customer.txt");
    ofstream fileout("temp_customer.txt");

    string tempId;
    string tempFullname,tempDateOfBirth,tempAddress,tempContact;
    long tempAmount;
    string tempText;


    if(!filein || !fileout)
    {
        cout<<"unable to update file";
        return false;
    }
    else
    {

        while(filein>>tempId>>tempFullname>>tempDateOfBirth>>tempAddress>>tempContact>>tempAmount)
        {
            if(tempId == id)
            {
                continue;
            }
            else
            {
                fileout<<tempId<<" "<<tempFullname<<" "<<tempDateOfBirth<<" "<<tempAddress<<" "<<tempContact<<" "<<tempAmount<<endl;
            }
        }
    }
    filein.close();
    fileout.close();

    ofstream out("customer.txt");
    ifstream in("temp_customer.txt");

    out << in.rdbuf();

    return true;
}

void Customer::withdraw(string id,long amount)
{
    ifstream filein("customer.txt");
    ofstream fileout("temp_customer.txt");

    string tempId;
    string tempFullname,tempDateOfBirth,tempAddress,tempContact;
    long tempAmount;
    string tempText;

    long sum = 0;


    if(!filein || !fileout)
    {
        cout<<"unable to update file";
    }
    else
    {

        while(filein>>tempId>>tempFullname>>tempDateOfBirth>>tempAddress>>tempContact>>tempAmount)
        {
            if(tempId == id)
            {
                sum = tempAmount - amount;
                fileout<<id<<" "<<tempFullname<<" "<<tempDateOfBirth<<" "<<spaceToUnderscore(tempAddress)<<" "<<spaceToUnderscore(tempContact)<<" "<<sum<<endl;
            }
            else
            {
                fileout<<tempId<<" "<<tempFullname<<" "<<tempDateOfBirth<<" "<<tempAddress<<" "<<tempContact<<" "<<tempAmount<<endl;
            }
        }
    }
    filein.close();
    fileout.close();

    ofstream out("customer.txt");
    ifstream in("temp_customer.txt");
    out << in.rdbuf();
}

void Customer::desposit(string id,long amount)
{
    ifstream filein("customer.txt");
    ofstream fileout("temp_customer.txt");

    string tempId;
    string tempFullname,tempDateOfBirth,tempAddress,tempContact;
    long tempAmount;
    string tempText;

    long sum = 0;


    if(!filein || !fileout)
    {
        cout<<"unable to update file";
    }
    else
    {

        while(filein>>tempId>>tempFullname>>tempDateOfBirth>>tempAddress>>tempContact>>tempAmount)
        {
            if(tempId == id)
            {
                sum = tempAmount + amount;
                fileout<<id<<" "<<tempFullname<<" "<<tempDateOfBirth<<" "<<spaceToUnderscore(tempAddress)<<" "<<spaceToUnderscore(tempContact)<<" "<<sum<<endl;
            }
            else
            {
                fileout<<tempId<<" "<<tempFullname<<" "<<tempDateOfBirth<<" "<<tempAddress<<" "<<tempContact<<" "<<tempAmount<<endl;
            }
        }
    }
    filein.close();
    fileout.close();

    ofstream out("customer.txt");
    ifstream in("temp_customer.txt");

    out << in.rdbuf();
}

long Customer::getTotalDeposite(string id)
{
    ifstream myfile("customer.txt");
    string getId;
    string fullname,dateOfBirth,address,contact;
    long amount = 0;
    long totalDeposite = 0;

    if(myfile.is_open())
    {
        while(myfile>>getId>>fullname>>dateOfBirth>>address>>contact>>amount)
        {
            if(id == getId)
            {
                totalDeposite = amount;
                break;
            }
        }
    }
    else
    {
        cout<<"Unable to display customers";
    }

    return totalDeposite;
}


void Customer::reciept(string customerId,string transactionType,string typeText,int amount)
{
    //ofstream myfile("reciepts.txt",ios::out | ios::app | ios::binary);
    ofstream myfile;
    string fileName = "receipt\\" + generateTransactionID() + ".txt";
    myfile.open(fileName.c_str());
    if(myfile.is_open())
    {
        myfile<<"           *** CRIMSON BANKING OFFICIAL RECEIPT *** "<<endl<<endl<<endl;
        myfile<<"  Date: " <<TimeStamp()<<endl<<endl;
        myfile<<"  Transaction ID"<<"       "<<"Account No"<<"     "<<"Transaction Type"<<endl;
        myfile<<generateTransactionID()<<"     "<<customerId<<"         "<<transactionType<<endl<<endl<<endl;
        myfile<<typeText<<": P"<<amount<<endl<<endl;
        myfile<<"Current Balance: P"<<getTotalDeposite(customerId)<<endl;
    }
}

