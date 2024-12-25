#include "menu.hpp"
#include "User.hpp"
#include <conio.h>
#include <cstring>
#include <cstdlib>
#include<string>
#include "userDashboard.hpp"

using namespace std;
Vector<User> User::database;
void clearScreen() {
    system("CLS");
}

void displayMainMenu() {
    cout << "--- Welcome! ---\n" << endl;
    cout << "1. Login\n2. Signup\n[ESC] Exit\n" << endl;
    cout << "Choose an option: ";
    handleMainMenuChoice();
}

void displayPage(bool isLogin) {
char username[50] = "";
char password[50] = "";
size_t usernameLen = 0;
size_t passwordLen = 0;
bool showPassword = false;
clearScreen();
cout << (isLogin ? "--- Login Page ---" : "--- Signup Page ---") << endl;
cout << "[ESC] to return to the main menu\n" << endl;
cout << "Username: ";
while (true) {
    if (_kbhit()) {
        char ch = _getch();

        if (ch == 27) return;

        if (ch == '\r') {
            if (!showPassword) {
                showPassword = true;
                cout << endl << "Password: ";
            }
            else {
                if (isLogin)
                {   
                    bool found = false;
                    User foundUser;
                    User::searchUser(username, found, foundUser);
                    if (found)
                    {   if(foundUser.password == password)
                        displayMenu(foundUser);
                        else cout<<"wrong password"<<endl;
                    } 
                    else{
                        displayPage(isLogin);
                    }
                }
                else if (!isLogin)
                {
                    signup(username,password);
                }
                
            }
            continue;
        }

        if (ch == '\b' || ch == 127) {
            if (showPassword && passwordLen > 0) {
                password[--passwordLen] = '\0';
            }
            else if (!showPassword && usernameLen > 0) {
                username[--usernameLen] = '\0';
            }
            cout << ch;
            continue;
        }

        if (ch >= 32 && ch <= 126) {
            if (showPassword && passwordLen < sizeof(password) - 1) {
                password[passwordLen++] = ch;
                password[passwordLen] = '\0';
            }
            else if (!showPassword && usernameLen < sizeof(username) - 1) {
                username[usernameLen++] = ch;
                username[usernameLen] = '\0';
            }
            cout << ch;
        }
    }
}
}
void signup(string username, string password){// is it done?
    User user(username, password);
    User::database.push_back(user);
}

void handleMainMenuChoice() {
    while (true) {
        if (_kbhit()) {
            char ch = _getch();

            if (ch == 27) {
                clearScreen();
                cout << "Exiting...\n";
                exit(0);
            }

            switch (ch) {
            case '1'://login
                displayPage(true);
                return;
            case '2'://signup
                displayPage(false);
                return;
            default://any other input
                clearScreen();
                cout << "--- Welcome! ---\n" << endl;
                cout << "1. Login\n2. Signup\n[ESC] Exit\n" << endl;
                cout << "Please choose a valid option: ";
                break;
            }
        }
    }
}
