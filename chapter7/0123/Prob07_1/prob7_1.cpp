// 주어진 클래스에서 적절한 생성자 삽입하는 문제
// 이를 확인할 수 있도록 main 함수 적절히 정의

#include <iostream>
#include <cstring>
using namespace std;

class Car
{
private:
    int gasolineGauge;

public:
    Car(int mygasolineGauge) : gasolineGauge(mygasolineGauge)
    {
        cout << "Car() : " << gasolineGauge << endl;
    }
    int GetGasGauge()
    {
        return gasolineGauge;
    }
};

class HybridCar : public Car
{
private:
    int electricGauge;

public:
    HybridCar(int myelectricGauge, int mygasolineGauge) : electricGauge(myelectricGauge), Car(mygasolineGauge)
    {
        cout << "HybridCar() : " << endl
             << "Gas: " << GetGasGauge() << endl
             << "Electric: " << electricGauge << endl;
    }
    int GetElectricGauge()
    {
        return electricGauge;
    }
};

class HybridWaterCar : public HybridCar
{
private:
    int waterGauge;

public:
    HybridWaterCar(int mywaterGauge, int mygas, int myelectric) : HybridCar(myelectric, mygas), waterGauge(mywaterGauge)
    {
        cout << "HybridWaterCar(): " << endl
             << "Gas : " << GetGasGauge() << endl
             << "Electric: " << GetElectricGauge() << endl
             << "Water: " << waterGauge << endl;
    }
};

int main()
{
    HybridWaterCar hbdwatercar(30, 50, 40);
    return 0;
}