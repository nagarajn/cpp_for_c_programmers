#include "graph.h"
// Main function ::
int main()
{
    // To get random output on each run:
    // srand(time(0));
    graph *a_graph = new graph(10, 0.3, 1, 10);
    cout << *a_graph << endl;
    cout << "Average path length: " << a_graph->get_average_path_length() << endl;
    delete (a_graph);
    // a_graph = new graph(50, 0.4, 1, 10);
    // cout << *a_graph << endl;
    // cout << "Average path length: " << a_graph->get_average_path_length() << endl;
}