// #ifndef HASHMAP_H
// #define HASHMAP_H


// using namespace std;


// template <typename T>
// class HashMap {
// private:
//     class Node {
//     public:
//         string key;
//         T* value;
//         Node* next;

//         Node(const string& k, T* v);
//     };

//     Node** table;
//     int capacity;
//     int size;

//     int hashFunction(const string& key);
//     void resize();

// public:
//     explicit HashMap(int initialCapacity=10);
//     ~HashMap();

//     void insert(T* value);
//     T* get(const string& key);
//     void remove(const string& key);
//     void print();
// };
// #endif