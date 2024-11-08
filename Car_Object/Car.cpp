#include <iostream>
using namespace std;

class Car{
private:
int fuel;

public:
Car() {fuel = 0;}


void start(){
    if(fuel >0){
        cout<<"Car Started With "<<fuel<<" Liters of Fuel"<<endl;
        ConsumeFuel();
    }
    else {
        cout<<"Car Can't Start, Put Some Fuel In It"<<endl;
    }
}

void ConsumeFuel(){
   while (fuel >0)
   {
    fuel--;

    cout<<"Covering Distance! Remaining "<<fuel<<" Liters"<<endl;

   }
   cout<<"Out of Fuel! Car Stoped"<<endl;
}

void putFuel(int f){
    fuel = f;
}

};

int main (){
    Car honda;
    honda.start();
    
    Car Jeep;
    Jeep.putFuel(5);
    Jeep.start();
}