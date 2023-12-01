// There are 2 basic implementations used for graphs – one is edge lists, and the other is connectivity matrices. You can decide which to use, but comment on your choice.
// Basic problem:  Write a set of constructors for declaring and initializing a graph. An edge will have a positive cost that is its distance. Have a procedure that produces a randomly generated set of edges with positive distances.  Assume the graphs are undirected. The random graph procedure should have edge density as a parameter and distance range as a parameter. So a graph whose density is 0.1 would have 10% of its edges picked at random and its edge distance would be selected at random from the distance range. The procedure should run through all possible undirected edges, say (i,j) and place the edge in the graph if a random probability calculation is less than the density. Compute for a set of randomly generated graphs an average shortest path.
// Turn in:  Printout of program, 200 words on what you learned, and output showing the average path length calculation. Use densities: 20% and 40% on a graph of 50 nodes with a distance range of 1.0 to 10.0.   To get an average path length, compute the 49 paths:
// 1 to 2, 1 to 3, 1 to 4, …, 1 to 50.
// [In an instance where there is no path between 1 and n, omit that value from the average. This should be very rare for the chosen density and size in this homework.]

#include <map>
#include <string>
#include <iostream>
#include <iomanip>
#include <random>
#include <cstdlib>
#define BIG_LOOP_LIMIT 10000
using namespace std;
// Class connection represents a single connection in the connectivity
//  matrix. It contains both the vertices but not the value.
class connection
{
public:
    int x;
    int y;
    connection(int x = 0, int y = 0)
    {
        this->x = x;
        this->y = y;
    }
    friend ostream &operator<<(ostream &os, const connection &c)
    {
        os << setw(2) << '(' << setw(2) << c.x << ',' << setw(2) << c.y << ')';
        return os;
    }
    bool operator<(const connection &other) const
    {
        if (x < other.x)
            return true;
        if (other.x < x)
            return false;
        if (y < other.y)
            return true;
        return false;
    }
};

class graph
{
private:
    map<connection, int> matrix;

public:
    int nof_nodes;
    float density;
    int min_distance;
    int max_distance;
    graph(int nof_nodes = 4, float density = 1, int min_distance = 1, int max_distance = 10);
    friend ostream &operator<<(ostream &os, const graph &g)
    {
        map<connection, int>::const_iterator it;
        int loop_cnt = 0;
        cout << "===========================================================" << endl;
        cout << "matrix size::  " << g.matrix.size() << endl;
        cout << "nof_nodes::    " << g.nof_nodes << endl;
        cout << "density::      " << g.density << endl;
        cout << "min_distance:: " << g.min_distance << endl;
        cout << "max_distance:: " << g.max_distance << endl;

        for (it = g.matrix.begin(); it != g.matrix.end(); it++)
        {
            os << it->first // string (key)
               << ':'
               << setw(3) << it->second << " ";

            // Insert an end of line after every 8th iteration
            if (loop_cnt % 8 == 7)
            {
                os << endl;
            }
            loop_cnt++;
        }

        return os;
    }

    // returns True if a connection exists, else False
    bool exists(connection a_connection);
    // Get average path length
    int get_average_path_length();
};