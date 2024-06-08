#include <iostream>
using namespace std;

class Message {

   public:
   virtual void sendMessage() = 0;
 
};

class TextMessage : public Message{
    void sendMessage() override {
        cout<<"Text Message Sent Successfully"<<endl;
    }
};

class ImageMessage : public Message{

    void sendMessage() override {
        cout<<"Image Sent Successfully"<<endl;
    }
};


class VideoMessage : public Message {
    void sendMessage() override {
        cout<<"Video Message Sent Successfully"<<endl;
    }
};



void MessageType(Message *paymentType){

    paymentType->sendMessage();
}

int main (){ 

TextMessage T_msg;
ImageMessage   I_msg;
VideoMessage  V_msg;

MessageType(&T_msg);
MessageType(&I_msg);
MessageType(&V_msg);


}