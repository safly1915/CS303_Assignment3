#ifndef SEARCH_CPP
#define SEARCH_CPP

#include "search.h"

void insertion_sort_queue(Queue<int>& q) {
    vector<int> temp; //setup temp vector to store queue values for sorting

    while (!q.empty()) { //while queue not empty, push front of queue to the temp vector and pop front of queue
        temp.push_back(q.front());
        q.pop();
    }

    for (size_t i = 1; i < temp.size(); ++i) {
        int key = temp[i]; //key is current item to be inserted into sorted part of vector
        int j = i - 1; //j is index of last item in sorted part of vector
        while (j >= 0 && temp[j] > key) { //while j is greater than or equal to 0 and temp[j] is greater than key, shift temp[j] to the right
            temp[j + 1] = temp[j];
            --j;
        }
        temp[j + 1] = key; //after moving items to the right, insert key into the correct position
    }

    for (int val : temp) { //push sorted values back into the queue
        q.push(val);
    }
}

#endif