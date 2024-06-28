#include <iostream>
#include<string>
using namespace std;


class BankAccount{
    private:
    string accountNum;
    string accountHolder;
    int balance;

    public:
    BankAccount(const string& userName,const string& accNum, int availableBalancce): accountNum(accNum), accountHolder(userName), balance(availableBalancce){}

    //Getter
    void getDetails(){
        cout<<"Account Holder Name : "<<accountHolder<<endl;
        cout<<"Account Number : "<<accountNum<<endl;
        cout<<"Available Balance : "<<balance<<endl;
    }

void deposit(int money){
    balance += money;
    cout<<"Amount Deposit Successfully"<<endl;
    cout<<"New Balance is "<<balance<<endl;
}

void withDraw(int amount){
    if(balance >= amount){
        balance -= amount;
          cout<<"Amount Withdrawn Successfully "<<endl;
        cout<<"Remaining Balance Is "<<balance<<endl;
    }
    else{
        cout<<"Insufficient Balance"<<endl;
    }
}

};


int main (){
    BankAccount BA("Abid Ali", "54401-9274201-7", 10000);
    BA.getDetails();
    BA.deposit(5000);
    BA.getDetails();
    BA.withDraw(12000);
    BA.withDraw(4000);
}