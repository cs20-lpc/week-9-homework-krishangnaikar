#include "LinkedQueue.hpp"
#include <iostream>
template <typename T>
LinkedQueue<T>::LinkedQueue() {
    head = nullptr;
    last = nullptr;
    this->length = 0;
}

template <typename T>
LinkedQueue<T>::LinkedQueue(const LinkedQueue<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
LinkedQueue<T>& LinkedQueue<T>::operator=(const LinkedQueue<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
LinkedQueue<T>::~LinkedQueue() {
    clear();
}

template <typename T>
T LinkedQueue<T>::back() const {
    if (last == nullptr) {
        throw string("Queue is empty");
    }
    return last->value;
}

template <typename T>
void LinkedQueue<T>::clear() {
    Node* temp;
    Node* current = head;
    while (current != nullptr) {
        temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
    last = nullptr;
    this->length = 0;
}

template <typename T>
void LinkedQueue<T>::copy(const LinkedQueue<T>& copyObj) {
    if (copyObj.head == nullptr) {
        head = nullptr;
        last = nullptr;
    } else {
        head = new Node(copyObj.head->value);
        Node* currentCopy = copyObj.head->next;
        Node* currentThis = head;
        while (currentCopy != nullptr) {
            currentThis->next = new Node(currentCopy->value);
            currentThis = currentThis->next;
            currentCopy = currentCopy->next;
        }
        last = currentThis;
    }
    this->length = copyObj.getLength();
}

template <typename T>
void LinkedQueue<T>::dequeue() {
    if (head == nullptr) {
        throw string("Queue is empty");
    }
    Node* temp = head;
    head = head->next;
    delete temp;
    this->length--;
}

template <typename T>
void LinkedQueue<T>::enqueue(const T& elem) {
    Node* newNode = new Node(elem);
    if (last != nullptr) {
        last->next = newNode;
    }
    last = newNode;
    if (head == nullptr) {
        head = newNode;
    }
    this->length++;
}

template <typename T>
T LinkedQueue<T>::front() const {
    if (head == nullptr) {
        throw string("Queue is empty");
    }
    return head->value;
}

template <typename T>
int LinkedQueue<T>::getLength() const {
    return this->length;
}

template <typename T>
bool LinkedQueue<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
bool LinkedQueue<T>::isFull() const {
    return false;
}
