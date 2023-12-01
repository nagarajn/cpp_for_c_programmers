#include <vector>
#include <iomanip>
#include <iostream>
#define MAX_INT (2 * *32 - 1)
using namespace std;
class node
{
public:
    int vertex;
    int weight; // same as accumulated distance

    node(int vertex = 0, int weight = 0) : vertex(vertex), weight(weight)
    {
    }
    bool operator>(const node &other) const
    {
        if (weight > other.weight)
            return true;
        return false;
    }
    friend ostream &operator<<(ostream &os, const node &n)
    {
        os << setw(2) << '(' << setw(2) << n.vertex << ',' << setw(2) << n.weight << ')';
        return os;
    }
    bool operator==(const node &other)
    {
        if (vertex == other.vertex && weight == other.weight)
            return true;
        return false;
    }
};
class priority_queue
{
private:
    vector<node> min_heap_arr;

public:
    priority_queue(){};

    // minPrioirty(PQ): removes the top element of the queue.
    void min_priority();
    // contains(PQ, queue_element): does the queue contain queue_element.
    bool contains(node a_node);
    // Insert(PQ, queue_element): insert queue_element into queue
    void insert(node a_node);
    // top(PQ):returns the top element of the queue.
    node top();
    // size(PQ): return the number of queue_elements.
    int size();
    friend ostream &operator<<(ostream &os, const priority_queue &pq)
    {
        vector<node>::const_iterator it;
        int loop_cnt;
        loop_cnt = 0;
        for (it = pq.min_heap_arr.begin(); it != pq.min_heap_arr.end(); it++)
        {
            os << *it;
            // Insert an end of line after every 8th iteration
            if (loop_cnt % 8 == 7)
            {
                os << endl;
            }
            loop_cnt++;
        }
        return os;
    }
};