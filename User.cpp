#include "User.h"
#include <iostream>
#include<string>
#include<fstream>
#include <cstdio>
#include<ctime>
#include<sstream>

void gotoxy(short x, short y);
User::User(){}

User::User(string username,string password)
{
    this->_username = username;
    this->_password = password;
}

string generateUserID()
{
    time_t now = time(0);
    ostringstream ss;

    ss<<now;
    return "USER_" + ss.str();
}

//LOGIN ACCOUNT
bool User::login()
{
    ifstream myfile("users.txt");
    bool isCorrect;
    string txtUsername;
    string txtPassword;
    string id;

        while(myfile>>id>>txtUsername>>txtPassword)
        {
            if((this->_username == txtUsername) && (this->_password == txtPassword))
            {
                isCorrect = true;
                break;
            }
            else
            {
                isCorrect = false;
            }
        }

    return isCorrect;
}

bool User::checkUserIfExists(string username)
{
    ifstream myfileDisplay("users.txt");

    string tempId;
    string tempUsername;
    string tempPassword;

    bool isExists = false;

    while(myfileDisplay>>tempId>>tempUsername>>tempPassword)
    {
        if(username == tempUsername)
        {
            isExists = true;
        }
        //cout<<"Id:"<<tempId<<" "<<"username:"<<tempUsername<<" "<<"password:"<<tempPassword<<endl;
    }

    return isExists;
}

bool User::findOne(string username)
{
    ifstream myfileDisplay("users.txt");

    string tempId;
    string tempUsername;
    string tempPassword;

    bool isExists = false;

    while(myfileDisplay>>tempId>>tempUsername>>tempPassword)
    {
        if(username == tempUsername)
        {
            isExists = true;

            gotoxy(43,11);
            cout<<"******* USER FOUND ******* "<<endl;

            gotoxy(43,13);
            cout<<"User ID: "<<tempId<<endl;

            gotoxy(43,14);
            cout<<"Username: "<<tempUsername<<endl;

            gotoxy(43,15);
            cout<<"Password: "<<tempPassword<<endl;
        }
    }

    return isExists;
}
//CREATE USER ACCOUNT
void User::create()
{
    ofstream myfile("users.txt", ios::out | ios::app | ios::binary);

    //ifstream myfileDisplay("users.txt");

    if(myfile.is_open())
    {
       myfile<<generateUserID()<<" "<<this->_username<<" "<<this->_password<<endl;
       myfile.close();
    }
    else
    {
       cout<<"Unable to save user";
    }
}

//DISPLAYING LIST OF USERS
void User::display()
{
    ifstream myfile("users.txt");
    string username,password,id;

    if(myfile.is_open())
    {
        while(myfile>>id>>username>>password)
        {
            cout<<"                                     "<<id<<" | "<<username<<" | "<<password<<endl;
        }
    }
    else
    {
        cout<<"Unable to display users";
    }
}


//UPDATE USER ACCOUNT
void User::update(string username,string password)
{
    ifstream filein("users.txt");
    ofstream fileout("temp_user.txt");


    if(!filein || !fileout)
    {
        cout<<"unable to update file";
    }
    else
    {
        string tempId,tempUsername,tempPassword;
        string tempText;
        while(filein>>tempId>>tempUsername>>tempPassword)
        {
            if(username == tempUsername)
            {
                fileout<<tempId<<" "<<tempUsername<<" "<<password<<endl;
            }
            else
            {
                fileout<<tempId<<" "<<tempUsername<<" "<<tempPassword<<endl;
            }
        }
    }
    filein.close();
    fileout.close();

    ofstream out("users.txt");
    ifstream in("temp_user.txt");

    out << in.rdbuf();
}

//DELETE USER ACCOUNT
void User::destroy(string username)
{
    ifstream filein("users.txt");
    ofstream fileout("temp_user.txt");


    if(!filein || !fileout)
    {
        cout<<"unable to update file";
    }
    else
    {
        string tempId,tempUsername,tempPassword;
        string tempText;
        while(filein>>tempId>>tempUsername>>tempPassword)
        {
            if(username == tempUsername)
            {
                continue;
            }
            else
            {
                fileout<<tempId<<" "<<tempUsername<<" "<<tempPassword<<endl;
            }
        }
    }
    filein.close();
    fileout.close();

    ofstream out("users.txt");
    ifstream in("temp_user.txt");

    out << in.rdbuf();
}
