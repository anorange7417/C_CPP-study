#include <iostream>
using namespace std;

int Addone(int &mynum)
{
    return mynum + 1;
}

int ChangeSign(int &mynum)
{
    return -mynum;
}

int main()
{
    int original = 10;
    cout << "Addone(): " << Addone(original) << endl;
    cout << "ChangeSign(): " << ChangeSign(original) << endl;
    return 0;
}