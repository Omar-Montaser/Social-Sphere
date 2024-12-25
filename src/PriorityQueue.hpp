#pragma once

#include "User.hpp"
#include <string>
using namespace std;

class PriorityQueue {
//a custom priority queue to sort metadata based on depth and mutual friends
private:
    Metadata* heap;
    int size;
    int capacity;

    inline bool compare(const Metadata& m1, const Metadata& m2);
    inline void swap(Metadata& m1, Metadata& m2);
    void heapifyDown(int index);
    void buildHeap();
    void resizeHeap();

public:
    PriorityQueue();
    PriorityQueue(Metadata* data, int dataSize);
    ~PriorityQueue();

    void push(const Metadata& m);
    Metadata pop();
    Metadata top() const;
    bool empty() const;
    int getSize() const;
};