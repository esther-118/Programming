#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

bool checkLogin () {
    string username, password, uname, pword;
    cout << "Type in your username: ";
    cin >> username;
    cout << "Type in your password: ";
    cin >> password;

    ifstream MyReadFile(username + ".txt");
    getline(MyReadFile, uname);
    getline(MyReadFile, pword);

    if (uname == username && pword == password) {
        return true;
    }
    else {
        return false;
    }
}

int main () {
    string status;
    cout << "Hello and welcome to our website." << endl;
    cout << "Type in yes to register or no to login" << endl;
    cin >> status;
    string username, password;
    if (status == "yes" || status == "Yes") {
        cout << "Type in your username: "; cin >> username;
        cout << "Type in your password: "; cin >> password;
        ofstream file (username + ".txt");
        file << username << endl << password;
    }
    else {
        bool login = checkLogin();
        if (!login) {
            cout << "Invalid login" << endl;
            system("pause");
            return 0;
        }
        else {
            cout << "Login successful" << endl;
            system("pause");
            return 0;
        }
    }
}