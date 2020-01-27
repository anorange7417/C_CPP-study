#include <iostream>
using namespace std;

int main()
{
    const int num = 12;
    // const int *ptr = &num;
    const int *ptr = &num;
    const int *(&rptr) = ptr;
    cout << "num: " << num << endl;
    cout << "ptr: " << *ptr << endl;
    cout << "rptr: " << *rptr << endl;
    return 0;
}