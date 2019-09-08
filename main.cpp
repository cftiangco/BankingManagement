#include <iostream>
#include<fstream>
#include "User.h"
#include "Customer.h"
#include<algorithm>
#include<sstream>
#include<windows.h>
#include<string>
#include<string.h>
#include<conio.h>
#include<dos.h>
#include<stdio.h>
#include<limits>
#include "History.h"
#include<ctime>

using namespace std;

void header();
void gotoxy(short x, short y);

void menu();

void transaction();

void customer();
void customer_new();
void customer_display();
void customer_new_question(int location);
void customer_find();
void customer_findAndUpdate();
void customer_update();
void customer_remove();
void customer_find_display();
void customer_withdraw();
void customer_deposit();
void customer_history();

void user();
void user_create();
void user_update();
void user_display();
void user_remove();

void loading();
void transaction_search();

class Session
{
    public:
        static string username;
};

string Session::username = "";


int main()
{
    /* COVERT LONG TO STRING
    long l = 123456;
    ostringstream ss;
    ss << l;
    cout<< ss.str() + "7";
    */

    /*
    char key_press;
    int ascii_value;
    cout<<"Press any key to check Its ASCI"<<endl;

    while(1)
    {
        key_press = getch();
        ascii_value = key_press;
        if(ascii_value == 19) //For ESC
        {
            break;
        }
        cout<<"Key:"<<key_press<<" ASCII:"<<ascii_value<<endl;
    }
    */


     //menu();



     system("cls");
     system("color 97");

     string username="", password="";
     char c= ' ';

     gotoxy(55,12);
     cout<<"U S E R N A M E"<<endl;

     gotoxy(55,15);
     cout<<"P A S S W O R D"<<endl;

     LOGIN:

     gotoxy(55,13);
     cin>>username;

     gotoxy(55,16);
     while(c!=13) //enter key;
     {
         c=getch();
         if(c!=13)
         {
            password += c;
         }

     }
     cout<<endl;
     User user(username,password);
     if(user.login())
     {
        Session::username = username;
        loading();
        menu();
     }
     else
     {
         gotoxy(50,20);
         cout<<"Incoorect Username/Password"<<endl;
         password = "";
         username = "";
         c = ' ';
         goto LOGIN;
     }

     return 0;



}

void loading()
{
     gotoxy(50,50);
     cout<<"LOADING, PLEASE WAIT..."<<endl;

     for(int x = 0;x<120;x++)
     {
        Sleep(20);
        printf("%c",219);
     }
}

void header()
{
    gotoxy(37,4);
    cout<<"*** CRIMSON BANKING MANAGEMENT SYSTEM ***"<<endl;
}

void menu()
{
    system("cls");
    system("color 97");
    header();

    gotoxy(25,10);
    cout<<"[T] : TRANSACTION";

    gotoxy(70,10);
    cout<<"[C] : CUSTOMER ACCOUNT";

    gotoxy(25,15);
    cout<<"[U] : USER ACCOUNT";

    gotoxy(70,15);
    cout<<"[X] : EXIT";

    gotoxy(25,20);
    cout<<"[S] : SEARCH TRANSACTION";

    gotoxy(43,25);
    cout<<"[ PLEASE PRESS YOUR OPTION ]"<<endl;

    char key_press;
    int ascii_value;

    while(1)
    {
        key_press = getch();
        ascii_value = key_press;
        if((ascii_value == 120) || (ascii_value == 88)) //For ESC || X120 x88
        {
            exit(1);
            break;
        }
        else if((ascii_value == 116) || (ascii_value == 84))
        {
            transaction();
        }
        else if((ascii_value == 99) || (ascii_value == 67))
        {
            customer();
        }
        else if((ascii_value == 117) || (ascii_value == 85))
        {
            user();
        }
        else if((ascii_value == 115) || (ascii_value == 83))
        {
            transaction_search();
        }
        else
        {
            menu();
        }
    }

}

