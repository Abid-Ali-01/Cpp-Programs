#include <iostream>
#include <iterator>
#include <algorithm>
#include <set>
using namespace std;


bool isSubset(const set <int> &set1,const set <int> &set2){

    return includes(set1.begin(),set1.end(),  set2.begin(), set2.end());

}

int main(){



    set<int> set1 = {1, 3, 5, 7, 9};
    set<int> set2 = {3,5,2};
    
    if(isSubset(set1, set2) == false){
        cout<<"Set 2 is not a sub set of Set 1"<<endl;
    }
    else{
        cout<<"Set 2 is a sub set of Set 1"<<endl;
    }
    return 0;
}