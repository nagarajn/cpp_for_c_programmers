#ifndef __SHORTEST_PATH_CPP__
#define __SHORTEST_PATH_CPP__
#include "shortest_path.h"
#include <algorithm>
#include <numeric>
// vertices(List) : list of vertices in G(V, E).
vector<int> shortest_path::vertices(graph a_graph)
{
    vector<int> vertices;
    for (int i = 1; i <= a_graph.nof_vertices; i++)
        vertices.push_back(i);
    return vertices;
}

// path(u, w) : find shortest path between u-w and returns the sequence of
// vertices representing shorest path u - v1 - v2 -…- vn - w.
vector<int> shortest_path::path(graph a_graph, int u, int w)
{
    int iter_cnt = 0;
    vector<int> path; // shortest path
    unvisited_list.clear();
    visited_list.clear();
    unvisited_list = vertices(a_graph);
    cout << "a_graph size: " << a_graph.nof_vertices << " unvisited_list size: " << unvisited_list.size() << endl;
    for (int x : unvisited_list)
    {
        cout << "x: " << x << endl;
    }
    // Let the distance between u and u be 0
    // Let the distance of all other nodes be infinity (MAX_INT) from u
    for (int vertex : unvisited_list)
    {
        dt_row a_dt_row(MAX_INT, u);
        if (vertex == u)
            a_dt_row.dist = 0;
        dt.push_back(a_dt_row);
    }
    node curr_node;
    curr_node.vertex = u;
    curr_node.weight = 0;
    // Here starts the dijkstra loop:
    while (unvisited_list.size() && iter_cnt < 5)
    {
        // Insert all neighbours of the current node
        vector<int> neighbours;
        neighbours = a_graph.neighbors(curr_node.vertex);
        cout << "================================================================" << endl;
        cout << "= iter_cnt: " << iter_cnt << " curr_node.vertex: " << curr_node.vertex << endl;
        cout << "================================================================" << endl;
        iter_cnt++;
        cout << "Neighbours: " << neighbours.size() << endl;
        for (int vertex : neighbours)
        {
            node neighbour_node;
            neighbour_node.vertex = vertex;
            neighbour_node.weight = curr_node.weight + a_graph.get_edge_value(curr_node.vertex, vertex);
            cout << " " << vertex << " weight: " << neighbour_node.weight << endl;
            pq.insert(neighbour_node);
        }
        cout << "================================================================" << endl;

        cout << "Priority queue: " << pq.size() << " : " << pq.top() << endl;
        cout << pq << endl;
        cout << "================================================================" << endl;
        cout << "DT: " << dt.size() << endl;
        for (dt_row a_dt_row : dt)
        {
            cout << a_dt_row << endl;
        }
        // Add to the dijkstra table only if the new value is lower than what exists in the table
        if (dt[pq.top().vertex - 1].dist > pq.top().weight)
        {
            dt[pq.top().vertex - 1].dist = pq.top().weight;
        }
        unvisited_list.erase(std::remove(unvisited_list.begin(), unvisited_list.end(), curr_node.vertex), unvisited_list.end());
        cout << "a_graph size: " << a_graph.nof_vertices << " unvisited_list size: " << unvisited_list.size() << endl;

        curr_node = pq.top();
        // Remove the min priority element from priority queue
        pq.min_priority();
        cout << pq << endl;
    }
}
// path_size(u, w) : return the path cost associated with the shortest path.
int shortest_path::path_size(graph a_graph, int u, int w)
{
    vector<int> shortest_path_vec;
    shortest_path_vec = path(a_graph, u, w);
    return std::accumulate(shortest_path_vec.begin(), shortest_path_vec.end(), 0);
}
#endif