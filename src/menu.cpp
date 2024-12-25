#include "menu.hpp"
#include "User.hpp"
#include "userDashboard.hpp"
#include <conio.h>
#include <cstring>
#include <cstdlib>
#include <string>

using namespace std;
void clearScreen() {
    system("CLS");
}

void displayMainMenu(Graph& network) {
    clearScreen();
    cout << "--- Welcome! ---\n" << endl;
    cout << "1. Login\n2. Signup\n[ESC] Exit\n" << endl;
    cout << "Choose an option: ";
    handleMainMenuChoice(network);
}

void displayPage(bool isLogin,Graph& network) {
    string username;
    string password;
    bool showPassword = false;

    clearScreen();
    cout << (isLogin ? "--- Login Page ---" : "--- Signup Page ---") << endl;
    cout << "[ESC] to return to the main menu\n" << endl;
    cout << "Username: ";

    while (true) {
        if (_kbhit()) {
            char ch = _getch();

            if (ch == 27) displayMainMenu(network);

            if (ch == '\r') {
                if (!showPassword) {
                    showPassword = true;
                    cout << endl << "Password: ";
                } else {
                    if (isLogin) {
                        bool found = false;
                        User foundUser;
                        User::searchUser(username, found, foundUser);//
                        if (found) {
                            if (foundUser.password == password)
                                displayMenu(foundUser,network);
                            else
                                cout << "Wrong password" << endl;
                        } else {
                            displayPage(isLogin,network);
                        }
                    }
                    else signup(username, password, network);
                }
                continue;
            }

            if (ch == '\b' || ch == 127) {
                if (showPassword && !password.empty()) {
                    password.pop_back();
                } else if (!showPassword && !username.empty()) {
                    username.pop_back();
                }
                cout << "\b \b";
                continue;
            }

            if (ch >= 32 && ch <= 126) {
                if (showPassword) {
                    password += ch;
                    cout << '*';
                } else {
                    username += ch;
                    cout << ch;
                }
            }
        }
    }
}

void signup(string username, string password, Graph& network){

     for (int i = 0; i < User::database.getSize(); ++i)
        if (User::database[i].username == username) {
            cout << "Username already exists. Please try again.\n";
            return;
        }
    User user(username, password);
    User::database.push_back(user);
    Vector<int> v;
    network.adjList.push_back(v);
    displayMenu(user,network);
}
void handleMainMenuChoice(Graph& network) {
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
                displayPage(true,network);
                return;
            case '2'://signup
                displayPage(false,network);
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