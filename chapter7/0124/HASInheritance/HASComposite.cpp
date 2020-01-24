#include <iostream>
#include <cstring>
using namespace std;

class Gun
{
private:
    int bullet;

public:
    Gun(int bnum) : bullet(bnum) {}
    void Shot()
    {
        cout << "BBAM!" << endl;
        bullet--;
    }
};

class Police
{
private:
    int handcuffs;
    Gun *pistol;

public:
    Police(int bnum, int bcuff) : handcuffs(bcuff)
    {
        if (bnum > 0)
            pistol = new Gun(bnum);
        else
        {
            pistol = NULL;
        }
    }
    void PutHandcuff()
    {
        cout << "Gotcha!" << endl;
        handcuffs--;
    }
    void Shot()
    {
        if (pistol == NULL)
            cout << "No Bullet!" << endl;
        else
            pistol->Shot();
    }
};

int main()
{
    Police pman1(5, 3);
    pman1.Shot();
    pman1.Shot();
    pman1.PutHandcuff();

    Police pman2(0, 3);
    pman2.Shot();
    pman2.Shot();
    pman2.Shot();
    pman2.PutHandcuff();
    return 0;
}