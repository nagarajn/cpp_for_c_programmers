#include "graph.h"

// Most generic constructor method to initialize the graph
graph::graph(int nof_nodes, float density, int min_distance, int max_distance) : nof_nodes(nof_nodes),
                                                                                 density(density), min_distance(min_distance), max_distance(max_distance)
{
    int total_nof_conn = nof_nodes * (nof_nodes - 1);
    for (int i = 0; i < total_nof_conn; i++)
    {
        if (rand() % 100 >= density * 100)
            continue;
        int random_distance = min_distance + (rand() % (max_distance - min_distance)) + 1;
        int random_node = rand() % nof_nodes;
        int max_loop_cnt = BIG_LOOP_LIMIT;
        connection a_connection(i % nof_nodes, random_node);
        // Search till we find a unique node to connect with..
        while ((exists(a_connection) && max_loop_cnt > 0) || (random_node == i))
        {
            max_loop_cnt--;
            random_node = rand() % nof_nodes;
            a_connection.y = random_node;
        }
        if (max_loop_cnt == 0)
            cout << "Loop maxed out !!" << endl;
        matrix[a_connection] = random_distance;
    }
}
// returns True if a connection exists, else False
bool graph::exists(connection a_connection)
{
    return (matrix.find(a_connection) != matrix.end());
}
// Get average path length
int graph::get_average_path_length()
{
    int average_path_length;
    connection a_connection;
    for (int i = 1; i < nof_nodes; i++)
    {
        a_connection.y = i;
        if (exists(a_connection))
        {
            average_path_length += matrix[a_connection];
        }
    }
    return average_path_length;
}

// Main function ::
int main()
{
    // To get random output on each run:
    srand(time(0));
    graph *a_graph = new graph(50, 0.2, 1, 10);
    cout << *a_graph << endl;
    cout << "Average path length: " << a_graph->get_average_path_length() << endl;
    delete (a_graph);
    a_graph = new graph(50, 0.4, 1, 10);
    cout << *a_graph << endl;
    cout << "Average path length: " << a_graph->get_average_path_length() << endl;
}