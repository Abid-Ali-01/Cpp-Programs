#include <iostream>
#include <iterator>
#include <algorithm>
#include <set>
using namespace std;

int main(){


       set <int> set1 = {10, 40, 20,50,60,90};
       auto target = 40;
       auto it = set1.find(target);

       if(it != set1.end()){
         cout << "The Element " << target << " Found In Set" << endl;
       }

       else 
        {
        cout << "Element Not Found In Set" << endl;
        }
}