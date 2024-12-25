#include <iostream>
#include <conio.h>
#include "menu.hpp"
#include "userDashboard.hpp"
#include "User.hpp"

using namespace std;

void loginScreen() {
    while (true) {
        clearScreen();
        displayMainMenu();
        handleMainMenuChoice();
    }
}

void viewFriends() {

}

void addFriend() {
}

void viewFriendRecommendations() {
}

void viewSocialSphere() {
}

void displayMenu(User currentUser) {
    while (true) {
        system("CLS");
        cout << "----- User Dashboard -----\n";
        cout << "1. View Friends\n";
        cout << "2. Add Friend\n";
        cout << "3. View Friend Recommendations\n";
        cout << "4. View Social Sphere\n";
        cout << "Press ESC to log out\n";

        char choice = _getch();

        switch (choice) {
        case '1':
            viewFriends();
            break;
        case '2':
            addFriend();
            break;
        case '3':
            viewFriendRecommendations();
            break;
        case '4':
            viewSocialSphere();
            break;
        case '27':
            loginScreen();
            break;
        default:
            cout << "Invalid choice. Press any key to try again.\n";
            _getch();
            break;
        }
    }
}
