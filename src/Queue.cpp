#include "Queue.h"

template <typename QueueElement>
Queue<QueueElement>::Queue() : myFront(NULL), myBack(NULL) {}

template <typename QueueElement>
Queue<QueueElement>::Queue(const Queue& original) {
    if (original.empty())
        myFront = myBack = NULL;
    else {
        myFront = myBack = new Queue<QueueElement>::Node(original.front());
        Queue<QueueElement>::NodePointer origPtr = original.myFront->next;
        while (origPtr != NULL) {
            myBack->next = new Queue<QueueElement>::Node(origPtr->data);
            myBack = myBack->next;
            origPtr = origPtr->next;
        }
    }
}

template <typename QueueElement>
Queue<QueueElement>::~Queue() {
    Queue<QueueElement>::NodePointer currPtr = myFront, nextPtr = NULL;
    while (currPtr != NULL) {
        nextPtr = currPtr->next;
        delete currPtr;
        currPtr = nextPtr;
    }
}

template <typename QueueElement>
const Queue<QueueElement>& Queue<QueueElement>::operator=(const Queue<QueueElement>& rhs) {
    if (this != &rhs) {
        this->~Queue();
        if (rhs.empty()) {
            myFront = myBack = NULL;
        } else {
            myFront = myBack = new Queue<QueueElement>::Node(rhs.front());
            Queue<QueueElement>::NodePointer rhsPtr = rhs.myFront->next;
            while (rhsPtr != NULL) {
                myBack->next = new Queue<QueueElement>::Node(rhsPtr->data);
                myBack = myBack->next;
                rhsPtr = rhsPtr->next;
            }
        }
    }
    return *this;
}

template <typename QueueElement>
bool Queue<QueueElement>::empty() const {
    return myFront == NULL;
}

template <typename QueueElement>
void Queue<QueueElement>::enqueue(const QueueElement& value) {
    Queue<QueueElement>::NodePointer newptr = new Queue<QueueElement>::Node(value);
    if (empty()) {
        myFront = myBack = newptr;
    } else {
        myBack->next = newptr;
        myBack = newptr;
    }
}

template <typename QueueElement>
void Queue<QueueElement>::display(ostream& out) const {
    if (empty()) {
        cerr << "Queue-empty!" << endl;
        return;
    }
    Queue<QueueElement>::NodePointer myPtr = myFront;
    while (myPtr != NULL) {
        out << myPtr->data << ' ';
        myPtr = myPtr->next;
    }
    out << endl;
}

template <typename QueueElement>
QueueElement Queue<QueueElement>::front() const {
    if (!empty())
        return myFront->data;
    else {
        cerr << "Queue Empty -- Returning garbage." << endl;
        QueueElement garbage;
        return garbage;
    }
}

template <typename QueueElement>
void Queue<QueueElement>::dequeue() {
    if (!empty()) {
        Queue<QueueElement>::NodePointer ptr = myFront;
        myFront = myFront->next;
        delete ptr;
        if (myFront == NULL)     // queue is now empty
            myBack = NULL;
    } else {
        cerr << "Queue Empty!" << endl;
    }
}

template <typename QueueElement>
ostream& operator<< (ostream& out, const Queue<QueueElement>& aQueue) {
    aQueue.display(out);
    return out;
}

template <typename QueueElement>
int Queue<QueueElement>::size() {
    int count = 0;
    NodePointer ptr = myFront;
    while (ptr != NULL) {
        ptr = ptr->next;
        count++;
    }
    return count;
}

template <typename QueueElement>
QueueElement Queue<QueueElement>::bottom() {
    if (!empty()) {
        return myBack->data;
    }
    cerr << "Queue empty: no bottom element -- returning garbage value\n";
    QueueElement garbage;
    return garbage;
}

template <typename QueueElement>
QueueElement Queue<QueueElement>::nthElement(int n) {
    Queue::NodePointer nptr = myFront;
    int counter = 1;
    while (counter < n && nptr != 0)
    {
        counter++;
        nptr = nptr->next;
    }
    if (counter == n)
        return nptr->data;
    // else
    cerr << "Queue has no " << n << "-th element -- returning a garbage value\n";
    QueueElement garbage;
    return garbage;
}

template <typename QueueElement>
Queue<QueueElement> Queue<QueueElement>::mergedAscendinglyWith(const Queue<QueueElement>& q2) {
    Queue<QueueElement> q;
    NodePointer myPtr = myFront, q2Ptr = q2.myFront;
    while (myPtr != NULL && q2Ptr != NULL) {
        if (myPtr->data < q2Ptr->data) {
            q.enqueue(myPtr->data);
            myPtr = myPtr->next;
        } else {
            q.enqueue(q2Ptr->data);
            q2Ptr = q2Ptr->next;
        }
    }
    while (myPtr != NULL) {
        q.enqueue(myPtr->data);
        myPtr = myPtr->next;
    }
    while (q2Ptr != NULL) {
        q.enqueue(q2Ptr->data);
        q2Ptr = q2Ptr->next;
    }
    return q;
}

template class Queue<int>;
template class Queue<string>;
template ostream& operator<< (ostream& out, const Queue<int>& aQueue);
template ostream& operator<< (ostream& out, const Queue<string>& aQueue);