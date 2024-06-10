#include <iostream>
#include <iterator>
#include <algorithm>
#include <set>
using namespace std;


set <int> intersection(const set <int> &set1, const set <int> &set2){
    
    set<int> intersactionSet; 

    set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(),
    inserter(intersactionSet, intersactionSet.begin()));

    return intersactionSet;
}

int main(){
    set <int> set1 = {10,20,30,40,50};
    set <int> set2 = {10, 40, 20,50,60,90};

    set <int> IntersectionSet = intersection(set1,set2);


    cout<<"Intersecting Elements of Set1 and Set2 Are : "<<endl;
    for(const auto  &elem : IntersectionSet){

        cout<<elem<<" ";

}

}


