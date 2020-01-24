#include <iostream>
#include <cstring>
using namespace std;

class Computer
{
private:
    char owner[50];

public:
    Computer(char *name)
    {
        strcpy(owner, name);
    }
    void Calculate()
    {
        cout << "Calculating your order..." << endl;
    }
};

class NotebookComp : public Computer
{
private:
    int Battery;

public:
    NotebookComp(char *name, int initChag) : Computer(name), Battery(initChag) {}
    void Charging() { Battery += 5; }
    void UseBattery() { Battery -= 1; }
    void MovingCal()
    {
        if (GetBatteryInfo() < 1)
        {
            cout << "Need Charging!" << endl;
            return;
        }
        cout << "I am moving and ...";
        Calculate();
        UseBattery();
    }
    int GetBatteryInfo() { return Battery; }
};

class TabletNotebook : public NotebookComp
{
private:
    char regstPenModel[50];

public:
    TabletNotebook(char *name, int initChag, char *pen) : NotebookComp(name, initChag)
    {
        strcpy(regstPenModel, pen);
    }
    void Write(char *penInfo)
    {
        if (GetBatteryInfo() < 1)
        {
            cout << "I need charging!" << endl;
            return;
        }
        if (strcmp(regstPenModel, penInfo) != 0)
        {
            cout << "You are using unregistered pen";
            return;
        }
        cout << "Processing your writings..." << endl;
        UseBattery();
    }
};

int main()
{
    NotebookComp nc("이수종", 5);
    TabletNotebook tn("정수영", 5, "ISE-241-242");
    nc.MovingCal();
    tn.Write("ISE-241-242");
    return 0;
}