#pragma once
#include <string>
#include "Vector.hpp"
using namespace std;
class Metadata {
    //will be calculated for each of my user's
    //friends when traversing to find the recommended ones suing the priority queue
    public:
        int userID;
        int depth;
        int frequency;
        
        Metadata() : userID(0), depth(0), frequency(0) {}
        Metadata(int id,int d=0, int f=0) : userID(id), depth(d), frequency(f) {}
            bool operator<(const Metadata& other) const {
            if (depth == other.depth)
                return frequency < other.frequency; 
    
            return depth > other.depth;
        }
};

class User {
    public:
        static Vector<User> database;
        static int counter; 
        int id;
        string username;    
        string password;
    
    User();
    User(string name, string password);

    static void initializeDatabase(int size);
    static void searchUser(string name, bool& found,User& foundUser);
    static void searchUser(string name, bool& found);
};