#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string ownerName;
    string accountNumber;
    double balance;
    static int total_accounts;
public:
    BankAccount() {
        ownerName = "Unknown";
        accountNumber = "0000";
        balance = 0.0;
        total_accounts++;
    }
    BankAccount(const string &name, const string &account_num, double set_balance) {
        ownerName = name;
        accountNumber = account_num;
        if (set_balance < 0) {
            cout << "Set balance cannot be negative. Set to 0.\n";
            balance = 0.0;
        } else {
            balance = set_balance;
        }
        total_accounts++;
    }
    BankAccount(const string &name, const string &account_num) {
        ownerName = name;
        accountNumber = account_num;
        balance = 0.0;
        total_accounts++;
    }
    BankAccount(const BankAccount &acc_banks) {
        ownerName = acc_banks.ownerName;
        accountNumber = acc_banks.accountNumber;
        balance = acc_banks.balance;
        total_accounts++;
    }
    ~BankAccount() {
        total_accounts--;
    }
    string getOwnerName() const { return ownerName; }
    string getAccountNumber() const { return accountNumber; }
    double getBalance() const { return balance; }
    void deposit(double value) {
        if (value > 0) {
            balance += value;
            cout << "Deposited " << value << " successfully.\n";
        } else {
            cout << "Deposit must be positive.\n";
        }
    }
    void deposit(double value, const string &accounts) {
        if (value > 0) {
            balance += value;
            cout << "Deposited " << value << " from " << accounts << "\n";
        } else {
            cout << "Deposit must be positive.\n";
        }
    }
    bool transfer(BankAccount &val, double value) {
        if (value > 0 && balance >= value) {
            balance -= value;
            val.balance += value;
            cout << "Transferred " << value << " from " << ownerName
                 << " to " << val.ownerName << " \n";
            return true;
        }
        cout << "Transfer failed! Insufficient balance or invalid amount.\n";
        return false;
    }
    static int getTotalAccounts() {
        return total_accounts;
    }
    double operator + (const BankAccount &account) const {
        return balance + account.balance;
    }
    bool operator == (const BankAccount &account) const {
        if (accountNumber == account.accountNumber) {
            if (ownerName == account.ownerName) {
                return true;
            }
        }
        return false;
    }
};

int BankAccount::total_accounts = 0;
int main() {
    BankAccount account1("Jana", "Aph101", 5000.0);
    BankAccount account2("mohamed", "Vgh102", 2000.0);
    cout << "Total accounts: " << BankAccount::getTotalAccounts() << "\n\n";
    account1.deposit(1000);
    account1.deposit(500.50, "salary");
    cout << "Jana's Balance: " << account1.getBalance() << "\n\n";
    account1.transfer(account2, 1500.0);
    cout << "mohamed's new Balance : " << account2.getBalance() << "\n\n";
    cout << "Total balance : " << (account1 + account2) << "\n\n";
    BankAccount account3("Jana", "AAph101", 5000.0);
    if (account1 == account3) {
        cout << "account1 and account3 are the same account!\n";
    } else {
        cout << "account1 and account3 are different accounts!\n";
    }

    return 0;
}