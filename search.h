#ifndef SEARCH_H
#define SEARCH_H

#include <vector>
#include <iostream>
#include "queue.h"
#include "search.cpp" //template function implementation
using namespace std;


//declaration of function for question 2
template <typename Item_Type>
int recursive_last_search(const std::vector<Item_Type>& items, const Item_Type& target, size_t pos_first = 0);

//declaration of function for question 3
void insertion_sort_queue(Queue<int>& q);

#endif
