#include "User.hpp"
#include <iostream>
using namespace std;


int User::counter=0;
Vector<User> User::database;

User::User():username(""){}
User::User(string name, string password):username(name),password(password),id(counter++){}


void User::initializeDatabase(int size){
        Vector<string> names1 = {
        "Omar", "Ahmed", "Mohamed", "Susan", "Peter",
        "Mahmoud", "Grace", "Hank", "Ivy", "Jack",
        "Hamada", "John", "Mona", "Nate", "Olivia",
        "Abdelrahman", "Dana", "Rita", "Sam", "Fotoh",
        "Abdallah", "Sara", "Montaser", "Xander", "Feras", "Naguib",
        "Abdelaziz", "David", "Kevin", "Hani"
        };
    for (int i=0;i<size;i++)
        database.push_back(User(names1[i],"pass"));
}

void User::searchUser(string name, bool& found,User& foundUser) {
    for (int i = 0; i <database.getSize(); ++i) {
        if (database[i].username==name){
            foundUser=database[i], found=true;
            return;
           }
    }
    found=false;
}
void User::searchUser(string name, bool& found) {
    for (int i = 0; i <database.getSize(); ++i) {
        if (database[i].username==name){
            found=true;
            return;
        }
    }
    found=false;
}
