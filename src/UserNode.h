#ifndef USER_H
#define USER_H
#include <string>
using namespace std;

struct Metadata {
    int userID;
    int depth;
    int frequency;

    Metadata(int id,int d=0, int f=0) : userID(id), depth(d), frequency(f) {}
    bool operator<(const Metadata& other) const {
        if (depth == other.depth) {
            return frequency < other.frequency; 
        }
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
    UserNode(string name,int id, Metadata metadata);


    void print() const;

};
#endif