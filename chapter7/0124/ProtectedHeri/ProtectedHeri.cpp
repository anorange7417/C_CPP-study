#include <iostream>
using namespace std;

class Base
{
private:
    int num1;

protected:
    int num2;

public:
    int num3;

    Base() : num1(1), num2(2), num3(3) {}
    int getnum1()
    {
        return num1;
    }
};

class Derived : protected Base
{
public:
    int getnum3()
    {
        return num3;
    }
};

int main()
{
    Derived drv;
    cout << drv.getnum3() << endl;
    // cout << drv.num3() << endl; //compile error!
    return 0;
}