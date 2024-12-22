#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <vector>
#include "UserNode.h"
class PriorityQueue {
private:
    std::vector<Metadata> heap;
    void heapify(int idx);

public:
    void push(const Metadata& item);
    Metadata pop();
    bool empty() const;
    int size() const;

    const Metadata& top() const;
};

#endif
