#include <iostream>
#include <vector>
using namespace std;

vector <int> addvector(vector<int> vect1,  vector<int> vect2 ){
    if(vect1.size() != vect2.size()){
        cout<<"Vectors Size Are Not Same"<<endl;
        return {};
    }
    vector <int> result(vect1.size());

for(int i =0; i<vect1.size(); i ++){
    result[i]= vect1[i] + vect2[i];
}
return result;
}


//End Of Function
int main() {
 
vector <int> vect1 = {2,3,4,5,6,7,8,9,10};
vector <int> vect2 = {2,3,4,5,6,7,8,9,10};

//Insert Numbers at the end of vector
 vect1.insert(vect1.end(), {50, 60});
 vect2.insert(vect2.end(), {70,80});

//Remove an element at a certain location
 vect1.erase(vect1.begin() + 2);
 vect2.erase(vect2.begin() + 2);

vector <int> result= addvector(vect1, vect2);

for(int i = 0; i<result.size(); i ++){
    cout<<result[i]<<"  ";
}
cout<<endl;
    return 0;
}