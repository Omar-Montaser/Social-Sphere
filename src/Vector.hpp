#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <stdexcept>
#include <initializer_list>
using namespace std;

template <typename T>
class Vector {
public:
    Vector();
    Vector(size_t count, const T& value);
    Vector(initializer_list<T> init);
    ~Vector();

    Vector(const Vector& other);
    Vector(Vector&& other) noexcept;

    Vector& operator=(const Vector& other);
    Vector& operator=(Vector&& other) noexcept;

    T& operator[](size_t index);
    const T& operator[](size_t index) const;
    T& at(size_t index);
    const T& at(size_t index) const;
    T& front();
    const T& front() const;
    T& back();
    const T& back() const;

    size_t getSize() const;
    size_t getCapacity() const;

    bool empty() const;

    void push_back(const T& value);
    void pop_back();
    void clear();
    void reserve(size_t new_capacity);
    void resize(size_t new_size, const T& value);
    void erase(size_t index);
    void remove(T element);
    void insert(size_t index, const T& value);

private:
    void reallocate(size_t newCapacity);

    T* data;
    size_t size;
    size_t capacity;
};

// Constructor: Default
template <typename T>
Vector<T>::Vector() : data(nullptr), size(0), capacity(0) {}

// Constructor: With initial size and value
template <typename T>
Vector<T>::Vector(size_t count, const T& value) : size(count), capacity(count) {
    data = new T[capacity];
    for (size_t i = 0; i < size; ++i)
        data[i] = value;
}

// Constructor: From initializer list
template <typename T>
Vector<T>::Vector(initializer_list<T> init) : size(init.size()), capacity(init.size()) {
    data = new T[capacity];
    size_t i = 0;
    for (const T& val : init)
        data[i++] = val;
}

// Destructor
template <typename T>
Vector<T>::~Vector() {
    delete[] data;
}

// Copy constructor
template <typename T>
Vector<T>::Vector(const Vector& other) : size(other.size), capacity(other.capacity) {
    data = new T[capacity];
    for (size_t i = 0; i<size; ++i)
        data[i] = other.data[i];
}

// Move constructor
template <typename T>
Vector<T>::Vector(Vector&& other) noexcept : data(other.data), size(other.size), capacity(other.capacity) {
    other.data = nullptr;
    other.size = 0;
    other.capacity = 0;
}

// Copy assignment operator
template <typename T>
Vector<T>& Vector<T>::operator=(const Vector& other) {
    if (this == &other) return *this;
    delete[] data;
    size = other.size;
    capacity = other.capacity;
    data = new T[capacity];
    for (size_t i = 0; i < size; ++i) 
        data[i] = other.data[i];
    
    return *this;
}

// Move assignment operator
template <typename T>
Vector<T>& Vector<T>::operator=(Vector&& other) noexcept {
    if (this == &other) return *this;
    delete[] data;
    data = other.data;
    size = other.size;
    capacity = other.capacity;
    other.data = nullptr;
    other.size = 0;
    other.capacity = 0;
    return *this;
}

template <typename T>
T& Vector<T>::operator[](size_t index) {
    return data[index];
}

template <typename T>
const T& Vector<T>::operator[](size_t index) const {
    return data[index];
}

template <typename T>
T& Vector<T>::at(size_t index) {
    if (index >= size) throw out_of_range("Index out of range");
    return data[index];
}

template <typename T>
const T& Vector<T>::at(size_t index) const {
    if (index >= size) throw out_of_range("Index out of range");
    return data[index];
}

template <typename T>
T& Vector<T>::front() {
    return data[0];
}

template <typename T>
const T& Vector<T>::front() const {
    return data[0];
}

template <typename T>
T& Vector<T>::back() {
    return data[size - 1];
}

template <typename T>
const T& Vector<T>::back() const {
    return data[size - 1];
}

template <typename T>
size_t Vector<T>::getSize() const {
    return size;
}

template <typename T>
size_t Vector<T>::getCapacity() const {
    return capacity;
}

template<typename T>
bool Vector<T>::empty() const {
    return size == 0;
}

template <typename T>
void Vector<T>::reallocate(size_t newCapacity) {
    T* new_data = new T[newCapacity];
    for (size_t i = 0; i < size; ++i)
        new_data[i] = data[i];

    delete[] data;
    data = new_data;
    capacity = newCapacity;
}

template <typename T>
void Vector<T>::reserve(size_t new_capacity) {
    if (new_capacity > capacity) reallocate(new_capacity);
}

template <typename T>
void Vector<T>::push_back(const T& value) {
    if (size == capacity) reserve(capacity==0? 1:capacity*2);
    data[size++]=value;
}

template <typename T>
void Vector<T>::pop_back() {
    if (size>0) --size;
}

template <typename T>
void Vector<T>::clear() {
    size = 0;
}

template <typename T>
void Vector<T>::resize(size_t new_size, const T& value) {
    if (new_size > capacity) reserve(new_size);
    for (size_t i = size; i < new_size; ++i) {
        data[i] = value;
    }
    size = new_size;
}

template <typename T>
void Vector<T>::erase(size_t index) {
    for (size_t i = index; i < size - 1; ++i)
        data[i] = data[i + 1];
    --size;
}

template <typename T>
void Vector<T>::remove(T element) {
    for (size_t i = 0; i < size;) {
        if (data[i] == element) erase(i);
        else ++i;
    }
}
template <typename T>
void Vector<T>::insert(size_t index, const T& value) {
    if (size == capacity) reserve(capacity == 0 ? 1 : capacity * 2);
    for (size_t i = size; i > index; --i)
        data[i] = data[i - 1];
    
    data[index] = value;
    ++size;
}

#endif // VECTOR_HPP
