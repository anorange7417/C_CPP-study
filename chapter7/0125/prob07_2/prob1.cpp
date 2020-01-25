#include <iostream>
using namespace std;
class Rectangle
{
private:
    int garo;
    int sero;

public:
    Rectangle(int mygaro, int mysero)
    {
        garo = mygaro;
        sero = mysero;
    }
    void ShowAreaInfo()
    {
        cout << "Area : " << garo * sero << endl;
    }
};

class Square : public Rectangle
{
private:
    int length;

public:
    Square(int mylength) : Rectangle(mylength, mylength), length(mylength) {}
};

int main()
{
    Rectangle rec(4, 3);
    rec.ShowAreaInfo();

    Square sqr(7);
    sqr.ShowAreaInfo();
    return 0;
}