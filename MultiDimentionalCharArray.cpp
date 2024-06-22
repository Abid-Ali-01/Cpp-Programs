#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main (){


string info [10][30] = {
        {"Quetta", "Capital of Balochistan"},
        {"Karachi", "Capital of Sindh"},
        {"Peshawar", "Capital of KPK"},
        {"Lahore", "Capital of Punjab"},
        {"Islamabad", "Capital of Pakistan"}};

cout<<left <<setw(12)<<"City"<<"Info"<<endl;
cout<<left <<setw(10)<<"========== "<<" ======================="<<endl;
for(int i =0 ; i<=5; i++){

cout<<setw(12) <<info[i][0] <<info[i][1]<<endl;

}

}
