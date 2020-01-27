#include <iostream>
using namespace std;

typedef struct __Point
{
    int xpos;
    int ypos;
} Point;

Point &PntAdder(const Point &p1, const Point &p2)
{
    Point *pptr = new Point;
    pptr->xpos = p1.xpos + p2.xpos;
    pptr->ypos = p1.ypos + p2.ypos;
    return *pptr;
}

int main()
{
    Point *a = new Point;
    a->xpos = 3;
    a->ypos = 3;
    Point *b = new Point;
    b->xpos = 5;
    b->ypos = 5;
    Point &c = PntAdder(*a, *b);
    cout << "New Point C" << endl;
    cout << "xpos: " << c.xpos << endl;
    cout << "ypos: " << c.ypos << endl;
    delete a;
    delete b;
    delete &c;
    return 0;
}