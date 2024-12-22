// #include "HashMap.h"
// #include <iostream>

// using namespace std;

// template <typename T>
// HashMap<T>::Node::Node(const string& k, T* v) : key(k), value(v), next(nullptr) {}

// HashMap::HashMap(int initialCapacity):capacity(initialCapacity), size(0) {
//     table = new Node*[capacity];
//     for (int i = 0; i < capacity; i++) {
//         table[i] = nullptr;
//     }
// }
// HashMap::~HashMap() {
//     for (int i = 0; i < capacity; i++) {
//         Node* current = table[i];
//         while (current) {
//             Node* temp = current;
//             current = current->next;
//             delete temp;
//         }
//     }
//     delete[] table;
// }

// int HashMap::hashFunction(const string& key) {
//     int asciiSum;
//     for (char c : key) {
//         asciiSum+=c;
//     }
//     return asciiSum % capacity;
// }

// void HashMap::insert(User* value) {
//     string key = value->username;
//     int index = hashFunction(key);

//     Node* newNode = new Node(key, value);

//     if (table[index] == nullptr)
//         table[index] = newNode;
//     else {
//         //chaining
//         Node* temp = table[index];
//         while (temp != nullptr) {
//             if (temp->key == key) {
//                 cout << "Username: '" << key << "' already exists!" << endl;
//                 delete newNode;  //to avoid memory leak
//                 return;
//             }
//             temp = temp->next;
//         }
//         temp->next=newNode;//place at the end
//     }

//     size++;

//     if (static_cast<float>(size) / capacity > 0.75) {
//         resize();
//         //TODO load factor
//     }
// }

// User* HashMap::get(const string& key) {
//     int index = hashFunction(key);
//     Node* current = table[index];
//     while (current != nullptr) {
//         if (current->key == key)
//             return current->value;
//         current = current->next;
//     }
//     return nullptr;
// }
// void HashMap::remove(const string& key) {
//     int index = hashFunction(key);
//     Node* current = table[index];
//     Node* prev = nullptr;

//     while (current != nullptr) {
//         if (current->key == key) {
//             if (prev == nullptr)
//                 table[index] = current->next;
//              else 
//                 prev->next = current->next;
            
//             delete current;
//             size--;
//             cout<<"Key '"<<key<<"' removed."<<endl;
//             return;
//         }
//         prev = current;
//         current = current->next;
//     }
//     cout << "Key '" << key << "' not found!" << endl;
// }

// void HashMap::resize() {
//     int oldCapacity = capacity;
//     capacity *= 2;
//     Node** oldTable = table;

//     table = new Node*[capacity];
//     for (int i = 0; i < capacity; i++)
//         table[i] = nullptr;

//     for (int i = 0; i < oldCapacity; i++) {
//         Node* current = oldTable[i];
//         while (current != nullptr) {
//             insert(current->value);
//             Node* temp = current;
//             current = current->next;
//             delete temp;
//         }
//     }

//     delete[] oldTable;
// }
// void HashMap::print() {
//     for (int i = 0; i < capacity; i++) {
//         if (table[i] != nullptr) {
//             Node* current = table[i];
//             while (current != nullptr) {
//                 cout << "User: " << current->key 
//                 << ", Friends: ";
//                     current->value->printFriends();
//                 current = current->next;
//             }
//         }
//     }
// }