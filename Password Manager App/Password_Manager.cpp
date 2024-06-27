#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class PassManager {
public:
    string platform;
    string email;
    string password;
    fstream file;

    string incrementCharsByTwo(const string& input) {
        string result = input;
        for (char& c : result) {
            c += 2;
        }
        return result;
    }

    void Encrypt() {
        cout << "Enter Platform: ";
        cin.ignore(); // Clear the newline character from the input buffer
        getline(cin, platform);
        cout << "Enter Email: ";
        getline(cin, email);
        cout << "Enter Password: ";
        getline(cin, password);

        // Increment each character by 2
        string incrementedPlatform = incrementCharsByTwo(platform);
        string incrementedEmail = incrementCharsByTwo(email);
        string incrementedPassword = incrementCharsByTwo(password);

        file.open("passManager.txt", ios::out | ios::app);
        if (!file) {
            cerr << "Error opening file!" << endl;
            return;
        }

        file << "Platform: " << incrementedPlatform << endl;
        file << "Email: " << incrementedEmail << endl;
        file << "Password: " << incrementedPassword << endl;
        file << "---------------------------------------------------------" << endl;

        file.close();
        if (file.fail()) {
            cerr << "Error closing file!" << endl;
        }
    }
void Decrypt() {
    cout << "Enter Password: ";
    string code;
    cin.ignore(); // Clear the newline character from the input buffer
    getline(cin, code);
    if (code == "Abidali") {
        file.open("passManager.txt", ios::in);
        if (!file) {
            cerr << "Error opening file!" << endl;
            return;
        }

        string line;
        while (getline(file, line)) {
            bool skipSpace = false;
            for (char& c : line) {
                if (c == ' ') {
                    skipSpace = true;
                    continue; // Skip spaces
                }
                if (skipSpace) {
                    if (c != '\n' && c != '\r' && c != '-') { // avoid decrypting newline and separator characters
                        c -= 2;
                    }
                    skipSpace = false;
                } else {
                    if (c != '\n' && c != '\r' && c != '-') { // avoid decrypting newline and separator characters
                        c -= 2;
                    }
                }
            }
            cout << line << endl;
        }

        file.close();
        if (file.fail()) {
            cerr << "Error closing file!" << endl;
        }
    } else {
        cout << "Incorrect password!" << endl;
    }
}



};

int main() {
    int choice;
    PassManager pm;
    cout << "Enter Your Choice" << endl;
    cout << "Press 1 To Add Info & Encrypt It" << endl;
    cout << "Press 2 To Print File Data" << endl;
    cin >> choice;

    switch (choice) {
        case 1:
            pm.Encrypt();
            break;
        case 2:
            pm.Decrypt();
            break;
        default:
            cerr << "Invalid choice!" << endl;
            break;
    }
    return 0;
}
