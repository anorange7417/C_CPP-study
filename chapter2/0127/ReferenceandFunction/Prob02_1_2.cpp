#include <iostream>
using namespace std;

void SwapByRef(int &num1, int &num2)
{
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

void SwapByRef(const int &num1, const int &num2)
{
    // 10,20은 상수형 변수로 앞에 const를 붙여야 컴파일 에러가 일어나지 않는다는것을 보여주기 위함
}

int main()
{
    int a = 10;
    int b = 20;
    SwapByRef(a, b);
    SwapByRef(10, 20);
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    return 0;
}