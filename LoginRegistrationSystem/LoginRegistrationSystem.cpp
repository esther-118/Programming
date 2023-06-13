#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

bool checkLogin () { // check for login validity
    string username, password, uname, pword;
    cout << "Type in your username: ";
    cin >> username;
    cout << "Type in your password: ";
    cin >> password;

    ifstream MyReadFile(username + ".txt"); // look for the username
    getline(MyReadFile, uname);
    getline(MyReadFile, pword); // read in the password from the txt

    if (uname == username && pword == password) {
        return true;
    }
    else {
        return false;
    }
}

bool checkUsername (string username) { // username validity
    if (username.length() < 3) {
        cout << "Username length must be longer than 3!";
        return false;
    }
    else {
        return true;
    }
}

bool checkPassword (string password) {
    if (password.length() < 5) { // password validity
        cout << "Password length must be longer than 5!";
        return false;
    }
    else {
        return true;
    }
}

int main () {
    string status;
    cout << "Hello and welcome to our website." << endl;
    cout << "Type in yes to register or no to login" << endl;
    cin >> status;
    string username, password;
    if (status == "yes" || status == "Yes") { // register
        bool usernameStatus = false;
        bool passwordStatus = false;
        while (usernameStatus == false) {
            cout << "Type in your username: "; cin >> username;
            usernameStatus = checkUsername(username);
        }
        while (passwordStatus == false) {
            cout << "Type in your password: "; cin >> password;
            passwordStatus = checkPassword(password);
        }
        
        cout << "Type in your password: "; cin >> password;
        ofstream file (username + ".txt");
        file << username << endl << password;
    }
    else { // login
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