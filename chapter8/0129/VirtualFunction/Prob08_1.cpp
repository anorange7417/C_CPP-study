#include <iostream>
#include <cstring>
using namespace std;

// virtual class
class Employee
{
private:
    char name[100];

public:
    Employee(char *name)
    {
        strcpy(this->name, name);
    }
    void ShowYourName() const
    {
        cout << "name: " << name << endl;
    }
};

// Derived class
class ForeignSalesWorker : public Employee
{
private:
    int salary;
    int bonusRatio;
    int risklevel;

public:
    ForeignSalesWorker(char *name, int mysalary, int myratio, int myrisklevel) : Employee(name), salary(mysalary), bonusRatio(myratio), risklevel(myrisklevel) {}
    void AddSalesResult(int mysale)
    {
        salary += mysale * bonusRatio;
    }
};

// Controller
class Employeehandler
{
private:
    Employee *empList[10];
    int empNum;

public:
    Employeehandler() : empNum(0) {}
    void AddEmployee(Employee *myemp)
    {
        empList[empNum++] = myemp;
    }
};