#include <iostream>
#include <fstream>
using namespace std;

class LoginSystem {
    string username, email, password;
    fstream file;
    string searchname, searchpass, searchemail;

public:
    void signup() {
        cout << "Enter Username: ";
        cin.ignore(); // Clear input buffer
        getline(cin, username);
        cout << "Enter Email: ";
        getline(cin, email);
        cout << "Enter Password: ";
        getline(cin, password);
        cout << "Account Created Successfully! ";
        // Sending entered data into file
        file.open("loginData.txt", ios::out | ios::app);
        file << username << "," << email << "," << password << endl;
        file.close();
    }

    void login() {
        cout << "---------LOGIN----------" << endl;
        cout << "Enter Username: ";
        cin.ignore(); // Clear input buffer
        getline(cin, searchname);
        cout << "Enter Password: ";
        getline(cin, searchpass);

        file.open("loginData.txt", ios::in);
        bool found = false;
        while (getline(file, username, ',') && getline(file, email, ',') && getline(file, password)) {
            if (username == searchname && password == searchpass) {
                cout << "Login Successful" << endl;
                cout << "\nUsername: " << username << endl;
                cout << "\nEmail: " << email << endl;
                cout << "\nPassword: " << password << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Invalid Credentials! Try Again" << endl;
        }
        file.close();
    }

    void forget() {
        cout << "Enter Username: ";
        cin.ignore(); // Clear input buffer
        getline(cin, searchname);
        cout << "Enter Email Address: ";
        getline(cin, searchemail);

        file.open("loginData.txt", ios::in);
        bool found = false;
        while (getline(file, username, ',') && getline(file, email, ',') && getline(file, password)) {
            if (email == searchemail && username == searchname) {
                cout << "Password Found: " << password << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "No Account Found!" << endl;
        }
        file.close();
    }
};

int main() {
    LoginSystem obj;
    char choice;
    while (true) {
        cout << "\n 1: Sign Up";
        cout << "\n 2: Login";
        cout << "\n 3: Forget Password";
        cout << "\n 4: Exit";

        cout << "\n Enter Your Choice: ";
        cin >> choice;

        switch (choice) {
            case '1':
                obj.signup();
                break;
            case '2':
                obj.login();
                break;
            case '3':
                obj.forget();
                break;
            case '4':
                return 0;
            default:
                cout << "Invalid Input" << endl;
        }
    }
}