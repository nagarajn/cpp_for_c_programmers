#ifndef __SHORTEST_PATH_H__
#define __SHORTEST_PATH_H__
#include <vector>
#include <iomanip>
#include <iostream>
#include "priority_queue.h"
#include "graph.h"
// Dijkstra's table row
// Contains
// 1. the distance from the "start vertex".
// 2. previous vertex
class dt_row
{
public:
    int dist;
    int prev_vertex;
    dt_row(int dist, int prev_vertex) : dist(dist), prev_vertex(prev_vertex){};
};
class shortest_path
{
    graph a_graph;
    // dt -- dijkstras table
    // Indexed using the vertex number
    vector<dt_row> dt;
    vector<int> visited_list;
    vector<int> unvisited_list;
    priority_queue pq;

public:
    shortest_path(graph a_graph) : a_graph(a_graph){};
    // vertices(List) : list of vertices in G(V, E).
    vector<int> vertices(graph a_graph);
    // path(u, w) : find shortest path between u-w and returns the sequence of
    // vertices representing shorest path u - v1 - v2 -…- vn - w.
    vector<int> path(graph a_graph, int u, int w);
    // path_size(u, w) : return the path cost associated with the shortest path.
    int path_size(graph a_graph, vector<int> u, vector<int> w);
};

#endif