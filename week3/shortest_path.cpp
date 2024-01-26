#ifndef __SHORTEST_PATH_CPP__
#define __SHORTEST_PATH_CPP__
#include "shortest_path.h"
#include <algorithm>
// vertices(List) : list of vertices in G(V, E).
vector<int> shortest_path::vertices(graph a_graph)
{
    vector<int> vertices;
    for (int i = 0; i < a_graph.nof_vertices; i++)
        vertices.push_back(i);
    return vertices;
}

// path(u, w) : find shortest path between u-w and returns the sequence of
// vertices representing shorest path u - v1 - v2 -…- vn - w.
vector<int> shortest_path::path(graph a_graph, int u, int w)
{
    vector<int> path; // shortest path
    node a_node;
    unvisited_list.clear();
    visited_list.clear();
    unvisited_list = vertices(a_graph);
    // Let the distance between u and u be 0
    // Let the distance of all other nodes be infinity (MAX_INT) from u
    for (int vertex : unvisited_list)
    {
        dt_row a_dt_row(MAX_INT, u);
        if (vertex == u)
            a_dt_row.dist = 0;
        dt.push_back(a_dt_row);
    }
    // First time insert the starting node
    a_node.vertex = u;
    a_node.weight = 0;
    pq.insert(a_node);
    // From the unvisited list, pick the vertex with smallest known distance from start vertex
    // First time we should pick u, and then it depends on which one has the smallest known distance
    int curr_vertex;
    int min_distance = MAX_INT;
    for (int vertex : unvisited_list)
    {
        if (min_distance < dt[vertex].dist)
        {
            min_distance = dt[vertex].dist;
            curr_vertex = vertex;
        }
    }

    a_node = pq.top();
}
// path_size(u, w) : return the path cost associated with the shortest path.
int shortest_path::path_size(graph a_graph, vector<int> u, vector<int> w)
{
}
#endif