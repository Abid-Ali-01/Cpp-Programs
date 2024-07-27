#include<iostream>
#include<cmath> //for Pow() function
#include <iomanip> // for SetPrecision() Funtion 
using namespace std;

// float square(int num){
//     return num * num;
// }

int main (){


cout<<"***BMI Calculator***"<<endl;
int weight;
float height, BMI;

cout<<"Enter Weight In  Kilograms"<<endl;
cin>>weight;
cout<<"Enter Height in Meters Including Decimal Points"<<endl;
cin>>height;

float HeightSquare = pow(height, 2);
BMI = weight /  HeightSquare;





if( BMI < 18.5 ){
    cout<<" Your BMI IS "<<setprecision(3)<<BMI<<endl;
    cout<<"You Are Underweight, Try to Eat Something"<<endl;
}
else if ( BMI >= 18.5 && BMI <=24.9){
    cout<<" Your BMI IS "<<setprecision(3)<<BMI<<endl;
    cout<<"You Are Normal, Dont Eat Junk FOod"<<endl;
}
else if ( BMI >= 25.0 && BMI <=29.9){
    cout<<" Your BMI IS "<<setprecision(3)<<BMI<<endl;
    cout<<"You Are Overweight, Take Some Excercise"<<endl;
}

else if ( BMI >= 30.0){
    cout<<" Your BMI IS "<<setprecision(3)<<BMI<<endl;
    cout<<"You Are Obese, You Must Join a GYM"<<endl;
}
}