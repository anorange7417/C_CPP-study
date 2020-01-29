#include <iostream>
using namespace std;

class First
{
public:
    virtual void SimpleFunc() { cout << "First" << endl; }
};

class Second : public First
{
public:
    void SimpleFunc() { cout << "Second" << endl; }
};

int main()
{
    First *ptr = new First();
    ptr->SimpleFunc();
    delete ptr;
    ptr = new Second();
    ptr->SimpleFunc();
    delete ptr;
    return 0;
}