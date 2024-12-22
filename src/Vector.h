#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <new>
using namespace std;

template <typename T>
class Vector {
private:
    int mySize;       
    int myCapacity;    
    T* myArray;      

    void resize();    
public:
    Vector(int maxSize = 1024);

    ~Vector();

    Vector(const Vector& origList);

    Vector& operator=(const Vector& rhs);

    void insert(T item, int pos);

    void erase(int pos);

    bool empty() const;

    T& operator[](int index);
    const T& operator[](int index) const;

    void display(ostream& out) const;

    int size() const { return mySize; }
};

template <typename T>
ostream& operator<<(ostream& out, const Vector<T>& vec);

#endif
