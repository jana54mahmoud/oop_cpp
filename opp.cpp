#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class BankAccount {
private:
    string accountNumber;
    string accountHolderName;
    double balance;

public:
    BankAccount(string account_num, string account_holder, double set_balance = 0.0) {
        accountNumber = account_num;
        accountHolderName = account_holder;

        if (set_balance < 0) {
            cout << " Erorr,Initial balance cannot be negative\n";
            balance = 0.0;
        } else {
            balance = set_balance;
        }
    }
    void deposit(double value) {
        if (value <= 0) {
            cout << "Deposit must be positive.\n";
            return;
        }
        balance += value;
        cout << "Deposited " << value << " into account " << accountNumber << ".\n";
    }
    void withdraw(double value) {
        if (value <= 0) {
            cout << "Withdrawal must be positive.\n";
            return;
        }
        if (value > balance) {
            cout << "Balance is not enough. Current balance is " << balance << "\n";
            return;
        }
        balance -= value;
        cout << "Withdrew " << value << " from account " << accountNumber << "\n";
    }
    void display_information() const {
        cout << "Account Number : " << accountNumber << "\n";
        cout << "Account Holder : " << accountHolderName << "\n";
        cout << "Balance        : " << balance << "\n";
       
    }
};

int main() {
    BankAccount account1("Aknx011", "jana", 500.00);
    BankAccount account2("Aknx012", "mohamed", 1000.00);

    cout << "  Account Details : \n";
    account1.display_information();
    account2.display_information();

    cout << "\n Perform Transactions : \n";
    account1.deposit(150.00);
    account1.withdraw(200.00);
    account1.withdraw(1000.00);

    account2.deposit(75.50);
    account2.withdraw(20.00);
    account2.withdraw(-5.00);

    cout << "\n Last Details After Transactions: \n";
    account1.display_information();
    account2.display_information();

    return 0;
}