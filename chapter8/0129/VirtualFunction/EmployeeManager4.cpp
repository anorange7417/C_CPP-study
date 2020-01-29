#include <iostream>
#include <cstring>
using namespace std;

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
    virtual int GetPay() const = 0;

    virtual void ShowSalaryInfo() const = 0; // virtual 선언 안 해주면 Employee * varname = new PermanentWorker()로 생성한 varname 객체에 대하여 오버라이드 된 함수인
                                             // GetPay()와 ShowSalaryInfo() 가 Employee 객체 내용으로 실행됨. 객체 포인터가 실제로 참조하는 멤버 사용하려면 상위 클래스
                                             // 멤버함수에 꼭 virtual 선언 해줄 것. line 110, 116 참고
};

class PermanentWorker : public Employee
{
private:
    int salary;

public:
    PermanentWorker(char *name, int money) : Employee(name), salary(money) {}
    int GetPay() const
    {
        return salary;
    }
    void ShowSalaryInfo() const
    {
        ShowYourName();
        cout << "salary: " << GetPay() << endl
             << endl;
    }
    void AddSalesResult(int vlaue) {}
};

class TemporaryWorker : public Employee
{
private:
    int workTime;
    int payPerHour;

public:
    TemporaryWorker(char *name, int pay) : Employee(name), workTime(0), payPerHour(pay) {}
    void AddWorkTime(int time)
    {
        workTime += time;
    }
    int GetPay() const
    {
        return workTime * payPerHour;
    }
    void ShowSalaryInfo() const
    {
        ShowYourName();
        cout << "salary: " << GetPay() << endl
             << endl;
    }
};

class SalesWorker : public PermanentWorker
{
private:
    int salesResult;
    double bonusRatio;

public:
    SalesWorker(char *name, int money, double ratio) : PermanentWorker(name, money), salesResult(0), bonusRatio(ratio) {}
    void AddSalesResult(int value)
    {
        salesResult += value;
    }
    int GetPay() const
    {
        return PermanentWorker::GetPay() + (int)(salesResult * bonusRatio);
    }
    void ShowSalaryInfo() const
    {
        ShowYourName();
        cout << "salary: " << GetPay() << endl
             << endl;
    }
};

class EmployeeHandler
{
private:
    Employee *empList[50];
    int empNum;

public:
    EmployeeHandler() : empNum(0) {}
    void AddEmployee(Employee *emp)
    {
        empList[empNum++] = emp;
    }
    void ShowAllSalaryInfo() const
    {
        for (int i = 0; i < empNum; i++)
            empList[i]->ShowSalaryInfo(); // virtual를 선언해줘야 하는 이유
    }
    void ShowTotalSalary() const
    {
        int sum = 0;
        for (int i = 0; i < empNum; i++)
            sum += empList[i]->GetPay(); // virtual를 선언해줘야 하는 이유
        cout << "salary sum: " << sum << endl;
    }
    ~EmployeeHandler()
    {
        for (int i = 0; i < empNum; i++)
            delete empList[i];
    }
};

int main()
{
    // Employee * emp = new Employee("LDS"); // Employee 객체 안에 순수 가상함수가  포함되어 있으면, 그 객체는 추상객체로 객체 생성이 불가능하게 막아놓는 역할을 한다.
    EmployeeHandler handler;
    handler.AddEmployee(new PermanentWorker("KIM", 1000));
    handler.AddEmployee(new PermanentWorker("LEE", 1500));

    TemporaryWorker *alba = new TemporaryWorker("Jung", 700);
    alba->AddWorkTime(5);
    handler.AddEmployee(alba);

    // PermanentWorker *seller = new SalesWorker("Hong", 1000, 0.1);
    // PermanentWorker 형으로 SaelsWorker를 정의하고 PermanentWorker 멤버에 AddSaelsResult를 virtual로
    // 정의하면 seller->AddSalesResult실행시 오버라이드 한 SalesWorker의 AddSalesResult를 실행할 수 있으나
    // SalesWorker의 private 멤버인 salesResult와 bonus ratio가 없어 성과급이 지급이 안된다.

    SalesWorker *seller = new SalesWorker("Hong", 1000, 0.1);
    seller->AddSalesResult(7000);
    handler.AddEmployee(seller);

    handler.ShowAllSalaryInfo();

    handler.ShowTotalSalary();
    return 0;
}