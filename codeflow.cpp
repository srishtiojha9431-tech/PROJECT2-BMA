#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

class Account
{
private:
    long long accountNumber;
    char name[50];
    double balance;

public:
    void createAccount()
    {
        cout << "\nEnter Account Number : ";
        cin >> accountNumber;

        cin.ignore();

        cout << "Enter Customer Name  : ";
        cin.getline(name, 50);

        cout << "Enter Initial Balance: ";
        cin >> balance;
    }

    void displayAccount()
    {
        cout << "\n================================";
        cout << "\nAccount Number : " << accountNumber;
        cout << "\nCustomer Name  : " << name;
        cout << "\nCurrent Balance: " << balance;
        cout << "\n================================\n";
    }

    long long getAccountNumber()
    {
        return accountNumber;
    }

    double getBalance()
    {
        return balance;
    }

    void deposit(double amount)
    {
        balance += amount;
    }

    bool withdraw(double amount)
    {
        if (amount > balance)
        {
            return false;
        }

        balance -= amount;
        return true;
    }
};


// CREATE ACCOUNT
void createNewAccount()
{
    Account acc;

    ofstream file("bank.dat", ios::binary | ios::app);

    if (!file)
    {
        cout << "\nError Opening File!\n";
        return;
    }

    acc.createAccount();

    file.write(reinterpret_cast<char*>(&acc), sizeof(Account));

    file.close();

    cout << "\nAccount Created Successfully!\n";
}


// DISPLAY ALL ACCOUNTS
void displayAllAccounts()
{
    Account acc;

    ifstream file("bank.dat", ios::binary);

    if (!file)
    {
        cout << "\nNo Accounts Found!\n";
        return;
    }

    cout << "\n========== ACCOUNT DETAILS ==========\n";

    bool found = false;

    while (true)
    {
        file.read(reinterpret_cast<char*>(&acc), sizeof(Account));

        // STOP when file reading ends
        if (file.eof())
        {
            break;
        }

        // CHECK invalid/corrupted data
        if (file.fail())
        {
            break;
        }

        // DISPLAY only valid accounts
        if (acc.getAccountNumber() > 0)
        {
            acc.displayAccount();
            found = true;
        }
    }

    if (!found)
    {
        cout << "\nNo Valid Accounts Available!\n";
    }

    file.close();
}


// SEARCH ACCOUNT
void searchAccount()
{
    long long accNo;
    bool found = false;

    cout << "\nEnter Account Number : ";
    cin >> accNo;

    Account acc;

    ifstream file("bank.dat", ios::binary);

    while (file.read(reinterpret_cast<char*>(&acc), sizeof(Account)))
    {
        if (acc.getAccountNumber() == accNo)
        {
            cout << "\nAccount Found!\n";
            acc.displayAccount();

            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "\nAccount Not Found!\n";
    }

    file.close();
}


// DEPOSIT MONEY
void depositAmount()
{
    long long accNo;
    double amount;
    bool found = false;

    cout << "\nEnter Account Number : ";
    cin >> accNo;

    cout << "Enter Deposit Amount : ";
    cin >> amount;

    Account acc;

    fstream file("bank.dat", ios::binary | ios::in | ios::out);

    while (file.read(reinterpret_cast<char*>(&acc), sizeof(Account)))
    {
        if (acc.getAccountNumber() == accNo)
        {
            acc.deposit(amount);

            file.seekp(-static_cast<int>(sizeof(Account)), ios::cur);

            file.write(reinterpret_cast<char*>(&acc), sizeof(Account));

            cout << "\nAmount Deposited Successfully!\n";

            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "\nAccount Not Found!\n";
    }

    file.close();
}


// WITHDRAW MONEY
void withdrawAmount()
{
    long long accNo;
    double amount;
    bool found = false;

    cout << "\nEnter Account Number : ";
    cin >> accNo;

    cout << "Enter Withdraw Amount : ";
    cin >> amount;

    Account acc;

    fstream file("bank.dat", ios::binary | ios::in | ios::out);

    while (file.read(reinterpret_cast<char*>(&acc), sizeof(Account)))
    {
        if (acc.getAccountNumber() == accNo)
        {
            if (acc.withdraw(amount))
            {
                file.seekp(-static_cast<int>(sizeof(Account)), ios::cur);

                file.write(reinterpret_cast<char*>(&acc), sizeof(Account));

                cout << "\nWithdrawal Successful!\n";
            }
            else
            {
                cout << "\nInsufficient Balance!\n";
            }

            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "\nAccount Not Found!\n";
    }

    file.close();
}


// CHECK BALANCE
void checkBalance()
{
    long long accNo;
    bool found = false;

    cout << "\nEnter Account Number : ";
    cin >> accNo;

    Account acc;

    ifstream file("bank.dat", ios::binary);

    while (file.read(reinterpret_cast<char*>(&acc), sizeof(Account)))
    {
        if (acc.getAccountNumber() == accNo)
        {
            cout << "\nCurrent Balance : " << acc.getBalance() << endl;

            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "\nAccount Not Found!\n";
    }

    file.close();
}


// MAIN FUNCTION
int main()
{
    int choice;

    do
    {
        cout << "\n========== BANK MANAGEMENT SYSTEM ==========\n";
        cout << "1. Create New Account\n";
        cout << "2. Display All Accounts\n";
        cout << "3. Search Account\n";
        cout << "4. Deposit Amount\n";
        cout << "5. Withdraw Amount\n";
        cout << "6. Check Balance\n";
        cout << "7. Exit\n";
        cout << "============================================\n";

        cout << "Enter Your Choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            createNewAccount();
            break;

        case 2:
            displayAllAccounts();
            break;

        case 3:
            searchAccount();
            break;

        case 4:
            depositAmount();
            break;

        case 5:
            withdrawAmount();
            break;

        case 6:
            checkBalance();
            break;

        case 7:
            cout << "\nThank You For Using Bank Management System!\n";
            break;

        default:
            cout << "\nInvalid Choice! Please Try Again.\n";
        }

    } while (choice != 7);

    return 0;
}
