#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <exception>
#include <fstream>
template <typename T>
class Vector {
    T* data;
    size_t size;
    size_t capacity;

    void free();
    void copyFrom(const Vector<T>&);
    void resize();
    bool isEmpty() const;

public:
    Vector();
    Vector(size_t size);
    Vector(const Vector<T>&);
    Vector<T>& operator=(const Vector<T>&);
    ~Vector();

    size_t getSize() const;
    size_t getCapacity() const;
    void setCapacity(size_t);
    void push_back(const T&);
    void insert(const T&, long long);

    T& operator[](long long);
    const T& operator[](long long) const;
    void deleteAt(long long);
    void pop_back();
    long long findItem(const T&) const;
    void clear();

};

template <typename T>
void Vector<T>::free() {
    delete[] data;
    data = nullptr;
    capacity = size = 0;
}

template <typename T>
void Vector<T>::copyFrom(const Vector<T> &other) {
    size = other.size;
    capacity = other.capacity;

    data = new T[capacity];

    for (size_t i = 0; i < size; i++)
        data[i] = other.data[i];
}

template <typename T>
void Vector<T>::resize() {
    capacity = 2 * capacity;

    T *newMemory = new T[capacity];

    for (size_t i = 0; i < size; i++)
        newMemory[i] = std::move(data[i]);

    delete[] data;
    data = newMemory;
}

template <typename T>
bool Vector<T>::isEmpty() const {
    return size == 0;
}

template <typename T>
Vector<T>::Vector() {
    size = 0;
    capacity = 8;
    data = new T[capacity];
}

template <typename T>
Vector<T>::Vector(size_t size) {
    this->size = 0;
    capacity = size;
    data = new T[capacity];
}

template <typename T>
void Vector<T>::setCapacity(size_t newCapacity) {
    size = 0;
    delete[] data;
    capacity = newCapacity;
    data = new T[capacity];
}

template <typename T>
Vector<T>::Vector(const Vector<T> &other) {
    copyFrom(other);
}

template <typename T>
Vector<T> &Vector<T>::operator=(const Vector<T> &other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}

template <typename T>
Vector<T>::~Vector<T>() {
    free();
}

template <typename T>
size_t Vector<T>::getSize() const {
    return size;
}

template <typename T>
size_t Vector<T>::getCapacity() const {
    return capacity;
}

template <typename T>
void Vector<T>::push_back(const T& element) {
    if (size == capacity)
        resize();

    data[size++] = element;
}

template <typename T>
void Vector<T>::insert(const T& element, long long index) {
    if (index >= size || index < 0)
        throw std::out_of_range("out of range");
    if (size == capacity)
        resize();

    for (int i = size; i > index; --i) {
        data[i] = std::move(data[i - 1]);
    }
    ++size;
    data[index] = element;
}

template <typename T>
T& Vector<T>::operator[](long long index) {
    if (index >= size || index < 0)
        throw std::out_of_range("out of range");
    return data[index];
}

template <typename T>
const T& Vector<T>::operator[](long long index) const {
    if (index >= size || index < 0)
        throw std::out_of_range("out of range");

    return data[index];
}

template <typename T>
void Vector<T>::deleteAt(long long index) {
    if (index >= size || index < 0)
        throw std::out_of_range("out of range");

    for (size_t i = index; i < size - 1; ++i)
        data[i] = std::move(data[i + 1]);

    --size;
}

template <typename T>
void Vector<T>::pop_back() {
    if (isEmpty())
        throw std::logic_error("vector is empty");
    --size;
}

template <typename T>
long long Vector<T>::findItem(const T& element) const {
    for (size_t i = 0; i < size; ++i) {
        if (data[i] == element) {
            return i;
        }
    }
    return -1;
}

template <typename T>
void Vector<T>::clear() {
    free();
    size = 0;
    capacity = 8;
    data = new T[capacity];
}

#endif //VECTOR_HPP