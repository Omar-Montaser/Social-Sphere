#include <iostream>
#include "PriorityQueue.hpp"
#include "Queue.hpp"
#include "Vector.hpp"
#include <queue>

using namespace std;


// Friend recommendation function
Vector<Metadata> traverseFriends(const Vector<Vector<int>>& userIds, int currentUser) {
    //using bfs
    Vector<int> freq(userIds.getSize(), 0);
    Vector<int> visited(userIds.getSize(), 0);
    Queue<Metadata> q;
    Vector<Metadata> res;

    q.enqueue(Metadata(currentUser, 0, 0));
    visited[currentUser] = 1;

    while (!q.empty()) {
        Metadata current = q.front();
        q.dequeue();

        for (int i = 0; i < userIds[current.userID].getSize(); ++i) {
            int id = userIds[current.userID][i];
            if (current.depth == 1) {
                freq[id]++;
            }
            if (!visited[id]) {
                visited[id] = 1;
                if (current.depth > 0) {
                    res.push_back(Metadata(id, current.depth + 1));
                }
                q.enqueue(Metadata(id, current.depth + 1, freq[id]));
            }
        }
    }

for(int i=0;i<res.getSize();i++){
        res[i].frequency=freq[res[i].userID];
    }
    return res;
}
PriorityQueue recommendFriends(const Vector<Vector<int>>& userIds, int currentUser) {
    Vector<Metadata> recommendations = traverseFriends(userIds, currentUser);
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

int main() {

//testing

//basic graph with depth >2
Vector<Vector<int>> userIds1 = {
    {1, 2},        
    {0, 3},        
    {0, 4},        
    {1, 5},        
    {2, 5},        
    {3, 4, 6},    
    {5}            
};

//cyclic graph with depth >2
Vector<Vector<int>> userIds2 = {
    {1, 2},        
    {0, 3, 4},     
    {0, 4, 5},     
    {1},           
    {1, 2},        
    {2, 6},        
    {5}            
};

//disconnected clusters
Vector<Vector<int>> userIds3 = {
    {1},           
    {0, 2},        
    {1},           
    {4, 5},        // User 3: Friend in isolated group
    {3, 5},        // User 4: Friends in isolated group
    {3, 4, 6},     // User 5: Friends in isolated group
    {5}            
};

//complex graph
Vector<Vector<int>> userIds4 = {
    {1, 2},        
    {0, 3, 4},     
    {0, 4, 5},     
    {1},           
    {1, 2, 6},     
    {2},           
    {4}            
};


//Fully connected graph
Vector<Vector<int>> userIds5 = {
    {1, 2, 3, 4},  
    {0, 2, 3, 4},  
    {0, 1, 3, 4},  
    {0, 1, 2, 4},  
    {0, 1, 2, 3}   
};


//Large sparse graph
Vector<Vector<int>> userIds6 = {
    {1},            
    {0, 2},         
    {1, 3},         
    {2, 4},         
    {3, 5},         
    {4, 6},         
    {5}            
};



// Star-shaped graph
Vector<Vector<int>> userIds7 = {
    {1, 2, 3, 4, 5}, 
    {0},              
    {0},              
    {0},              
    {0},              
    {0}               
};

Vector<Vector<int>> userIds8 = {
    {1, 2},           
    {0},              
    {0},              
    {4, 5},           
    {3, 5},           
    {3, 4, 6},        
    {5}               
}; 

Vector<Vector<int>> userIds9 = {
    {1, 2},           
    {0, 3, 4},        
    {0, 4},           
    {1, 5, 6},        
    {1, 2, 5},        
    {3, 4},           
    {3}               
};



Vector<Vector<int>> userIds10 = {
    {1},                
    {0, 2, 3},         
    {1, 4},            
    {1},               
    {2}               
};


int currentUser = 0;
    Vector<Metadata> userFriends = traverseFriends(userIds9, currentUser);
    // for(int i=0;i<userFriends.getSize();i++){
    //     cout<<userFriends[i].userID<<" "<<userFriends[i].depth<<" "<<userFriends[i].frequency<<endl;
    // }
    PriorityQueue recommendations = recommendFriends(userIds9, currentUser);
    cout << "Recommended friends for user " << currentUser << ":\n";
    displayRecommendations(recommendations);
}
