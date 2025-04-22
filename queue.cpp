#ifndef QUEUE_CPP
#define QUEUE_CPP

#include <iostream>
#include "queue.h"

template <typename T>
Queue<T>::Queue() : front_node(nullptr), rear_node(nullptr), count(0) {}

template <typename T>
Queue<T>::~Queue() {
    while (!empty()) {
        pop();
    }
}

template <typename T>
void Queue<T>::push(const T& item) {
    Node* new_node = new Node(item);
    if (empty()) {
        front_node = rear_node = new_node;
    } else {
        rear_node->next = new_node;
        rear_node = new_node;
    }
    count++;
}

template <typename T>
void Queue<T>::pop() {
    if (!empty()) {
        Node* temp = front_node;
        front_node = front_node->next;
        delete temp;
        count--;
        if (empty()) rear_node = nullptr;
    }
}

template <typename T>
T Queue<T>::front() const {
    if (!empty()) return front_node->data;
    throw std::out_of_range("Queue is empty.");
}

template <typename T>
int Queue<T>::size() const {
    return count;
}

template <typename T>
bool Queue<T>::empty() const {
    return front_node == nullptr;
}

template <typename T>
void Queue<T>::move_to_rear() {
    if (!empty() && size() > 1) {
        T temp = front();
        pop();
        push(temp);
    }
}

#endif
