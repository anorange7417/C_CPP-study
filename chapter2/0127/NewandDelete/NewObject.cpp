#include <iostream>
#include <stdlib.h>
using namespace std;

class Simple
{
public:
    Simple()
    {
        cout << "I'm simple constructor!" << endl;
    }
};

int main()
{
    cout << "case 1: ";
    Simple *sp1 = new Simple;

    cout << "case 2:";
    Simple *sp2 = (Simple *)malloc(sizeof(Simple) * 1); // new실행 시 생성자 내 cout 구문 실행되지만, malloc 실행 시 그렇지 않다. (동작 방식의 차이)
    cout << endl
         << "end of main" << endl;
    delete sp1;
    return 0;
}