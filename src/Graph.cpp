#include "Graph.hpp" 
#include "User.hpp"
#include "Queue.hpp"

Graph::Graph(int numUsers) {
    adjList.resize(numUsers, Vector<int>());
}
Graph::Graph(Vector<Vector<int>> v){
    adjList = v;
}

void Graph::addFriendship(int user1, int user2) {
    adjList[user1].push_back(user2);
    adjList[user2].push_back(user1);
}

void Graph::removeFriendship(int user1, int user2) {
    adjList[user1].remove(user2);
    adjList[user2].remove(user1);
}

const Vector<int>& Graph::getFriends(int userID) const {
    return adjList[userID];
} 

Vector<Vector<int>>& Graph::getAdjList(){
    return adjList;
}
int Graph::size() const{
    return adjList.getSize();
}
Vector<Metadata> Graph::bfs(int currentUser) const {
    Vector<int> freq(adjList.getSize(), 0);
    Vector<int> visited(adjList.getSize(), 0);
    Queue<Metadata> q;
    Vector<Metadata> res;

    q.enqueue(Metadata(currentUser, 0, 0));
    visited[currentUser] = 1;

    while (!q.empty()) {
        Metadata current = q.front();
        q.dequeue();

        for (int i = 0; i < adjList[current.userID].getSize(); ++i) {
            int id = adjList[current.userID][i];
            if (current.depth == 1)
                freq[id]++;
            
            if (!visited[id]) {
                visited[id] = 1;
                if (current.depth > 0)
                    res.push_back(Metadata(id, current.depth + 1));
                q.enqueue(Metadata(id, current.depth + 1, freq[id]));
            }
        }
    }

for(int i=0;i<res.getSize();i++)
        res[i].frequency=freq[res[i].userID];

    return res;
}