void transaction()
{

    system("cls");
    system("color 97");
    header();

    gotoxy(25,10);
    cout<<"[W] : WITHDRAW";

    gotoxy(70,10);
    cout<<"[D] : DEPOSIT";

    gotoxy(25,13);
    cout<<"[B] : BACK";

    gotoxy(70,13);
    cout<<"[H] : TRANSACTION HISTORY";

    gotoxy(40,17);
    cout<<"[ PLEASE PRESS YOUR OPTION ]"<<endl;

    char key_press;
    int ascii_value;

    while(1)
    {
        key_press = getch();
        ascii_value = key_press;
        if((ascii_value == 87) || (ascii_value == 119)) //For ESC || X120 x88
        {
            customer_withdraw();
        }
        else if((ascii_value == 68) || (ascii_value == 100))
        {
            customer_deposit();
        }
        else if((ascii_value == 98) || (ascii_value == 66))
        {
            menu();
        }
        else if((ascii_value == 104) || (ascii_value == 72))
        {
            customer_history();
        }
        else
        {
            //menu();
        }
    }

}
// ************************************* TRANSACTION SEARCH ***************************** //
void transaction_search()
{
    system("cls");
    system("color 97");
    header();

    gotoxy(42,7);
    cout<<"    *** SEARCH TRANSACTION *** "<<endl;

    string transactionID = "";

    gotoxy(35,10);
    cout<<"Enter Transaction No.: "<<endl;


    gotoxy(57,10);
    cin>>transactionID;

    History historyFindOne;

    cout<<endl<<endl;
    if(historyFindOne.findOne(transactionID))
    {
        gotoxy(44,21);
        cout<<"DO YOU WANT ANOTHER TRANSACTION?";

        gotoxy(52,23);
        cout<<"[Y] YES [N] NO";

        char key_press;
        int ascii_value;

        while(1)
        {
            key_press = getch();
            ascii_value = key_press;
            if((ascii_value == 121) || (ascii_value == 89))
            {
                transaction_search();
            }
            else if((ascii_value == 110) || (ascii_value == 78))
            {
                menu();
            }
            else
            {
                //no logic
            }
        }
    }
    else
    {
        cout<<"                                        ****  TRANSACTION NUMBER NOT FOUND. ***** "<<endl;

        char key_press;
        int ascii_value;

        gotoxy(44,15);
        cout<<"DO YOU WANT ANOTHER TRANSACTION?";

        gotoxy(52,17);
        cout<<"[Y] YES [N] NO";

        while(1)
        {
            key_press = getch();
            ascii_value = key_press;
            if((ascii_value == 121) || (ascii_value == 89))
            {
                transaction_search();
            }
            else if((ascii_value == 110) || (ascii_value == 78))
            {
                menu();
            }
            else
            {
                //no logic
            }
        }
    }
}
void customer()
{
    system("cls");
    system("color 97");
    header();

    gotoxy(25,10);
    cout<<"[N] : NEW CUSTOMER ACCOUNT";

    gotoxy(70,10);
    cout<<"[U] : UPDATE CUSTOMER ACCOUNT";

    gotoxy(25,15);
    cout<<"[C] : CHECK CUSTOMER ACCOUNT";

    gotoxy(70,15);
    cout<<"[L] : LIST OF CUSTOMERS ACCOUNT";

    gotoxy(25,20);
    cout<<"[R] : REMOVE CUSTOMER ACCOUNT";

    gotoxy(70,20);
    cout<<"[B] : BACK";

    gotoxy(43,25);
    cout<<"[ PLEASE PRESS YOUR OPTION ]"<<endl;

    char key_press;
    int ascii_value;

    while(1)
    {
        key_press = getch();
        ascii_value = key_press;
        if((ascii_value == 110) || (ascii_value == 78)) //For ESC || X120 x88
        {
            customer_new();
        }
        else if((ascii_value == 117) || (ascii_value == 85))
        {
            customer_update();
        }
        else if((ascii_value == 99) || (ascii_value == 67))
        {
            customer_find();
        }
        else if((ascii_value == 108) || (ascii_value == 76))
        {
            customer_display();
        }
        else if((ascii_value == 114) || (ascii_value == 82))
        {
            customer_remove();
        }
        else if((ascii_value == 98) || (ascii_value == 66))
        {
            menu();
        }
        else
        {
            //menu();
        }
    }

}

