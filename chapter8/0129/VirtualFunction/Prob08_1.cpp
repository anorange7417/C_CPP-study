#include <iostream>
#include <cstring>
using namespace std;

namespace RISK_LEVEL
{
enum
{
    RISK_A = 3,
    RISK_B = 2,
    RISK_C = 1
};
}

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
    virtual void ShowInfo() const = 0;
};

// Derived class
class ForeignSalesWorker : public Employee
{
private:
    int salary;
    double bonusRatio;
    int risklevel;

public:
    ForeignSalesWorker(char *name, int mysalary, double myratio, int myrisklevel) : Employee(name), salary(mysalary), bonusRatio(myratio), risklevel(myrisklevel) {}
    void AddSalesResult(int mysale)
    {
        salary += mysale * bonusRatio;
        salary += salary * bonusRatio * risklevel;
    }
    void ShowInfo() const
    {
        ShowYourName();
        cout << "salary: " << salary << endl;
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
    void ShowAllSalaryInfo() const
    {
        for (int i = 0; i < empNum; i++)
            empList[i]->ShowInfo();
    }
    ~Employeehandler()
    {
        for (int i = 0; i < empNum; i++)
            delete empList[i];
    }
};

int main()
{
    Employeehandler handler;

    // 해외 영업직 등록
    ForeignSalesWorker *fseller1 = new ForeignSalesWorker("Hong", 1000, 0.1, RISK_LEVEL::RISK_A);
    fseller1->AddSalesResult(7000);
    handler.AddEmployee(fseller1);

    ForeignSalesWorker *fseller2 = new ForeignSalesWorker("Yoon", 1000, 0.1, RISK_LEVEL::RISK_B);
    fseller2->AddSalesResult(7000);
    handler.AddEmployee(fseller2);

    ForeignSalesWorker *fseller3 = new ForeignSalesWorker("Lee", 1000, 0.1, RISK_LEVEL::RISK_C);
    fseller3->AddSalesResult(7000);
    handler.AddEmployee(fseller3);

    handler.ShowAllSalaryInfo();
    return 0;
}