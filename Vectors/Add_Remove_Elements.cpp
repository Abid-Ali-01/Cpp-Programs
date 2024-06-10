#include <iostream>
#include <vector>
using namespace std;

int main() {
 
vector <int> vect1 = {2,3,4,5,6,7,8,9,10};


// Insert Numbers at the end of vector
vect1.insert(vect1.end(), {50, 60});

// Insert Numbers the given location. Here +1 is the index number 1 and 100 is the value to add
vect1.insert(vect1.begin() + 1, 100); 

// Remove the element at the index Number 10
vect1.erase(vect1.begin() + 10);



for(int i = 0; i<vect1.size(); i ++){
    cout<<vect1[i]<<"  ";
}
cout<<endl;


    return 0;
}