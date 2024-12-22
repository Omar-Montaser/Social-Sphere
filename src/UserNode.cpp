#include "UserNode.h"
#include <iostream>
using namespace std;


int UserNode::counter=0;

UserNode::UserNode(string name):username(name),id(counter++),metadata(Metadata(0,0)){}

UserNode::UserNode(string name,Metadata metadata):username(name),id(counter++),metadata(metadata){}
UserNode::UserNode(string name, int id,  Metadata metadata) 
: username(name), id(id), metadata(id,metadata.depth,metadata.frequency) {}

void UserNode::print() const {
    cout << "ID: " << id << ", Username: " << username
         << ", Depth: " << metadata.depth
         << ", Frequency: " << metadata.frequency << endl;
}