#include "PriorityQueue.hpp"
#include <iostream>

using namespace std;

inline bool PriorityQueue::compare(const Metadata& m1, const Metadata& m2) {
    return (m1.depth < m2.depth) || (m1.depth == m2.depth && m1.frequency > m2.frequency);
}

inline void PriorityQueue::swap(Metadata& m1, Metadata& m2) {
    Metadata temp = m1;
    m1 = m2;
    m2 = temp;
}

void PriorityQueue::heapifyDown(int index) {
    int left, right, highestPriority;
    while (true) {
        left = 2 * index + 1;
        right = 2 * index + 2;
        highestPriority = index;

        if (left < size && compare(heap[left], heap[highestPriority])) {
            highestPriority = left;
        }
        if (right < size && compare(heap[right], heap[highestPriority])) {
            highestPriority = right;
        }

        if (highestPriority == index) break;

        swap(heap[index], heap[highestPriority]);
        index = highestPriority;
    }
}

void PriorityQueue::buildHeap() {
    for (int i = (size / 2) - 1; i >= 0; --i) {
        heapifyDown(i);
    }
}

void PriorityQueue::resizeHeap() {
    capacity *= 2;
    Metadata* newHeap = new Metadata[capacity];
    for (int i = 0; i < size; ++i) {
        newHeap[i] = heap[i];
    }
    delete[] heap;
    heap = newHeap;
}

PriorityQueue::PriorityQueue(): size(0), capacity(2) {
    heap = new Metadata[capacity];
}
PriorityQueue::PriorityQueue(Metadata* data, int dataSize) : size(dataSize), capacity(dataSize > 0 ? dataSize * 2 : 2) {
    heap = new Metadata[capacity];
    for (int i = 0; i < dataSize; ++i) {
        heap[i] = data[i];
    }
    buildHeap();
}

PriorityQueue::~PriorityQueue() {
    delete[] heap;
}

void PriorityQueue::push(const Metadata& m) {
    if (size == capacity) {
        resizeHeap();
    }
    heap[size++] = m;
    int index = size - 1;
    while (index > 0 && compare(heap[index], heap[(index - 1) / 2])) {
        swap(heap[index], heap[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

Metadata PriorityQueue::pop() {
    if (empty()) {
        cout << "Error: Priority queue is empty." << endl;
        return { NULL, -1, -1 };
    }
    Metadata top = heap[0];
    heap[0] = heap[--size];
    heapifyDown(0);
    return top;
}

Metadata PriorityQueue::top() const {
    if (empty()) {
        cout << "Error: Priority queue is empty." << endl;
        return { NULL, -1, -1 };
    }
    return heap[0];
}

bool PriorityQueue::empty() const {
    return size == 0;
}

int PriorityQueue::getSize() const {
    return size;
}
