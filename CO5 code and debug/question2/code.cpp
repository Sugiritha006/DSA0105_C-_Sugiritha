
#include <iostream>
#include <string>
using namespace std;

class BankingException {
protected:
    string msg;

public:
    BankingException(string m) {
        msg = m;
    }

    virtual string getMessage() const {
        return msg;
    }

    virtual ~BankingException() {}
};

class InsufficientFundsException : public BankingException {
private:
    double shortfall;

public:
    InsufficientFundsException(string m, double s)
        : BankingException(m) {
        shortfall = s;
    }

    double getShortfall() const {
        return shortfall;
    }
};

void processWithdrawal(double balance, double amount) {
    if (amount > balance) {
        throw InsufficientFundsException(
            "Account overdrawn", amount - balance
        );
    }

    cout << "Withdrawal successful!" << endl;
}

int main() {
    try {
        processWithdrawal(500.0, 750.0);
    }

    catch (const InsufficientFundsException &e) {
        cout << "Shortfall of Rs. "
             << e.getShortfall() << endl;
    }

    catch (const BankingException &e) {
        cout << "General Banking Error: "
             << e.getMessage() << endl;
    }

    return 0;
}
