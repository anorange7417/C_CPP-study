#include <iostream>
using namespace std;

class SoBase
{
private:
    int baseNum;

public:
    SoBase() : baseNum(20)
    {
        cout << "SoBase()" << endl;
    }
    SoBase(int n) : baseNum(n)
    {
        cout << "SoBase(int n)" << endl;
    }
    void ShowBaseData()
    {
        cout << baseNum << endl;
    }
};

class Soderived : public SoBase
{
private:
    int derivNum;

public:
    Soderived() : derivNum(30)
    {
        cout << "SoDerived()" << endl;
    }
    Soderived(int n) : derivNum(n)
    {
        cout << "SoDerived(int n)" << endl;
    }
    Soderived(int n1, int n2) : SoBase(n1), derivNum(n2)
    {
        cout << "SoDerived(int n1,int n2)" << endl;
    }
    void ShowDerivData()
    {
        ShowBaseData();
        cout << derivNum << endl;
    }
};

int main()
{
    cout << "case1..... " << endl;
    Soderived dr1;
    dr1.ShowDerivData();
    cout << "--------------" << endl;
    cout << "case2....." << endl;
    Soderived dr2(12);
    dr2.ShowDerivData();
    cout << "--------------" << endl;
    cout << "case3....." << endl;
    Soderived dr3(23, 24);
    dr3.ShowDerivData();
    return 0;
}