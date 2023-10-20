#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

const int N = 40;

//sum function to sum up all elements in a vector 'd'
//Arguments: 
//  p: Pointer to the accumated value
//  d: Vector of int type that is to be summed up
inline void sum(int &p, vector<int> d)
{
    p = accumulate(d.begin(), d.end(), 0);
}

int main()
{
    int accum = 0;
    vector<int> data(N);

    for (int i = 0; i < N; ++i)
        data[i] = i;

    sum(accum, data);
    cout << "Sum is " << accum << endl;

    return 0;
}
