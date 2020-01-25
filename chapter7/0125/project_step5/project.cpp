#include <iostream>
#include <cstring>
using namespace std;
const int NAME_LEN = 20;

enum
{
    MAKE = 1,
    DEPOSIT,
    WITHDRAW,
    INQUIRE,
    EXIT
};

// Entity class : class where saves data
class Account
{
private:
    int accID;
    int balance;
    char *cusName;

public:
    Account(int ID, int money, char *name);
    Account(const Account &ref);

    int GetAccID() const;
    void Deposit(int money);
    int Withdraw(int money);
    void ShowAccInfo() const;
    ~Account();
};

Account::Account(int ID, int money, char *name) : accID(ID), balance(money)
{
    cusName = new char[strlen(name) + 1];
    strcpy(cusName, name);
}

Account::Account(const Account &ref) : accID(ref.accID), balance(ref.balance) // need study about reference
{
    cusName = new char[strlen(ref.cusName) + 1];
    strcpy(cusName, ref.cusName);
}

int Account::GetAccID() const { return accID; }

void Account::Deposit(int money)
{
    balance += money;
}

int Account::Withdraw(int money)
{
    if (balance < money)
        return 0;
    balance -= money;
    return money;
}

void Account::ShowAccInfo() const
{
    cout << "Account ID: " << accID << endl;
    cout << "Name: " << cusName << endl;
    cout << "Balance: " << balance << endl;
}

Account::~Account()
{
    delete[] cusName;
}

// Control class : class where essential functions are described
class AccountHandler
{
private:
    Account *accArr[100];
    int accNum;

public:
    AccountHandler();
    void ShowMenu() const;
    void MakeAccount();
    void DepositMoney();
    void WithdrawMoney();
    void ShowAllAccInfo() const;
    ~AccountHandler();
};

void AccountHandler::ShowMenu() const
{
    cout << "-----Menu-----" << endl;
    cout << "1. Create New Account" << endl;
    cout << "2. Deposit" << endl;
    cout << "3. Witdrawl" << endl;
    cout << "4. Show all accounts" << endl;
    cout << "5. Terminate program" << endl;
}

void AccountHandler::MakeAccount()
{
    int id;
    char name[NAME_LEN];
    int balance;

    cout << "[Create an Account]" << endl;
    cout << "AccountID: ";
    cin >> id;
    cout << "Name: ";
    cin >> name;
    cout << "Deposit: ";
    cin >> balance;
    cout << endl;

    accArr[accNum++] = new Account(id, balance, name);
}

void AccountHandler::DepositMoney()
{
    int money;
    int id;
    cout << "[Deposit]" << endl;
    cout << "AccountID: ";
    cin >> id;
    cout << "Amount: ";
    cin >> money;

    for (int i = 0; i < accNum; i++)
    {
        if (accArr[i]->GetAccID() == id)
        {
            accArr[i]->Deposit(money);
            cout << "Deposit Complete" << endl
                 << endl;
            return;
        }
        cout << "It's not a valid ID" << endl
             << endl;
    }
}

void AccountHandler::WithdrawMoney()
{
    int money;
    int id;
    cout << "[Witdrawl]" << endl;
    cout << "AccountID: ";
    cin >> id;
    cout << "Amount: ";
    cin >> money;

    for (int i = 0; i < accNum; i++)
    {
        if (accArr[i]->GetAccID() == id)
        {
            if (accArr[i]->Withdraw(money) <= 0)
            {
                cout << "Not enough balance" << endl
                     << endl;
                return;
            }
            cout << "Withdrawl Complete" << endl
                 << endl;
            return;
        }
    }
    cout << "It's not a valid ID" << endl
         << endl;
}

AccountHandler::AccountHandler() : accNum(0) {}

void AccountHandler::ShowAllAccInfo() const
{
    for (int i = 0; i < accNum; i++)
    {
        accArr[i]->ShowAccInfo();
        cout << endl;
    }
}

AccountHandler::~AccountHandler()
{
    for (int i = 0; i < accNum; i++)
        delete accArr[i];
}

int main()
{
    AccountHandler manager;
    int choice;

    while (1)
    {
        manager.ShowMenu();
        cout << "Choice: ";
        cin >> choice;
        cout << endl;

        switch (choice)
        {
        case MAKE:
            manager.MakeAccount();
            break;
        case DEPOSIT:
            manager.DepositMoney();
            break;
        case WITHDRAW:
            manager.WithdrawMoney();
            break;
        case INQUIRE:
            manager.ShowAllAccInfo();
            break;
        case EXIT:
            return 0;
        default:
            cout << "Illegal selection.." << endl;
        }
    }
    return 0;
}