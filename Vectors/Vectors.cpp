#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Create a vector of integers
    vector<int> vec;

    //We can also add elements to vector at the time of declaration 
    // Create a vector of integers and initialize it with elements
    //vector<int> vec = {1, 2, 3, 4, 5};

    // Add elements to the vector
    for (int i = 1; i <= 10; ++i) {
        vec.push_back(i);
    }

    // Print the elements of the vector
    cout << "Vector elements: ";
    for (int i = 0; i < vec.size(); ++i) {
        cout << vec[i] << " ";
    }
    cout << endl;

    return 0;
}
