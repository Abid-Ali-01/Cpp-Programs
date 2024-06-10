#include <iostream>
#include <set>
using namespace std;
 
int main() {
    // Create a set of integers
    set<int> mySet = {10,20,30,40};
    set<int> mySet2 = {50,60,70,80};
    // Insert elements into the set
    // mySet.insert(10);
    // mySet.insert(20);
    // mySet.insert(30);
    // mySet.insert(40);

    // Attempt to insert a duplicate element (will not be added)
    mySet.insert(20);

    // Print the elements of the set
    cout << "Elements in the set: ";
    for (const int& elem : mySet) {
        cout << elem << " ";
    }
    cout << endl;

    // Remove an element from the set
    mySet.erase(20);

    // Print the elements of the set after removal
    cout << "Elements in the set after removal: ";
    for (const int& elem : mySet) {
        cout << elem << " ";
    }
    cout << endl;

    // Check if an element exists in the set
    int searchElement = 30;
    if (mySet.find(searchElement) != mySet.end()) {
        cout << searchElement << " is in the set." << endl;
    } else {
        cout << searchElement << " is not in the set." << endl;
    }

    return 0;
}
