#ifndef QUEUE_H
#define QUEUE_H
using namespace std;

template <typename T>
class Queue { //template for queue class
private:
    struct Node { //node struct
        T data; 
        Node* next; //pointer to next node
        Node(T item) : data(item), next(nullptr) {} //constructor for node
    };
    Node* front_node; //pointer to front node
    Node* rear_node; //pointer to rear node
    int count; //integer to keep track of size

public:
    Queue(); //constructor for queue
    ~Queue(); //destructor for queue
    void push(const T& item); //push function
    void pop(); //pop function
    T front() const; //front function
    int size() const; //size function
    bool empty() const; //empty function
    void move_to_rear(); //move to rear function
};

#include "queue.cpp"  //include template implementation
#endif
