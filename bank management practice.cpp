#include<bits/stdc++.h>
using namespace std;
class BankAccount
{
public:
    string account_holder;
    string address;
    int age;
    int account_number;
protected:
    int balance;
private:
    string password;
public:
    BankAccount(string account_holder,string address,int age,string password)
    {
        this-> account_holder=account_holder;
        this->address=address;
        this->age=age;
        this->password=password;
        this->account_number=rand()%1000000000;
        this->balance=0;
        cout<<"your account no is "<< this->account_number<<endl;
    }
    int show_balance(string password )
    {
        if(this->password==password)
        {
            return this->balance;
        }
        else
        {
            return -1;
        }
    }
    void add_money(string password,int amount)
    {

        if(amount<0)
        {
            cout<<"invalid amount"<<endl;
            return;
        }
        if(this->password==password)
        {
            this->balance+=amount;
            cout<<"add money sucessflly"<<endl;
        }
        else
        {
            cout<<"password didnt match"<<endl;
        }
    }

    void deposit_money(string password,int amount)
    {
        if(amount<0)
        {
            cout<<"invalid amount"<<endl;
            return;
        }
        if(this-> balance< amount)
        {
            cout<<"Insufficient balance"<<endl;
            return;
        }
        if(this->password==password)
        {
            this->balance-=amount;
            cout<<"deposit money sucessflly"<<endl;
        }
        else
        {
            cout<<"password didnt match"<<endl;
        }
    }
    friend class MyCash;
};

class MyCash
{
protected:
    int balance;
public:
    MyCash()
    {
        this->balance=0;
    }
    void add_money_form_bank(BankAccount *myAccount,string password,int amount )
    {
        if(amount<0)
        {
            cout<<"invalid amount"<<endl;
            return;
        }
        if(myAccount->balance <amount)
        {
            cout<<"insufficient  amount"<<endl;
            return;
        }
        if(myAccount->password==password)
        {
            this->balance+=amount;
            myAccount->balance-=amount;
            cout<<"add money bank is scessfully"<<endl;
        }
        else
        {
            cout<<"password didnt match"<<endl;
        }
    }
    int show_balance()
    {
        return balance;
    }
};
BankAccount* create_account()
{
    string account_holder, password,address;
    int age;
    cout<<"create Account"<<endl;
    cin>>account_holder>>address>>age>>password;
    BankAccount*myAccount = new BankAccount(account_holder,address,age,password);
    return myAccount;
}
void add_money(BankAccount *myAccount)
{
    string password;
    int amount;
    cout<<"Add money "<<endl;
    cin>>password >>amount ;
    myAccount->add_money(password,amount);
    cout<<"your bank balance is"<<myAccount->show_balance("abc")<<endl;
}
void deposit_money(BankAccount *myAccount)
{
    string password;
    int amount;
    cout<<"Deposit  money "<<endl;
    cin>>password >>amount ;
    myAccount->deposit_money(password,amount);
    cout<<"your bank balance is"<<myAccount->show_balance("abc")<<endl;
}
void add_money_form_bank(MyCash*myCash,BankAccount*myAccount)
{
    string password;
    int amount;
    cout<<"ADD   Money  FORM BANK"<<endl;
    cin>>password >>amount ;
    myCash->add_money_form_bank(myAccount,password,amount);
    cout<<"your bank balance is"<<myAccount->show_balance("abc")<<endl;
    cout<<"Mycash balanec is "<<myCash->show_balance()<<endl;
}
int main()
{
    //create_account();
    BankAccount *myAccount= create_account();
    MyCash *myCash= new MyCash();
    while(true)
    {
        cout<<"Select option: "<<endl;
        cout<<"1. ADD money to Bank  "<<endl;
        cout<<"2. deposit money form Bank  "<<endl;
        cout<<"3. ADD money to Mycash form  Bank  "<<endl;
        int option ;
        cin>> option;
        if(option==1)
        {
            add_money(myAccount);
        }
        else if(option==2)
        {
          deposit_money(myAccount);
        }
          else if(option==3)
          {
             add_money_form_bank(myCash,myAccount);
          }
          else
          {
              cout<<"invalid option"<<endl;
          }

    }


    /* add_money(myAccount);
      //cout<<"your bank balance is"<<myAccount->show_balance("abc")<<endl;
      deposit_money(myAccount);
      MyCash *myCash=new MyCash();

     add_money_form_bank(myCash,myAccount);*/
    return 0;
}
