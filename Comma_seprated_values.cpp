#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Person {
public:
    int age;
    string name, address;

    Person(const string& name, int age, const string& address) : name(name), age(age), address(address) {}

};

ostream& operator<<(ostream& os, const Person& p) {
    os << p.name << "," << p.age << "," << p.address << endl;
    return os;
}

int main() {
    Person p1("Abid Ali", 24, "Saryab Road Quetta");
    Person p2("Shahab", 35, "Ariport Road Quetta");
    
    ofstream outFile("CSVFile.txt"); 
    if (outFile.is_open()) {
        outFile << p1;
        outFile << p2;
        outFile.close();
        cout << "File written successfully." << endl;
    } else {
        cerr << "Error opening file!" << endl;
    }

    return 0;
}
