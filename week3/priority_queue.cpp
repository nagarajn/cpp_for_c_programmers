#ifndef __PRIORITY_QUEUE_CPP__
#define __PRIORITY_QUEUE_CPP__
#include "priority_queue.h"

// minPrioirty(PQ): removes the top element of the queue.
void priority_queue::min_priority()
{
    // if there aren't any elements, then simply return
    if (min_heap_arr.size() == 0)
        return;
    // If there's only one element then simply remove it.
    if (min_heap_arr.size() == 1)
    {
        min_heap_arr.erase(min_heap_arr.begin());
        return;
    }
    // But if there are more than one elements in the heap then we need to follow the below steps.
    //  Swap the first element and the last element
    swap(min_heap_arr[0], min_heap_arr.back());
    // Now remove the last element
    min_heap_arr.erase(min_heap_arr.end() - 1);

    // Now push down the new head of the heap if required
    // Handle the case where only two elements are present:
    if (min_heap_arr.size() == 2)
    {
        if (min_heap_arr[0] > min_heap_arr[1]) // check if swap is required
        {
            swap(min_heap_arr[0], min_heap_arr[1]);
        }
        return;
    }
    // Handle the more generic case of nof of elements <2
    int child0_idx = 1;
    int child1_idx = 2;
    int parent_idx = 0;
    // If swapping is required:
    while ((min_heap_arr[parent_idx] > min_heap_arr[child0_idx]) ||
           (min_heap_arr[parent_idx] > min_heap_arr[child1_idx]))
    {
        // Swap with the child node that has lower value of the two child nodes
        if (min_heap_arr[child0_idx] > min_heap_arr[child1_idx])
        {
            swap(min_heap_arr[child1_idx], min_heap_arr[parent_idx]);
            parent_idx = child1_idx;
        }
        else
        {
            swap(min_heap_arr[child0_idx], min_heap_arr[parent_idx]);
            parent_idx = child0_idx;
        }
        child0_idx = 2 * parent_idx + 1;
        child1_idx = child0_idx + 1;
        // What if there cannot be child1? Then simply point child1 to child0
        if (child1_idx == min_heap_arr.size())
            child1_idx = child0_idx;
    }
}
// contains(PQ, queue_element): does the queue contain queue_element.
bool priority_queue::contains(node a_node)
{
    return (find(min_heap_arr.begin(), min_heap_arr.end(), a_node) != min_heap_arr.end());
}
// Insert(PQ, queue_element): insert queue_element into queue
void priority_queue::insert(node a_node)
{
    int child_idx;
    int parent_idx;
    // INitially just push the new node to the heap in the last index.
    min_heap_arr.push_back(a_node);
    // Now check if it is in an acceptable position, if not bubble it up
    child_idx = min_heap_arr.size() - 1;
    parent_idx = (child_idx - 1) / 2; // floored by default
    while (min_heap_arr[parent_idx] > min_heap_arr[child_idx])
    {
        swap(min_heap_arr[child_idx], min_heap_arr[parent_idx]);
        child_idx = parent_idx;
        parent_idx = (child_idx - 1) / 2;
    }
}
// top(PQ):returns the top element of the queue.
node priority_queue::top()
{
    return min_heap_arr[0];
}
// size(PQ): return the number of queue_elements.
int priority_queue::size()
{
    return min_heap_arr.size();
}

#endif