#ifndef TQUEUE
#define TQUEUE

#include <iostream>
using namespace std;

template <typename QueueElement>
class Queue {

public:
    Queue();
    Queue(const Queue& original);
    ~Queue();
    const Queue& operator= (const Queue& rhs);
    bool empty() const;
    void enqueue(const QueueElement& value);
    void display(ostream& out) const;
    QueueElement front() const;
    void dequeue();
    int size();
    QueueElement bottom();
    QueueElement nthElement(int n);
    Queue<QueueElement> mergedAscendinglyWith(const Queue<QueueElement>& q2);

private:
    class Node {
    public:
        QueueElement data;
        Node* next;
        Node(QueueElement value, Node* link = 0) : data(value), next(link) {}
    };
    typedef Node* NodePointer;
    NodePointer myFront, myBack;
    QueueElement* myArray;
};

template <typename QueueElement>
ostream& operator<< (ostream& out, const Queue<QueueElement>& aList);

#endif
