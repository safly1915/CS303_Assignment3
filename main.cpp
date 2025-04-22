#include <iostream>
#include <vector>
#include "queue.h"
#include "search.h"
using namespace std;

int main() {
    Queue<int> q;

    // Push 10 integers
    for (int i = 1; i <= 10; ++i) {
        q.push(i * 10);
    }

    cout << "Original queue:\n";
    int n = q.size();
    for (int i = 0; i < n; ++i) {
        cout << q.front() << " ";
        q.push(q.front());
        q.pop();
    }
    cout << "\n";

    // Move front to rear
    q.move_to_rear();
    cout << "Queue after move_to_rear:\n";
    for (int i = 0; i < n; ++i) {
        cout << q.front() << " ";
        q.push(q.front());
        q.pop();
    }
    cout << "\n";

    // Q2: Recursive last index search
    vector<int> vec = {2, 5, 1, 7, 5, 9, 5};
    int target = 5;
    int last_index = recursive_last_index(vec, target);
    cout << "Last occurrence of " << target << " is at index: " << last_index << "\n";

    // Q3: Insertion sort on Queue
    Queue<int> unsorted;
    unsorted.push(42);
    unsorted.push(17);
    unsorted.push(23);
    unsorted.push(5);
    unsorted.push(89);

    cout << "Unsorted queue:\n";
    int sz = unsorted.size();
    for (int i = 0; i < sz; ++i) {
        cout << unsorted.front() << " ";
        unsorted.push(unsorted.front());
        unsorted.pop();
    }
    cout << "\n";

    insertion_sort_queue(unsorted);
    cout << "Sorted queue:\n";
    sz = unsorted.size();
    for (int i = 0; i < sz; ++i) {
        cout << unsorted.front() << " ";
        unsorted.push(unsorted.front());
        unsorted.pop();
    }
    cout << "\n";

    return 0;
}