void customer_new()
{
    system("cls");
    header();



    char fullname[50];
    string address;
    string dateOfBirth;
    string contact;
    string amount = "0";

    gotoxy(43,5);
    cout<<"*** CUSTOMER REGISTRATION ***";

    gotoxy(45,7);
    cout<<"New Customer Full Name:";

    gotoxy(45,8);
    cout<<"Date of Birth(MM/DD/YYYY):";

    gotoxy(45,9);
    cout<<"Current Complete Address:";

    gotoxy(45,10);
    cout<<"Contact/Phone No.:";

    gotoxy(45,11);
    cout<<"Amount To Be Deposit(Optional):";
    cout<<endl;

    //FULLNAME
    gotoxy(68,7);
    cin.ignore();
    cin.getline(fullname,50);

    //BIRTHDATE
    gotoxy(71,8);
    getline(cin,dateOfBirth);

    //address
    gotoxy(70,9);
    getline(cin,address);

    //Contact number
    gotoxy(63,10);
    getline(cin,contact);

    //DEPOSITE AMOUNT
    gotoxy(76,11);
    getline(cin,amount);


    if(strlen(fullname) == 0)
    {
        cout<<"fullname is required"<<endl;
    }
    else if(dateOfBirth.size() == 0)
    {
        cout<<"Date of Birth is required"<<endl;
    }
    else
    {
        string question;
        gotoxy(32,13);
        cout<<"Are you sure do you want to register this customer?(Y/N):";
        getline(cin,question);

        if(question == "y" || question == "Y")
        {
            Customer customer(fullname,dateOfBirth,address,contact,amount);
            customer.create();
            gotoxy(39,15);
            cout<<"Customer has been successfully saved!"<<endl;
            gotoxy(39,16);
            cout<<"New Customer Account Number: "<<customer.getID()<<endl;

            customer_new_question(18);
        }
        else if(question == "n" || question == "N")
        {
            //question 2
            customer_new_question(14);
        }
        else
        {
            menu();
        }
    }


}

void customer_display()
{
    system("cls");
    header();
    gotoxy(30,6);
    cout<<"=================== CUSTOMERS LIST ===================="<<endl;

    Customer customerView;
    customerView.display();

    char key_press;
    int ascii_value;

    cout<<"                                         Press (B) TO GO BACK TO MAIN MENU"<<endl;
    while(1)
    {
        key_press = getch();
        ascii_value = key_press;
        if((ascii_value == 98) || (ascii_value == 66))
        {
            menu();
        }
    }
}

void customer_find()
{

    //DISPLAY ONLY
    system("cls");
    header();
    Customer customer;
    string choose;
    string id;

    gotoxy(44,7);
    cout<<"***  CHECK CUSTOMER ACCOUNT  ***";

    gotoxy(40,9);
    cout<<"Please Enter Account Number:";
    cin>>id;


    if(customer.findOne(id))
    {
        History h;
        h.display(id);

        cout<<endl;
        cout<<"                                       Do you want to search another account?(Y/N):";
        cin>>choose;
        if(choose == "Y" || choose == "y")
        {
            customer_find();
        }
        else
        {
            menu();
        }
    }
    else
    {
        gotoxy(33,19);
        cout<<"Do you want to search another account?(Y/N):";
        cin>>choose;
        if(choose == "Y" || choose == "y")
        {
            customer_find();
        }
        else
        {
            menu();
        }
    }
}

