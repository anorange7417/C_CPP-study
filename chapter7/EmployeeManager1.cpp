#include <iostream>
#include <cstring>

class PermanentWorker
{
private:
    char name[100];
    int salary;

public:
    PermanentWorker(char *name, int money) : salary(money)
    {
        strcpy(this->name, name);
    }
};