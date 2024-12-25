#include <iostream>
#include "User.hpp"
#include "PriorityQueue.hpp"
#include "Queue.hpp"
#include "Vector.hpp"
#include "Graph.hpp"
#include <conio.h>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include 

using namespace std;

void loginScreen() {
    while (true) {
        clearScreen();
        displayMainMenu();
        handleMainMenuChoice();
    }
}

void viewFriends(int currentUser, Graph& network) {
system("cls");
while (true) {
    Vector<int> userFriends = network.getFriends(currentUser);

    cout << "Friends of user " << currentUser << ":\n";
    if(userFriends.getSize()==0) {
        cout<<"No friends yet. Press ESC to go back to the dashboard\n";
        char choice = _getch();
        if (choice == 27) break;
            else continue;
    }
    for (int i = 0; i < userFriends.getSize(); ++i) {
        int friendId = userFriends[i];
        cout << "User ID: " << friendId
             << " | Username: " << User::database[friendId].username << endl;
    }
    cout<<"Choose a userId to removeor press esc to go back to the dashboard.: ";
    int choice = _getch();
    if(choice == 27) break;
    int id; cin>>id;
    if(id < 0 || id >= network.size()) {
        cout<<"Invalid user ID. Try again.\n";
        continue;
    }
    if(userFriends.getSize()!=0) network.removeFriendship(currentUser, id);
    }
}
void addFriend(int currentUser, Graph& network) {
    system("cls");
    while (true) {
        cout << "Enter the ID of the friend you want to add (or press ESC to go back): ";

        char input = _getch();
        if (input == 27) // ESC key
            break;

        int friendId;
        cin >> friendId;

        // Validate the friendId
        if (friendId < 0 || friendId >= network.size()||friendId==currentUser) {
            cout << "Invalid user ID. Try again.\n";
            continue;
        }

        // Check if friendId is already a friend
        Vector<int> friends = network.getFriends(currentUser);
        bool found = false;
        for (int i = 0; i<friends.getSize(); ++i) {
            if (friends[i] == friendId) {
                found = true;
                break;
            }
        }
        if(found) {
            cout<<"User is already a friend. Try again.\n";
            continue;
        }
        // Add friendship
        network.addFriendship(currentUser, friendId);
        cout << "Friend added successfully.\n";
    }
}


void viewFriendRecommendations(int currentUser, Graph& network) {
system("cls");
    PriorityQueue recommendations = recommendFriends(network, currentUser);
    cout << "Recommended friends:\n";
    displayRecommendations(recommendations);
    cout << "Press any key to go back to the dashboard.\n";
    _getch();
}

PriorityQueue recommendFriends(Graph& userIds, int currentUser) {
    Vector<Metadata> recommendations = userIds.bfs(currentUser);
    PriorityQueue pq;
    for (int i = 0; i < recommendations.getSize(); ++i)
        pq.push(recommendations[i]);
    return pq;
}

void displayRecommendations(PriorityQueue& pq) {
    while (!pq.empty()) {
        Metadata rec = pq.pop();
        cout << "User: " << User::database[rec.userID].username
             << ", Mutual Friends: " <<rec.frequency<< endl;
    }
}

void viewSocialSphere(Graph& network) {
    srand(static_cast<unsigned>(time(nullptr)));

    ofstream dotFile("graph.dot");
    if (!dotFile.is_open()) {
        cerr << "Error: Unable to create the .dot file." << endl;
        return;
    }

    dotFile << "graph G {\n";
    dotFile << "    bgcolor=black;\n";
    dotFile << "    edge [color=white];\n";

    for (size_t node = 0; node < network.size(); ++node) {
        string nodeColor = "#";
        const char hexDigits[] = "0123456789ABCDEF";
        for (int i = 0; i < 3; ++i) {
            int lightComponent = 128 + (rand() % 128);
            nodeColor += hexDigits[lightComponent / 16];
            nodeColor += hexDigits[lightComponent % 16];
        }

        dotFile << "    " << node << " [style=filled, fillcolor=\"" << nodeColor << "\"];\n";

        for (int i = 0; i < network.getFriends(node).getSize(); ++i) {
            if (node < network.getFriends(node)[i]) {
                dotFile << "    " << node << " -- " << network.getFriends(node)[i] << ";\n";
            }
        }
    }
    dotFile << "}\n";
    dotFile.close();

    int result = system("dot -Tpng graph.dot -o graph.png");
    if (result != 0) {
        cerr << "Error: Unable to generate the graph. Ensure Graphviz is installed and accessible." << endl;
    } else {
        cout << "Graph generated successfully: graph.png" << endl;
        system("start graph.png");
    }
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