void customer_findAndUpdate()
{
    system("cls");
    header();
    string choose;
    string id,contact;
    char address[100];

    gotoxy(44,7);
    cout<<"*** UPDATE CUSTOMER ACCOUNT ***";

    gotoxy(40,9);
    cout<<"Please Enter Account Number:";
    cin>>id;

    Customer customerFind;
    if(customerFind.findOne(id))
    {
        gotoxy(42,20);
        cout<<"Enter New Address: ";
        cin.ignore();
        cin.getline(address,100);

        gotoxy(42,21);
        cout<<"Enter new Contact Number: ";
        cin>>contact;

        //update logic

        Customer customerUpdate;

        string yesNo;

        gotoxy(33,22);
        cout<<"Are you sure do you want to update this Record?(Y/N):";
        cin>>yesNo;

        if((yesNo == "y") || (yesNo == "Y"))
        {
            if(customerUpdate.update(id,address,contact))
            {
                gotoxy(42,24);
                cout<<"Customer has been successfully updated!"<<endl;

                gotoxy(33,25);
                cout<<"Do you want to search and update another account?(Y/N):";
                cin>>choose;
                if(choose == "Y" || choose == "y")
                {
                    customer_findAndUpdate();
                }
                else
                {
                    menu();
                }
            }
            else
            {
                cout<<"Unable to update customer"<<endl;
            }
        }
        else if((yesNo == "n") || (yesNo == "N"))
        {
            gotoxy(33,25);
                cout<<"Do you want to search and update another account?(Y/N):";
                cin>>choose;
                if(choose == "Y" || choose == "y")
                {
                    customer_findAndUpdate();
                }
                else
                {
                    menu();
                }
        }
        else
        {

        }
    }
    else
    {
        gotoxy(33,19);
        cout<<"Do you want to search and update another account?(Y/N):";
        cin>>choose;
        if(choose == "Y" || choose == "y")
        {
            customer_findAndUpdate();
        }
        else
        {
            menu();
        }
    }
}

void customer_update()
{
    customer_findAndUpdate();
}

void customer_remove()
{
    system("cls");
    header();
    Customer customer;
    string choose;
    string id;

    gotoxy(44,7);
    cout<<"***  REMOVE CUSTOMER ACCOUNT  ***";

    gotoxy(40,9);
    cout<<"Please Enter Account Number:";
    cin>>id;


    if(customer.findOne(id))
    {
        //DELETE RECORD LOGIC
        string del;
        gotoxy(42,20);
        cout<<"Do you want to delete this account?(Y/N): ";
        cin>>del;

        if((del == "y") || (del == "Y"))
        {
            if(customer.destory(id))
            {
                gotoxy(42,22);
                cout<<"Customer has been successfully Deleted!"<<endl;

                gotoxy(42,24);
                cout<<"Do you want to delete another account?(Y/N):";
                cin>>choose;
                if(choose == "Y" || choose == "y")
                {
                    customer_remove();
                }
                else
                {
                    menu();
                }

            }
            else
            {
                cout<<"Unable to delete customer"<<endl;
            }
        }
        else
        {
            menu();
        }
    }
    else
    {
        gotoxy(33,19);
        cout<<"Do you want to search another account?(Y/N):";
        cin>>choose;
        if(choose == "Y" || choose == "y")
        {
            customer_remove();
        }
        else
        {
            menu();
        }
    }
}

//QUESTION 2
void customer_new_question(int location)
{
    string question2;
    gotoxy(39,location);
    cout<<"Do you still want to create new Customer?(Y/N):";
    getline(cin,question2);

    if((question2 == "y") || (question2 == "Y"))
    {
        customer_new();
    }
    else if((question2 == "n") || (question2 == "n"))
    {
        menu();
    }
    else
    {
        cout<<"Unknown option"<<endl;
    }
}

