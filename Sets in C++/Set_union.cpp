#include <iostream>
#include <set>
#include <algorithm> // set_union
#include <iterator>  // inserter
using namespace std;
 
int main() {

    set <int> set1= {10,20,30,40};
    set <int> set2= {50,60,70,80};
    set <int> uniSet;


    //set_union() is already defined in the STL Standrard Template Library of Algorithm
    set_union(set1.begin(), set1.end(), set2.begin(), set2.end(),
    inserter(uniSet, uniSet.begin()));

cout<<"Union of Set A and B Is : "<<endl;
//Range Based For Loop
for(const auto &elem : uniSet)


cout<<elem<<" ";

}