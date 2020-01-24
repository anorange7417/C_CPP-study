#include <cstring>
#include <iostream>
using namespace std;

int main()
{
    char *nameptr;
    char name[20];
    strcpy(nameptr, "cho");
    // strcpy(name, "cho");
    cout << "nameptr: " << nameptr << endl;
    //  << "name: " << name << endl;
    return 0;
}