void customer_withdraw()
{
    system("cls");
    header();
    string choose;
    string id;

    long amount;
    string qAmount;

    gotoxy(44,7);
    cout<<"*** WITHDRAW TRANSACTION ***";

    gotoxy(40,9);
    cout<<"Please Enter Account Number:";
    cin>>id;

    Customer customerFind;


    if(customerFind.findOne(id))
    {
        gotoxy(40,20);
        cout<<"Please Enter Amount To Be Withdraw:";
        cin>>amount;

        gotoxy(38,22);
        cout<<"ARE YOU SURE YOU WANT TO WITHDRAW THIS AMOUNT?"<<endl;

        gotoxy(52,23);
        cout<<"[Y] YES [N] NO"<<endl;
        char key_press;
        int ascii_value;
        History history("Withdraw",amount,id,Session::username);

        while(1)
        {
            key_press = getch();
            ascii_value = key_press;

            if((ascii_value == 121) || (ascii_value == 89)) //yes
            {
                if(amount > customerFind.getTotalDeposite(id))
                {
                    gotoxy(27,25);
                    cout<<"Sorry the customer don't have enough balance to withdraw this Amount"<<endl;

                    char key_press;
                    int ascii_value;

                    gotoxy(45,27);
                    cout<<"DO YOU WANT ANOTHER TRANSACTION";

                    gotoxy(53,28);
                    cout<<"[Y] YES [N] NO";

                    while(1)
                    {
                        key_press = getch();
                        ascii_value = key_press;

                        if((ascii_value == 121) || (ascii_value == 89)) //yes
                        {
                            customer_withdraw();
                        }
                        else if((ascii_value == 110) || (ascii_value == 78))
                        {
                            menu();
                        }
                    }


                }
                else
                {

                    history.create();
                    customerFind.withdraw(id,amount);
                    customerFind.reciept(id,"Withdraw","Withdrew Amount",amount);

                    gotoxy(41,25);
                    cout<<"Transaction successfully completed!";

                    //transaction ID
                    gotoxy(41,26);
                    cout<<"Transaction ID: "<<customerFind.generateTransactionID()<<endl;

                    gotoxy(43,27);
                    cout<<"DO YOU WANT ANOTHER TRANSACTION?"<<endl;
                    gotoxy(52,28);
                    cout<<"[Y] YES [N] NO"<<endl;

                    char key_press;
                    int ascii_value;

                    while(1)
                    {
                        key_press = getch();
                        ascii_value = key_press;
                        if((ascii_value == 121) || (ascii_value == 89))
                        {
                            customer_withdraw();
                        }
                        else
                        {
                            transaction();
                        }
                    }
                }
            }
            else if((ascii_value == 116) || (ascii_value == 84))
            {

            }
            else
            {
                menu();
            }
        }
    }
    else
    {
        gotoxy(44,19);
        cout<<"DO YOU WANT ANOTHER TRANSACTION?";

        gotoxy(52,20);
        cout<<"[Y] YES [N] NO";

        char key_press;
        int ascii_value;

        while(1)
        {
            key_press = getch();
            ascii_value = key_press;
            if((ascii_value == 121) || (ascii_value == 89))
            {
                customer_withdraw();
            }
            else if((ascii_value == 110) || (ascii_value == 78))
            {
                transaction();
            }
            else
            {
                //no logic
            }
        }
    }

}

