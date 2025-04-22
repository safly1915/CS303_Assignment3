#ifndef QUEUE_H
#define QUEUE_H

template <typename T>
class Queue {
private:
    struct Node {
        T data;
        Node* next;
        Node(T item) : data(item), next(nullptr) {}
    };
    Node* front_node;
    Node* rear_node;
    int count;

public:
    Queue();
    ~Queue();
    void push(const T& item);
    void pop();
    T front() const;
    int size() const;
    bool empty() const;
    void move_to_rear();
};

#include "queue.cpp"  // Include template implementation

#endif
