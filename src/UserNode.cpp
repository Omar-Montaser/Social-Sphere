#include "UserNode.hpp"
#include <iostream>
using namespace std;


int UserNode::counter=0;

UserNode::UserNode(string name):username(name),id(counter++),metadata(Metadata()){}

UserNode::UserNode(string name,Metadata metadata):username(name),id(counter++),metadata(metadata){}

void UserNode::print() const {
    cout << "ID: " << id << ", Username: " << username
         << ", Depth: " << metadata.depth
         << ", Frequency: " << metadata.frequency << endl;
}