void customer_deposit()
{
    system("cls");
    header();
    string choose;
    string id;
    History history;
    long amount;

    gotoxy(44,7);
    cout<<"*** DEPOSIT TRANSACTION ***";

    gotoxy(40,9);
    cout<<"Please Enter Account Number:";
    cin>>id;

    Customer customerFind;
    if(customerFind.findOne(id))
    {
        gotoxy(40,20);
        cout<<"Please Enter Amount To Be Deposit:";
        cin>>amount;

        gotoxy(36,22);
        cout<<"ARE YOU SURE YOU WANT TO DEPOSIT THIS AMOUNT?";

        gotoxy(50,23);
        cout<<"[Y] YES [N] NO";

        char key_press;
        int ascii_value;

        while(1)
        {
            key_press = getch();
            ascii_value = key_press;

            if((ascii_value == 121) || (ascii_value == 89))
            {
                if(amount < 200)
                {
                    gotoxy(35,25);
                    cout<<"Deposit amount must be greater than or equal to 200"<<endl;

                    gotoxy(45,27);
                    cout<<"DO YOU WANT ANOTHER TRANSACTION";

                    gotoxy(50,28);
                    cout<<"[Y] YES [N] NO";

                    char key;
                    int value;

                    while(1)
                    {
                        key = getch();
                        value = key;
                        if((value == 121 ) || (value == 89))
                        {
                            customer_deposit();
                        }
                        else
                        {
                            menu();
                        }
                    }

                }
                else
                {
                    customerFind.desposit(id,amount);

                    //HISTORY RECORDER
                    History history("Deposit",amount,id,Session::username);
                    history.create();

                    //RECIEPT
                    customerFind.reciept(id,"Diposit","Diposited Amount",amount);

                    gotoxy(41,25);
                    cout<<"Transaction successfully completed!"<<endl;

                    //transaction ID
                    gotoxy(41,26);
                    cout<<"Transaction ID: "<<customerFind.generateTransactionID()<<endl;

                    gotoxy(43,27);
                    cout<<"DO YOU WANT ANOTHER TRANSACTION?";

                    gotoxy(50,28);
                    cout<<"[Y] YES [N] NO";

                    char key1;
                    int value1;

                    while(1)
                    {
                        key1 = getch();
                        value1 = key1;
                        if((value1 == 121 ) || (value1 == 89))
                        {
                            customer_deposit();
                        }
                        else
                        {
                            menu();
                        }
                    }
                }
            }
            else if((ascii_value == 110) || (ascii_value == 78))
            {
                    gotoxy(42,25);
                    cout<<"DO YOU WANT ANOTHER TRANSACTION?";
                    gotoxy(49,26);
                    cout<<"[Y] YES [N] NO";
                    char key;
                    int value;

                    while(1)
                    {
                        key = getch();
                        value = key;
                        if((value == 121 ) || (value == 89))
                        {
                            customer_deposit();
                        }
                        else if((value == 110 ) || (value == 78))
                        {
                            menu();
                        }
                        else
                        {
                            //no logic unknown key
                        }
                    }
            }
            else
            {
                // if not no and yes
            }
        }

    }
    else
    {
        gotoxy(44,19);
        cout<<"DO YOU WANT ANOTHER TRANSACTION?";

        gotoxy(52,20);
        cout<<"[Y] YES [N] NO";

        char key_press;
        int ascii_value;

        while(1)
        {
            key_press = getch();
            ascii_value = key_press;
            if((ascii_value == 121) || (ascii_value == 89))
            {
                customer_deposit();
            }
            else if((ascii_value == 110) || (ascii_value == 78))
            {
                transaction();
            }
            else
            {
                //no logic
            }
        }
    }

}

void customer_history()
{
    system("cls");
    system("color 97");
    header();
    cout<<endl<<endl;

    History history;
    history.display();

    cout<<endl;
    cout<<"                                                     PRESS [B] TO GO BACK"<<endl;

    char key_press;
    int ascii_value;
    while(1)
    {
        key_press = getch();
        ascii_value = key_press;
        if((ascii_value == 98) || (ascii_value == 66))
        {
            menu();
        }
    }
}


