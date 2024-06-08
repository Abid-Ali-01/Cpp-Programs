#include <iostream>
using namespace std;

class ElectronicDevices{

public:
    virtual void powerOn() = 0; 
};


class Laptop : public ElectronicDevices{
public :
void powerOn() override{

    cout<<"Laptop Turned On "<<endl;
}

};

class Smartphone : public ElectronicDevices{
public :
void powerOn() override{

    cout<<"Smart Phone Turned On "<<endl;
}

};

class Tablet : public ElectronicDevices{
public:
 void powerOn() override{

    cout<<"Tablet Turned On "<<endl;
}

};

//Function Accepts Pointer
void TurnOn(ElectronicDevices *device){

    device->powerOn();

}
int main(){
Laptop laptop;
Smartphone Smartphone;
Tablet tablet;
TurnOn(&laptop);
TurnOn(&Smartphone);
TurnOn(&tablet);
}