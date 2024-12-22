#include "Vector.h"

template <typename T>
Vector<T>::Vector(int maxSize) : mySize(0), myCapacity(maxSize), myArray(nullptr) {
    myArray = new (nothrow) T[myCapacity];
    if (!myArray) {
        cerr << "Error: Memory allocation failed.\n";
        exit(1);
    }
}

template <typename T>
Vector<T>::~Vector() {
    delete[] myArray;
}

template <typename T>
Vector<T>::Vector(const Vector<T>& origList)
    : mySize(origList.mySize), myCapacity(origList.myCapacity), myArray(nullptr) {
    myArray = new (nothrow) T[myCapacity];
    if (!myArray) {
        cerr << "Error: Memory allocation failed.\n";
        exit(1);
    }
    for (int i = 0; i < mySize; i++) {
        myArray[i] = origList.myArray[i];
    }
}

// Assignment Operator
template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& rhs) {
    if (this != &rhs) {
        delete[] myArray;

        myCapacity = rhs.myCapacity;
        mySize = rhs.mySize;
        myArray = new (nothrow) T[myCapacity];
        if (!myArray) {
            cerr << "Error: Memory allocation failed.\n";
            exit(1);
        }
        for (int i = 0; i < mySize; i++) {
            myArray[i] = rhs.myArray[i];
        }
    }
    return *this;
}

// Resize the array when full
template <typename T>
void Vector<T>::resize() {
    myCapacity *= 2;
    T* newArray = new (nothrow) T[myCapacity];
    if (!newArray) {
        cerr << "Error: Memory allocation failed during resize.\n";
        exit(1);
    }
    for (int i = 0; i < mySize; i++) {
        newArray[i] = myArray[i];
    }
    delete[] myArray;
    myArray = newArray;
}

// Insert a value
template <typename T>
void Vector<T>::insert(T item, int pos) {
    if (pos < 0 || pos > mySize) {
        cerr << "Illegal location to insert -- " << pos << ". List unchanged.\n";
        return;
    }
    if (mySize == myCapacity) {
        resize();
    }
    for (int i = mySize; i > pos; i--) {
        myArray[i] = myArray[i - 1];
    }
    myArray[pos] = item;
    mySize++;
}

// Remove a value
template <typename T>
void Vector<T>::erase(int pos) {
    if (mySize == 0) {
        cerr << "List is empty.\n";
        return;
    }
    if (pos < 0 || pos >= mySize) {
        cerr << "Illegal location to delete -- " << pos << ". List unchanged.\n";
        return;
    }
    for (int i = pos; i < mySize - 1; i++) {
        myArray[i] = myArray[i + 1];
    }
    mySize--;
}

// Check if the vector is empty
template <typename T>
bool Vector<T>::empty() const {
    return mySize == 0;
}

// Access elements using []
template <typename T>
T& Vector<T>::operator[](int index) {
    if (index < 0 || index >= mySize) {
        cerr << "Error: Index out of bounds.\n";
        exit(1);
    }
    return myArray[index];
}

template <typename T>
const T& Vector<T>::operator[](int index) const {
    if (index < 0 || index >= mySize) {
        cerr << "Error: Index out of bounds.\n";
        exit(1);
    }
    return myArray[index];
}

// Display elements
template <typename T>
void Vector<T>::display(ostream& out) const {
    for (int i = 0; i < mySize; i++) {
        out << myArray[i] << " ";
    }
}

// Overloaded << operator
template <typename T>
ostream& operator<<(ostream& out, const Vector<T>& vec) {
    vec.display(out);
    return out;
}
