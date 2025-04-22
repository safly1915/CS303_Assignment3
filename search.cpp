#include "search.h"
using namespace std;

void insertion_sort_queue(Queue<int>& q) {
    vector<int> temp;

    while (!q.empty()) {
        temp.push_back(q.front());
        q.pop();
    }

    // Regular insertion sort on vector
    for (size_t i = 1; i < temp.size(); ++i) {
        int key = temp[i];
        int j = i - 1;
        while (j >= 0 && temp[j] > key) {
            temp[j + 1] = temp[j];
            --j;
        }
        temp[j + 1] = key;
    }

    for (int val : temp) {
        q.push(val);
    }
}
