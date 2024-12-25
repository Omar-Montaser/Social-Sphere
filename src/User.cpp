#include "User.hpp"
#include <iostream>
using namespace std;


int User::counter=0;
Vector<User> User::database;

User::User():username(""){}
User::User(string name, string password):username(name),password(password),id(counter++){}


void User::initializeDatabase(){
        Vector<string> names = {
        "Alice", "Bob", "Charlie", "David", "Eve",
        "Frank", "Grace", "Hank", "Ivy", "Jack",
        "Kara", "Liam", "Mona", "Nate", "Olivia",
        "Paul", "Quinn", "Rita", "Sam", "Tina",
        "Uma", "Victor", "Wendy", "Xander", "Yara", "Zane"
    };
    
    for (int i=0;i<names.getSize();i++)
        database.push_back(User(names[i],"pass"));
}

void User::searchUser(string name, bool& found,User& foundUser) {
    for (int i = 0; i <database.getSize(); ++i) {
        if (database[i].username==name)
            foundUser=database[i];
            return;
    }
}
