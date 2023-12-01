#include <iostream>
#include "graph.h"
using namespace std;

// Most generic constructor method to initialize the graph
graph::graph(int nof_nodes, float density, int min_distance, int max_distance)
{
    int nof_conn = nof_nodes * density;
    cout << "nof_conn:" << nof_conn << endl;
    for (int i = 0; i < nof_nodes; i++)
    {
        for (int conn = 0; conn < nof_conn; conn++)
        {
            int random_distance = min_distance + (rand() % (max_distance - min_distance)) + 1;
            int random_node = rand() % nof_nodes;
            int max_loop_cnt = nof_nodes;
            cout << "random_distance" << random_distance << " random_node" << random_node << endl;
            // Search till we find a unique node to connect with..
            // while ((connectivity_matrix.find(make_pair(i, random_node)) == connectivity_matrix.end()) && max_loop_cnt > 0)
            // {
            //     max_loop_cnt--;
            //     random_node = rand() % nof_nodes;
            // }
            connectivity_matrix[i][random_node] = random_distance;
            cout << "connectivity_matrix: " << connectivity_matrix[i][random_node] << " Size: " << connectivity_matrix.size() << endl;
        }
    }
}
void graph::print_matrix()
{
    cout << "Size: " << connectivity_matrix.size() << endl;
}
int main()
{
    cout << "Compiling..." << endl;
    graph graphInst;
    //(4, 1, 1, 10);
    graphInst.print_matrix();
}