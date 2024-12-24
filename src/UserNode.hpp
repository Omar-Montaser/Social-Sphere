#ifndef USER_H
#define USER_H
#include <string>
using namespace std;
class Metadata {
    //This is for a user's friends
    //Will be calculated for each when traversing to find the recommended friends
    public:
        int userID;//friend id
        int depth;
        int frequency;//no. of mutual friends
        
        Metadata() : userID(0), depth(0), frequency(0) {}
        Metadata(int id,int d=0, int f=0) : userID(id), depth(d), frequency(f) {}
            bool operator<(const Metadata& other) const {
            if (depth == other.depth)
                return frequency < other.frequency; 
    
            return depth > other.depth;
        }
};

class UserNode {

    public:
    static int counter; 
    int id;
    string username;    
    Metadata metadata;//depth & frequency

    UserNode(string name);
    UserNode(string name,Metadata metadata);
    void print() const;

};
#endif