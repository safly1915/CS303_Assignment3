#ifndef SEARCH_CPP
#define SEARCH_CPP

#include "search.h"

template <typename Item_Type>
int recursive_last_search(const std::vector<Item_Type>& items, const Item_Type& target, size_t pos_first) { //function to recursively search for last occurrence of target, pos_first is default to 0 for first item
    if (pos_first == items.size()) { //base case: if end of vector is reached, return -1 for not found
        return -1;
    }

    int index_in_rest = recursive_last_search(items, target, pos_first + 1); //recursive call to keep searching through vector, continue until end is reached then search backwards through returns

    if (index_in_rest != -1) //if index isn't -1, we found target and return index_in_rest for last occurrence
        return index_in_rest;
    else if (items[pos_first] == target) //if target not found in recursive call, check if current item is target and return pos_first if true
        return pos_first;
    else //target not found in current item or recursive
        return -1;
}


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