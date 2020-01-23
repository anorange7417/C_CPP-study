// define appropriate constructor and destructor for the two classes below.
// Also define proper main() to checkout what you have defined in those two classes.

#include <iostream>
#include <cstring>
using namespace std;

class MyFriendInfo
{
private:
    char *name;
    int age;

public:
    MyFriendInfo(char *myname, int myage) : age(myage)
    {
        name = new char[strlen(myname) + 1];
        strcpy(name, myname);
    }
    void ShowMyFriendInfo()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
    ~MyFriendInfo()
    {
        delete[] name;
    }
};

class MyFriendDetailInfo : public MyFriendInfo
{
private:
    char *addr;
    char *phone;

public:
    MyFriendDetailInfo(char *yourname, int yourage, char *youraddress, char *yourphone) : MyFriendInfo(yourname, yourage)
    {
        addr = new char[strlen(youraddress) + 1];
        strcpy(addr, youraddress);
        phone = new char[strlen(yourphone) + 1];
        strcpy(phone, yourphone);
    }
    void ShowMyFriendDetailInfo()
    {
        ShowMyFriendInfo();
        cout << "Address: " << addr << endl;
        cout << "Phone Num: " << phone << endl;
    }
    ~MyFriendDetailInfo()
    {
        delete[] addr;
        delete[] phone;
    }
};

int main()
{
    MyFriendDetailInfo Yonghyeon("Cho", 26, "255-5, Sinlim, Seoul, Korea", "010-5675-7417");
    Yonghyeon.ShowMyFriendDetailInfo();
    return 0;
}