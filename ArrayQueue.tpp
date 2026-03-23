#include "ArrayQueue.hpp"
template <typename T>
ArrayQueue<T>::ArrayQueue(int i) {
    buffer = new T[i];
    maxSize = i;
    frontIndex = 0;
    backIndex = -1;
    this->length = 0;
}

template <typename T>
ArrayQueue<T>::ArrayQueue(const ArrayQueue<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
ArrayQueue<T>& ArrayQueue<T>::operator=(const ArrayQueue<T>& rightObj) {
    if (this != &rightObj) {
        delete[] buffer;
        copy(rightObj);
    }
    return *this;
}

template <typename T>
ArrayQueue<T>::~ArrayQueue() {
    delete[] buffer;
}

template <typename T>
T ArrayQueue<T>::back() const {
    if (this->length == 0) {
        throw string("Queue is empty");
    }
    return buffer[backIndex];
}

template <typename T>
void ArrayQueue<T>::clear() {
    frontIndex = 0;
    backIndex = -1;
    this->length = 0;
}

template <typename T>
void ArrayQueue<T>::copy(const ArrayQueue<T>& copyObj) {
    frontIndex = copyObj.frontIndex;
    backIndex = copyObj.backIndex;
    maxSize = copyObj.maxSize;
    this->length = copyObj.length;
    buffer = new T[maxSize];
    for (int i = 0; i < maxSize; i++) {
        buffer[i] = copyObj.buffer[i];
    }
}

template <typename T>
void ArrayQueue<T>::dequeue() {
    if (this->length == 0) {
        throw string("Queue is empty");
    }

    frontIndex = (frontIndex + 1) % maxSize;
    this->length--;

    if (this->length == 0) {
        frontIndex = 0;
        backIndex = -1;
    }
}

template <typename T>
void ArrayQueue<T>::enqueue(const T& elem) {
    if (this->length == maxSize) {
        throw string("Queue is full");
    }
    if (this->length == 0) {
        frontIndex = 0;
        backIndex = 0;
        buffer[0] = elem;
    } else {
        backIndex = (backIndex + 1) % maxSize;
        buffer[backIndex] = elem;
    }
    this->length++;
    
}

template <typename T>
T ArrayQueue<T>::front() const {
    if (this->length == 0) {
        throw string("Queue is empty");
    }
    return buffer[frontIndex];
}

template <typename T>
int ArrayQueue<T>::getLength() const {
    return this->length;
}

template <typename T>
int ArrayQueue<T>::getMaxSize() const {
    return maxSize;
}

template <typename T>
bool ArrayQueue<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
bool ArrayQueue<T>::isFull() const {
    return this->length == maxSize;
}
