#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class CSV {
public:
    int age;
    string name, address;

    CSV(const string& name, int age, const string& address) : name(name), age(age), address(address) {}

};

ostream& operator<<(ostream& os, const CSV& csv) {
    os << csv.name << "," << csv.age << "," << csv.address << endl;
    return os;
}

int main() {
    CSV csv1("Abid Ali", 24, "Saryab Road Quetta");
    CSV csv2("Shahab", 35, "Ariport Road Quetta");
    
    ofstream outFile("CSVFile.txt"); 
    if (outFile.is_open()) {
        outFile << csv1;
        outFile << csv2;
        outFile.close();
        cout << "File written successfully." << endl;
    } else {
        cerr << "Error opening file!" << endl;
    }

    return 0;
}
