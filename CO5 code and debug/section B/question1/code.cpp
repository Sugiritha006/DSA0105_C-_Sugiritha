
#include <iostream>
#include <string>
using namespace std;

class PaymentGateway {
public:
    virtual bool authorize(double amount) = 0;
    virtual bool capture() = 0;

    virtual ~PaymentGateway() {}
};

class CreditCardGateway : public PaymentGateway {
private:
    string cardNumber;
    string cvv;

public:
    CreditCardGateway(string card, string code) {
        cardNumber = card;
        cvv = code;
    }

    bool authorize(double amount) override {
        if (cardNumber.length() == 16 &&
            cvv.length() == 3 &&
            amount > 0) {
            cout << "Credit Card Authorized: Rs. "
                 << amount << endl;
            return true;
        }

        return false;
    }

    bool capture() override {
        cout << "Credit Card Payment Captured."
             << endl;
        return true;
    }
};

class CryptoGateway : public PaymentGateway {
private:
    string walletAddress;

public:
    CryptoGateway(string wallet) {
        walletAddress = wallet;
    }

    bool authorize(double amount) override {
        if (walletAddress.substr(0, 2) == "0x"
            && amount > 0) {
            cout << "Crypto Payment Authorized: Rs. "
                 << amount << endl;
            return true;
        }

        return false;
    }

    bool capture() override {
        cout << "Crypto Payment Captured."
             << endl;
        return true;
    }
};

int main() {
    PaymentGateway *gateway;

    CreditCardGateway card(
        "1234567890123456", "123"
    );

    gateway = &card;

    if (gateway->authorize(1500)) {
        gateway->capture();
    }

    CryptoGateway crypto("0xABC123");

    gateway = &crypto;

    if (gateway->authorize(2000)) {
        gateway->capture();
    }

    return 0;
}
