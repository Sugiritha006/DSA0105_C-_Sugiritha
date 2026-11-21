
#include <iostream>
#include <string>
using namespace std;

class TransactionException {
public:
    string message;

    TransactionException(string msg) {
        message = msg;
    }
};

class FrozenAccountException : public TransactionException {
public:
    FrozenAccountException()
        : TransactionException("Account is frozen.") {}
};

class DailyLimitExceededException : public TransactionException {
public:
    DailyLimitExceededException()
        : TransactionException("Daily withdrawal limit exceeded.") {}
};

class Account {
private:
    double balance;
    bool frozen;
    double dailyLimit;

public:
    Account(double b, bool f, double limit) {
        balance = b;
        frozen = f;
        dailyLimit = limit;
    }

    void withdraw(double amount) {
        try {
            if (frozen) {
                throw FrozenAccountException();
            }

            if (amount > dailyLimit) {
                throw DailyLimitExceededException();
            }

            if (amount > balance) {
                throw TransactionException(
                    "Insufficient account balance."
                );
            }

            balance -= amount;

            cout << "Withdrawal Successful: Rs. "
                 << amount << endl;
        }

        catch (const FrozenAccountException &e) {
            cout << "Frozen Account Error: "
                 << e.message << endl;
            throw;
        }

        catch (const TransactionException &e) {
            cout << "Transaction Error: "
                 << e.message << endl;
            throw;
        }
    }

    void displayBalance() {
        cout << "Balance: Rs. " << balance << endl;
    }
};

int main() {
    Account account(50000, false, 10000);

    try {
        account.withdraw(15000);
    }
    catch (const TransactionException &e) {
        cout << "Main Handler: "
             << e.message << endl;
    }

    account.displayBalance();

    return 0;
}
