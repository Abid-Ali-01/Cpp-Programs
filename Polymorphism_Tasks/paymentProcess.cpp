#include <iostream>
using namespace std;

class PaymentMethod {

   public:
   virtual void processPayment() = 0;
 
};

class CreditCard : public PaymentMethod{
    void processPayment() override {
        cout<<"Paid With Credit Card"<<endl;
    }
};

class PayPal : public PaymentMethod{

    void processPayment() override {
        cout<<"Paid With Paypal"<<endl;
    }
};


class Bitcoin : public PaymentMethod {
    void processPayment() override {
        cout<<"Paid With Bitcoin"<<endl;
    }
};


void PaymentMethod(PaymentMethod *paymentType){

    paymentType->processPayment();
}

int main (){ 

CreditCard creditCard;
PayPal   payPal;
Bitcoin  bitCoin;

PaymentMethod(&creditCard);
PaymentMethod(&payPal);
PaymentMethod(&bitCoin);


}