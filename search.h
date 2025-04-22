#ifndef SEARCH_H
#define SEARCH_H

#include <vector>
#include "queue.h"

// Recursive linear search to find last occurrence of target in a vector
template <typename T>
int recursive_last_index(const vector<T>& vec, const T& target, int index = 0) {
    if (index == vec.size()) return -1;
        int found = recursive_last_index(vec, target, index + 1);
    if (found != -1) return found;
        return vec[index] == target ? index : -1;
}

// Insertion sort for Queue<int>
void insertion_sort_queue(Queue<int>& q);

#endif
