#ifndef __GRAPH_CPP__
#define __GRAPH_CPP__
#include "graph.h"

// Most generic constructor method to initialize the graph
graph::graph(int nof_vertices, float density, int min_distance, int max_distance) : nof_vertices(nof_vertices),
                                                                                    density(density), min_distance(min_distance), max_distance(max_distance)
{
    int total_nof_conn = nof_vertices * (nof_vertices - 1);
    for (int i = 0; i < total_nof_conn; i++)
    {
        if (rand() % 100 >= density * 100)
            continue;
        int random_distance = min_distance + (rand() % (max_distance - min_distance)) + 1;
        int random_node = rand() % nof_vertices;
        int max_loop_cnt = BIG_LOOP_LIMIT;
        connection a_connection(i % nof_vertices, random_node);
        // Search till we find a unique node to connect with..
        while ((exists(a_connection) && max_loop_cnt > 0) || (random_node == i))
        {
            max_loop_cnt--;
            random_node = rand() % nof_vertices;
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
// returns True if a connection exists, else False
bool graph::exists(int x, int y)
{
    connection a_connection;
    a_connection.x = x;
    a_connection.y = y;
    return (matrix.find(a_connection) != matrix.end());
}
// Get average path length
int graph::get_average_path_length()
{
    int total_path_length;
    int average_path_length;
    int divider;
    connection a_connection;
    total_path_length = 0;
    divider = 0;
    for (int i = 1; i < nof_vertices; i++)
    {
        a_connection.y = i;
        if (exists(a_connection))
        {
            total_path_length += matrix[a_connection];
            divider++;
        }
    }
    // Avoid divide by 0
    if (divider == 0)
        divider = 1;
    average_path_length = total_path_length / divider;
    return average_path_length;
}
// V(G) : returns the number of vertices in the graph
int graph::V()
{
    return nof_vertices;
}
//   E(G) : returns the number of edges in the graph
int graph::E()
{
    return matrix.size();
}
// adjacent(G, x, y) : tests whether there is an edge from node x to node y.
bool graph::adjacent(int x, int y)
{
    connection a_connection;
    a_connection.x = x;
    a_connection.y = y;
    return (exists(a_connection));
}
// neighbors(G, x) : lists all nodes y such that there is an edge from x to y.
vector<int> graph::neighbors(int x)
{
    vector<int> node_list;
    connection a_connection;
    connection b_connection;
    a_connection.x = x;
    b_connection.y = x;
    for (int a_y = 1; a_y <= nof_vertices; a_y++)
    {
        a_connection.y = a_y;
        b_connection.x = a_y;
        if (exists(a_connection))
            node_list.push_back(a_y);
        else if (exists(b_connection))
            node_list.push_back(a_y);
    }
    return node_list;
}
// add(G, x, y) : adds to G the edge from x to y, if it is not there.
void graph::add(int x, int y)
{
    connection a_connection;
    a_connection.x = x;
    a_connection.y = y;
    if (!exists(a_connection))
        matrix[a_connection] = 0;
}
// delete(G, x, y) : removes the edge from x to y, if it is there.
void graph::delete_node(int x, int y)
{
    connection a_connection;
    a_connection.x = x;
    a_connection.y = y;
    if (exists(a_connection))
        matrix.erase(a_connection);
}
// get_edge_value(G, x, y) : returns the value associated to the edge(x, y).
int graph::get_edge_value(int x, int y)
{
    connection a_connection;
    a_connection.x = x;
    a_connection.y = y;
    return (matrix[a_connection]);
}
// set_edge_value(G, x, y, v) : sets the value associated to the edge(x, y) to v.
void graph::set_edge_value(int x, int y, int v)
{
    connection a_connection;
    a_connection.x = x;
    a_connection.y = y;
    matrix[a_connection] = v;
}

#endif