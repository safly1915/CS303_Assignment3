#include <iostream>
#include <vector>
#include "queue.h"
#include "search.h"
using namespace std;

int main() {
    Queue<int> q;

    for (int i = 1; i <= 10; ++i) { //create queue and push 10 integers, can be changed to any integers
        q.push(i * 10);
    }

    cout << "Original queue:\n"; //output original queue (queue can't be printed with iterator or index)
    int n = q.size();
    for (int i = 0; i < n; ++i) {
        cout << q.front() << " "; //get the front value and output it
        q.push(q.front()); //push that front value to back of queue
        q.pop(); //remove the front value
    }
    cout << endl << endl;

    q.move_to_rear(); //call move to rear function
    cout << "Queue after move to rear:\n";
    for (int i = 0; i < n; ++i) { //output queue after move to rear
        cout << q.front() << " ";
        q.push(q.front());
        q.pop();
    }
    cout << endl << endl;

    vector<int> vec = {2, 5, 1, 7, 5, 9, 5}; //vector for question 2 (can be updated to any vector of integers)
    int target = 5; //target value to search for (can be updated to any integer)
    int last_index = recursive_last_search(vec, target); //call recursive last index function
    cout << "Last occurrence of " << target << " is at index: " << last_index << endl << endl; //returns index of last occurrence

    Queue<int> unsorted; //create queue for question 3 (can be updated to any queue of integers)
    unsorted.push(42); //push integers to queue, unsorted
    unsorted.push(17);
    unsorted.push(23);
    unsorted.push(5);
    unsorted.push(89);

    cout << "Unsorted queue:\n";
    int sz = unsorted.size(); 
    for (int i = 0; i < sz; ++i) { //output unsorted queue, same format as above for queue
        cout << unsorted.front() << " ";
        unsorted.push(unsorted.front());
        unsorted.pop();
    }
    cout << endl << endl;

    insertion_sort_queue(unsorted); //call function to sort the queue
    cout << "Sorted queue:\n";
    sz = unsorted.size();
    for (int i = 0; i < sz; ++i) { //output sorted queue
        cout << unsorted.front() << " ";
        unsorted.push(unsorted.front());
        unsorted.pop();
    }
    cout << endl << endl;

    return 0;
}
