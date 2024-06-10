//Create a vector int, insert 10 even values using loop
#include <iostream>
#include <vector>
using namespace std;
 
int main (){

    vector <int> vect;

    // Inserting Values
    for(int i=0 ; i<=10 ; i++){
        vect.push_back(i *2 );
    }


//Printing Vector Values
for(int i = 0; i < vect.size(); i++){

    cout<<vect[i]<< " | ";
}
cout<<endl;
//Removes Last element of vector
vect.pop_back();
vect.pop_back();


//Printing Vector After
for(int i = 0; i < vect.size(); i++){
    cout<<vect[i]<< " | ";
}

}
