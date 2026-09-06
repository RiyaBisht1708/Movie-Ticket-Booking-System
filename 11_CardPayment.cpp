#include <iostream>
#include <string>
using namespace std;

class CardPayment : public Payment {
private:
    string cardNumber;
    string cardHolderName;
    string expiryDate;

public:
    CardPayment(string n = "XXXX-1234", string h = "Customer", string e = "12/29")
        : cardNumber(n), cardHolderName(h), expiryDate(e) {}

    bool pay(double amount) override {
        cout << "Processing Card payment of Rs." << amount << "...\n";
        return true;
    }

    string methodName() const override { return "CARD"; }
};
