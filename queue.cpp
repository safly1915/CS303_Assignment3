#ifndef QUEUE_CPP
#define QUEUE_CPP

#include <iostream>
#include "queue.h"

template <typename T> //constructor
Queue<T>::Queue() : front_node(nullptr), rear_node(nullptr), count(0) {} //initializes empty queue with nodes set to null and count set to 0

template <typename T> //destructor
Queue<T>::~Queue() { //called when queue is cleared, deletes all nodes in queue to prevent memory leaks
    while (!empty()) {
        pop();
    }
}

template <typename T>
void Queue<T>::push(const T& item) { //push function
    Node* new_node = new Node(item); //create new node with item in data
    if (empty()) { //if queue is empty, that item is the front and rear of queue
        front_node = rear_node = new_node;
    } else { //otherwise, new node is added to the back and set to the rear
        rear_node->next = new_node;
        rear_node = new_node;
    }
    count++; //increment count to keep track of size
}

template <typename T>
void Queue<T>::pop() { //pop function
    if (!empty()) { //if queue isn't empty
        Node* temp = front_node; //create temp node to store front node
        front_node = front_node->next; //move front node to the next node
        delete temp; //delete the former front node
        count--; //decrement count to keep track of size
        if (empty()) rear_node = nullptr; //if queue empty, set rear to null
    }
}

template <typename T>
T Queue<T>::front() const { //front function
    if (!empty()) return front_node->data; //if queue isn't empty, return the data of front node
    throw out_of_range("Queue is empty."); //queue is empty, throw out of range error
}

template <typename T>
int Queue<T>::size() const { //size function
    return count; //return count, as used above
}

template <typename T>
bool Queue<T>::empty() const { //empty function
    return front_node == nullptr; //true if front node is null, false otherwise
}

template <typename T>
void Queue<T>::move_to_rear() { //move item to rear function
    if (!empty() && size() > 1) { //if queue isn't empty and size greater than 1
        T temp = front(); //front item is stored in temp
        pop(); //remove the front item
        push(temp); //temp is pushed onto the back of the queue
    }
}

#endif