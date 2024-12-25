#ifndef GRAPH_HPP
#define GRAPH_HPP

#include "Vector.hpp" 
#include "User.hpp"

class Graph {
public:
    Vector<Vector<int>> adjList;  
    

public:
    Graph(int numUsers);
    Graph(Vector<Vector<int>>);

    void addFriendship(int user1, int user2);
    void removeFriendship(int user1, int user2);

    const Vector<int>& getFriends(int userID) const;
    Vector<Vector<int>>& getAdjList();
    Vector<Metadata> bfs(int currentUser) const;

    int size() const;
    
};

#endif
