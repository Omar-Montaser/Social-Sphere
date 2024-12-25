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
    {1, 2}, {0, 3, 4}, {0, 4}, {1, 5}, {1, 2, 6},
    {3, 7}, {4}, {5, 8, 9}, {7, 10}, {7, 10}, {8, 9}
    };
    
    User::initializeDatabase((int)userIds.getSize());//with
    int currentUser = 0;

    Graph* network = new Graph(userIds);
    displayMainMenu(*network);
}

