#include "PriorityQueue.h"
#include <stdexcept>  
#include <algorithm> 

void PriorityQueue::heapify(int idx) {
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    int largest = idx;

    if (left < heap.size() && heap[left] < heap[largest]) {
        largest = left;
    }

    if (right < heap.size() && heap[right] < heap[largest]) {
        largest = right;
    }

    if (largest != idx) {
        std::swap(heap[idx], heap[largest]);
        heapify(largest);
    }
}

void PriorityQueue::push(const Metadata& item) {
    heap.push_back(item);
    int idx = heap.size() - 1;

    // Move the new element to the correct position in the heap
    while (idx > 0 && heap[(idx - 1) / 2] < heap[idx]) {
        std::swap(heap[idx], heap[(idx - 1) / 2]);
        idx = (idx - 1) / 2;
    }
}

// Pop the top element from the heap
Metadata PriorityQueue::pop() {
    if (heap.empty()) {
        throw std::runtime_error("Heap is empty");
    }

    // Swap the root element with the last element and remove the last element
    std::swap(heap[0], heap[heap.size() - 1]);
    Metadata top = heap.back();
    heap.pop_back();

    // Reheapify the heap after removal
    heapify(0);
    return top;
}

// Check if the heap is empty
bool PriorityQueue::empty() const {
    return heap.empty();
}

// Get the size of the heap
int PriorityQueue::size() const {
    return heap.size();
}

// Peek at the top element without removing it
const Metadata& PriorityQueue::top() const {
    if (heap.empty()) {
        throw std::runtime_error("Heap is empty");
    }
    return heap[0];
}
