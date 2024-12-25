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
#include "menu.hpp"

using namespace std;


int main() {
    Vector<Vector<int>> userIds = {
        {1, 2, 3}, {0, 3, 4}, {0, 4, 5}, {0, 1, 5, 6},
        {1, 2, 6, 7}, {2, 3, 7, 8}, {3, 4, 8, 9}, {4, 5, 9, 10},
        {5, 6, 10, 11}, {6, 7, 11, 12}, {7, 8, 12, 13}, {8, 9, 13, 14},
        {9, 10, 14, 15}, {10, 11, 15, 16}, {11, 12, 15, 16}, {12, 13, 16, 17},
        {13, 14, 17, 18}, {14, 15, 18, 19}, {15, 16, 19, 20}, {16, 17, 20, 21},
        {17, 18, 21, 22}, {18, 19, 22, 23}, {19, 20, 23, 24}, {20, 21, 24, 25},
        {21, 22, 25, 26}, {22, 23, 26, 27}, {23, 24, 27, 28}, {24, 25, 28, 29},
        {25, 26, 29}, {26, 27, 28}
    };
    
    User::initializeDatabase((int)userIds.getSize());//with
    int currentUser = 0;

    Graph* network = new Graph(userIds);
    displayMainMenu(*network);
}