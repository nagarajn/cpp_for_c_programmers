#include <iostream>
#include <vector>
using namespace std;

class point
{
public:
    double x;
    double y;

    point(double x = 0.0, double y = 0.0)
    {
        this->x = x;
        this->y = y;
    }
    double get_x()
    {
        return x;
    }
    double get_y()
    {
        return y;
    }
};

ostream &operator<<(ostream &os, const point &p)
{
    os << "(" << p.x << "," << p.y << ")";
    return os;
}

point operator+(point &p1, point &p2)
{
    point sum(0.0, 0.0);
    sum.x = p1.get_x() + p2.get_x();
    sum.y = p1.get_y() + p2.get_y();
    return sum;
}
// Main part of the program
// Display point a and point b
int main()
{
    point a_point(1.2, 2);
    point b_point(3.8, 4.4);
    cout << a_point << b_point << endl;
    cout << a_point + b_point << endl;
}