//============ CUSTOMER ===================//
void user()
{
    system("cls");
    system("color 97");
    header();

    gotoxy(25,10);
    cout<<"[N] : NEW USER ACCOUNT";

    gotoxy(70,10);
    cout<<"[U] : CHECK/UPDATE USER ACCOUNT";

    gotoxy(25,15);
    cout<<"[L] : LIST OF USERS ACCOUNT";

    gotoxy(70,15);
    cout<<"[R] : REMOVE USER ACCOUNT";

    gotoxy(25,20);
    cout<<"[B] : BACK";

    gotoxy(43,25);
    cout<<"[ PLEASE PRESS YOUR OPTION ]"<<endl;

    char key_press;
    int ascii_value;

    while(1)
    {
        key_press = getch();
        ascii_value = key_press;
        if((ascii_value == 110) || (ascii_value == 78)) //For ESC || X120 x88
        {
            user_create();
        }
        else if((ascii_value == 117) || (ascii_value == 85))
        {
            user_update();
        }
        else if((ascii_value == 108) || (ascii_value == 76))
        {
            user_display();
        }
        else if((ascii_value == 114) || (ascii_value == 82))
        {
            user_remove();
        }
        else if((ascii_value == 98) || (ascii_value == 66))
        {
            menu();
        }
        else
        {
            //menu();
        }
    }

}

void user_create()
{
    system("cls");
    header();
    string username;
    string password1;
    string password2;

    gotoxy(44,7);
    cout<<"***  CREATE USER ACCOUNT  ***";

    gotoxy(40,9);
    cout<<"Please Enter Username:";

    gotoxy(40,10);
    cout<<"Please Enter Password:";

    gotoxy(40,11);
    cout<<"Please Confirm Password:";

    gotoxy(62,9);
    cin>>username;

    gotoxy(62,10);
    cin>>password1;

    gotoxy(64,11);
    cin>>password2;

    if(password1 == password2)
    {
        User user(username,password1);
        if(user.checkUserIfExists(username) == true)
        {
                gotoxy(40,13);
                cout<<"User Name is already Exists!"<<endl;

                gotoxy(35,16);
                string yesNo;
                cout<<"Do you still want to create User?(Y/N):";
                cin>>yesNo;

                if(yesNo == "Y" || yesNo == "y")
                {
                    user_create();
                }
                else
                {
                    menu();
                }
        }
        else
        {
            gotoxy(33,12);
            string sure;
            cout<<"Are you sure you want to create this User?(Y/N):";
            cin>>sure;
            if((sure == "Y") || (sure == "y"))
            {
                gotoxy(37,14);
                cout<<"New user has been successfully created!";
                user.create();

                gotoxy(37,16);
                string yesNo;
                cout<<"Do you want to create another User?(Y/N):";
                cin>>yesNo;

                if(yesNo == "Y" || yesNo == "y")
                {
                    user_create();
                }
                else
                {
                    menu();
                }

            }
            else
            {
                gotoxy(37,16);
                string yesNo;
                cout<<"Do you still want to create User?(Y/N):";
                cin>>yesNo;

                if(yesNo == "Y" || yesNo == "y")
                {
                    user_create();
                }
                else
                {
                    menu();
                }
            }

        }
    }
    else
    {
                gotoxy(32,13);
                cout<<"Password didn't matched the confirm password."<<endl;

                gotoxy(35,16);
                string yesNo;
                cout<<"Do you still want to create User?(Y/N):";
                cin>>yesNo;

                if(yesNo == "Y" || yesNo == "y")
                {
                    user_create();
                }
                else
                {
                    menu();
                }
    }


}

