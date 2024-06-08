#include <iostream>
using namespace std;

class Notification {

   public:
   virtual void sent() = 0;
 
};

class EmailNotification : public Notification{
    void sent() override {
        cout<<"Email Notification Sent"<<endl;
    }
};

class SmsNotification : public Notification{

    void sent() override {
        cout<<"SMS Notification Sent"<<endl;
    }
};


class PushNotification : public Notification {
    void sent () override {
        cout<<"Push Notification Sent"<<endl;
    }
};


//Function Accepts Reference 
void SendNotification(Notification &notification){

    notification.sent();
}

int main (){ 

EmailNotification emailNotification;
SmsNotification   smsNotification;
PushNotification  pushnotification;

SendNotification(emailNotification);
SendNotification(smsNotification);
SendNotification(pushnotification);


}