
#ifndef SEARCH_H
#define SEARCH_H

#include <vector>
#include <iostream>
#include "queue.h"
using namespace std;

//declaration of function for question 2
template <typename Item_Type>
int recursive_last_search(const vector<Item_Type>& items, const Item_Type& target, size_t pos_first = 0) {
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

//declaration of function for question 3
void insertion_sort_queue(Queue<int>& q);

#endif