void user_update()
{
    system("cls");
    header();

    gotoxy(41,7);
    cout<<"***  CHECK & UPDATE USER ACCOUNT  ***";

    gotoxy(40,9);
    string username;
    cout<<"Please Search For Username:";
    cin>>username;

    User user;
    string yesNo;

    if(user.findOne(username))
    {

        gotoxy(36,17);
        cout<<"Do you want to edit this Account?(Y/N):";
        cin>>yesNo;

        if((yesNo == "Y") || (yesNo == "y"))
        {
            string newPassword1,newPassword2;

            gotoxy(36,19);
            cout<<"Please Enter New Password: ";
            cin>>newPassword1;

            gotoxy(36,20);
            cout<<"Please Confirm New Password: ";
            cin>>newPassword2;

            if(newPassword1 == newPassword2)
            {
                string yesNo2;

                gotoxy(31,22);
                cout<<"Are you sure you want to update this Account?(Y/N):";
                cin>>yesNo2;

                if((yesNo2 == "Y") || (yesNo2 == "y"))
                {
                    user.update(username,newPassword1);

                    gotoxy(35,24);
                    cout<<"User account has been successfully updated!"<<endl;

                    string yesNo3;
                    gotoxy(32,25);
                    cout<<"Do you want to search another User Account?(Y/N):";
                    cin>>yesNo3;
                    if((yesNo3 == "Y") || (yesNo3 == "y"))
                    {
                        user_update();
                    }
                    else
                    {
                        menu();
                    }
                }
                else
                {
                    menu();
                }
            }
            else
            {
                cout<<"Password did'nt match the confirm password"<<endl;
            }
        }
        else
        {
            string yesNo3;
            gotoxy(33,18);
            cout<<"Do you want to search another User Account?(Y/N):";
            cin>>yesNo3;
            if((yesNo3 == "Y") || (yesNo3 == "y"))
            {
                user_update();
            }
            else
            {
                menu();
            }
        }
    }
    else
    {
        gotoxy(42,12);
        cout<<"******* NO USER FOUND *******"<<endl;

        string yesNo3;
        gotoxy(34,15);
        cout<<"Do you want to search another User Account?(Y/N):";
        cin>>yesNo3;
        if((yesNo3 == "Y") || (yesNo3 == "y"))
        {
            user_update();
        }
        else
        {
            menu();
        }
    }
}

void user_display()
{
    system("cls");
    header();
    gotoxy(44,6);
    cout<<"***  LIST OF USERS ACCOUNT  ***";
    User user;
    string goBack;


    cout<<endl<<endl<<endl;
    cout<<"                                      User ID        |   Username   |  Password"<<endl;
    cout<<"                                     ___________________________________________"<<endl;
    user.display();
    cout<<endl;

    char key_press;
    int ascii_value;

    cout<<"                                          PRESS [B] TO GO BACK TO MAIN MENU"<<endl;
    while(1)
    {
        key_press = getch();
        ascii_value = key_press;
        if((ascii_value == 98) || (ascii_value == 66)) //For ESC || X120 x88
        {
            menu();
        }
    }

}

void user_remove()
{
    system("cls");
    header();

    gotoxy(41,7);
    cout<<"***  REMOVE USER ACCOUNT  ***";

    gotoxy(40,9);
    string username;
    cout<<"Please Search For Username:";
    cin>>username;

    User user;
    string yesNo;

    if(user.findOne(username))
    {

        gotoxy(36,17);
        cout<<"Do you want to remove this Account?(Y/N):";
        cin>>yesNo;

        if((yesNo == "Y") || (yesNo == "y"))
        {
            user.destroy(username);

            gotoxy(36,19);
            cout<<"User has been successfully Removed!"<<endl;

            string qRemove;

            gotoxy(36,21);
            cout<<"Do you want to remove another Account?(Y/N):";
            cin>>qRemove;

            if((qRemove == "y") || (qRemove == "Y"))
            {
                user_remove();
            }
            else
            {
                main();
            }
        }
        else
        {
            main();
        }
    }
    else
    {
        gotoxy(42,12);
        cout<<"******* NO USER FOUND *******"<<endl;

        string yesNo3;
        gotoxy(34,15);
        cout<<"Do you want to remove another User Account?(Y/N):";
        cin>>yesNo3;
        if((yesNo3 == "Y") || (yesNo3 == "y"))
        {
            user_remove();
        }
        else
        {
            menu();
        }
    }
}

void gotoxy(short x, short y)           //definition of gotoxy function//
{
     COORD pos ={x,y};
     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}


