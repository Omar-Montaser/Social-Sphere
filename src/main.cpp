#include <iostream>
#include "User.hpp"
#include "PriorityQueue.hpp"
#include "Queue.hpp"
#include "Vector.hpp"
#include "Graph.hpp"
// #include "menu.hpp"
#include "userDashboard.hpp"
#include <conio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>


using namespace std;


PriorityQueue recommendFriends(Graph& userIds, int currentUser);
void displayRecommendations(PriorityQueue& pq);
void viewFriends(int currentUser, Graph& network);
void addFriend(int currentUser, Graph& network);
void viewFriendRecommendations(int currentUser,Graph& network);
void viewSocialSphere(Graph& network);

int main() {

int currentUser=0;
Vector<Vector<int>> userIds11 = {
    {1, 2, 3},//31
    {0, 3, 4},
    {0, 4, 5},
    {0, 1, 5, 6},
    {1, 2, 6, 7},
    {2, 3, 7, 8},
    {3, 4, 8, 9},
    {4, 5, 9, 10},
    {5, 6, 10, 11},
    {6, 7, 11, 12},
    {7, 8, 12, 13},
    {8, 9, 13, 14},
    {9, 10, 14, 15},
    {10, 11, 15, 16},
    {11, 12, 15, 16},
    {12, 13, 16, 17},
    {13, 14, 17, 18},
    {14, 15, 18, 19},
    {15, 16, 19, 20},
    {16, 17, 20, 21},
    {17, 18, 21, 22},
    {18, 19, 22, 23},
    {19, 20, 23, 24},
    {20, 21, 24, 25},
    {21, 22, 25, 26},
    {22, 23, 26, 27},
    {23, 24, 27, 28},
    {24, 25, 28, 29},
    {25, 26, 29},//29
    {26, 27, 28},//30
    };
    Graph *network=new Graph(userIds11);
    cout<<network->size()<<endl;
    viewSocialSphere(*network);
    while(true){
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
            viewFriends(0,*network);
            break;
        case '2':
            addFriend(0,*network);
            break;
        case '3':
            viewFriendRecommendations(0,*network);
            break;
        case '4':
            viewSocialSphere(*network);
            break;
        // case '27':
        //     loginScreen(0);
        //     break;
        default:
            cout << "Invalid choice. Press any key to try again.\n";
            _getch();
            break;
        }
    }
}

void viewFriends(int currentUser,Graph& network){
    Vector<int> userFriends = network.getFriends(currentUser);
    
    cout << "Friends of user " << currentUser << ":\n";
    for (int i = 0; i < userFriends.getSize(); i++) {
        int friendId = userFriends[i];
        cout << "Name: " <<User::database[friendId].username<< endl;
    }
    cout << "Press any key to go back to the dashboard.\n";
    _getch();
}

void addFriend(int currentUser, Graph& network) {
    int friendId;
    cout << "Enter the ID of the friend you want to add: ";
    cin >> friendId;
    while(true){
    if (friendId >= 0 && friendId < network.size()) {
        network.addFriendship(currentUser,friendId);
        cout << "Friend added successfully.\n";
    } else
        cout << "Invalid friend ID. Press any key to try again or press esc to go back.\n";
        
    char c=_getch();
        if(c==27) break; 
    }
}

void viewFriendRecommendations(int currentUser,Graph& network) {
    PriorityQueue recommendations = recommendFriends(network, currentUser);
    cout << "Recommended friends for user " << currentUser << ":\n";
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
                cout << "User ID: " << rec.userID << ", Depth: " << rec.depth
                 << ", Frequency: " << rec.frequency << endl;
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

    for (size_t node = 0; node < network.size(); ++node){
        string nodeColor = "#";
        const char hexDigits[] = "0123456789ABCDEF";
        for (int i = 0; i<3; ++i) {
            int lightComponent = 128 + (rand() % 128);
            nodeColor += hexDigits[lightComponent / 16];
            nodeColor += hexDigits[lightComponent % 16];
        }

        dotFile << "    " << node << " [style=filled, fillcolor=\"" << nodeColor << "\"];\n";

        for (int i=0;i<network.getFriends(node).getSize();i++) {
            if (node<network.getFriends(node)[i]) {
                dotFile << "    " << node << " -- " <<network.getFriends(node)[i] << ";\n";
            }
        }
    }
    dotFile << "}\n";
    dotFile.close();

    int result = system("dot -Tpng graph.dot -o graph.png");
    if (result != 0)
        cerr << "Error: Unable to generate the graph. Ensure Graphviz is installed and accessible." << endl;
    
    else {
        cout << "Graph generated successfully: graph.png" << endl;
        result = system("start graph.png");
        if (result != 0) 
            cerr << "Error: Unable to open the image file." << endl;
        
    }
}