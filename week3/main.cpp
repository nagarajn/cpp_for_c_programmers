#include "graph.h"
#include "priority_queue.h"
// Main function ::
int main()
{
    // To get random output on each run:
    // srand(time(0));
    graph *a_graph = new graph(50, 0.2, 1, 10);
    cout << *a_graph << endl;
    cout << "Average path length: " << a_graph->get_average_path_length() << endl;
    delete (a_graph);
    a_graph = new graph(50, 0.4, 1, 10);
    cout << *a_graph << endl;
    cout << "Average path length: " << a_graph->get_average_path_length() << endl;

    priority_queue pq;
    node a_node;
    node b_node;
    for (int i = 0; i < 10; i++)
    {
        a_node.weight = rand() % 50;
        a_node.vertex = i;
        pq.insert(a_node);
    }

    cout << "Priority queue::" << endl;
    cout << pq << endl;
    cout << pq.top() << endl;

    a_node.vertex = 100;
    a_node.weight = 2;
    pq.insert(a_node);
    cout << "Priority queue::" << endl;
    cout << pq << endl;
    cout << pq.top() << endl;
    cout << pq.contains(a_node) << ":" << pq.contains(b_node) << " Size: " << pq.size() << endl;

    pq.min_priority();
    cout << pq << endl;
}