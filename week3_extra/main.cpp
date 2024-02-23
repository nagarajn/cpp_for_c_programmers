#include "graph.h"
#include "priority_queue.h"
#include "shortest_path.h"
#include "main.h"
// Main function ::
int main()
{
    // To get random output on each run:
    // srand(time(0));
    graph *a_graph = new graph(0, 0.2, 1, 10);
    node a_node;
    node b_node;
    node c_node;
    node d_node;
    node e_node;
    node f_node;
    node g_node;
    node h_node;
    node i_node;
    node j_node;
    a_node.vertex = 1;
    b_node.vertex = 2;
    c_node.vertex = 3;
    d_node.vertex = 4;
    e_node.vertex = 5;
    f_node.vertex = 6;
    g_node.vertex = 7;
    h_node.vertex = 8;
    i_node.vertex = 9;
    j_node.vertex = 10;
    a_graph->nof_vertices = 10;
    // Build the graph
    add_and_set_edge_value(a_graph, a_node, b_node, 4);
    add_and_set_edge_value(a_graph, a_node, c_node, 2);
    add_and_set_edge_value(a_graph, a_node, g_node, 7);
    add_and_set_edge_value(a_graph, b_node, d_node, 2);
    add_and_set_edge_value(a_graph, d_node, g_node, 5);
    add_and_set_edge_value(a_graph, d_node, h_node, 6);
    add_and_set_edge_value(a_graph, h_node, j_node, 2);
    add_and_set_edge_value(a_graph, g_node, j_node, 4);
    add_and_set_edge_value(a_graph, c_node, g_node, 3);
    add_and_set_edge_value(a_graph, c_node, f_node, 8);
    add_and_set_edge_value(a_graph, f_node, j_node, 3);

    cout << *a_graph << endl;
    connection a_connection;
    a_connection.x = 4;
    a_connection.y = 7;
    cout << "exists: " << a_graph->exists(a_connection) << endl;
    shortest_path *a_shortest_path = new shortest_path(*a_graph);
    vector<int> shortest_path_v;
    shortest_path_v = a_shortest_path->path(*a_graph, 1, 2);
    // a_graph = new graph(50, 0.4, 1, 10);
    // cout << *a_graph << endl;
    // cout << "Average path length: " << a_graph->get_average_path_length() << endl;

    // priority_queue pq;
    // // node a_node;
    // // node b_node;
    // for (int i = 0; i < 2; i++)
    // {
    //     a_node.weight = rand() % 50;
    //     a_node.vertex = i;
    //     pq.insert(a_node);
    // }

    // cout << "Priority queue::" << endl;
    // cout << pq << endl;
    // cout << pq.top() << endl;

    // a_node.vertex = 100;
    // a_node.weight = 2;
    // pq.insert(a_node);
    // cout << "Priority queue::" << endl;
    // cout << pq << endl;
    // cout << pq.top() << endl;
    // cout << pq.contains(a_node) << ":" << pq.contains(b_node) << " Size: " << pq.size() << endl;

    // pq.min_priority();
    // cout << "one removal:" << pq << " size:" << pq.size() << endl;
    // pq.min_priority();
    // cout << "two removals:" << pq << " size: " << pq.size() << endl;
    // pq.min_priority();
    // cout << "three removal:" << pq << " size:" << pq.size() << endl;
    // pq.min_priority();
    // cout << "four removals:" << pq << " size: " << pq.size() << endl;
}
void add_and_set_edge_value(graph *a_graph, node &a_node, node &b_node, int edge_value)
{
    a_graph->add(a_node.vertex, b_node.vertex);
    a_graph->set_edge_value(a_node.vertex, b_node.vertex, edge_value);
}