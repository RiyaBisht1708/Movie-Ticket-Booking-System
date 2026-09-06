#include <iostream>
#include <string>
using namespace std;

class CashPayment : public Payment {
public:
    bool pay(double amount) override {
        cout << "Processing Cash payment of Rs." << amount << "...\n";
        return true;
    }

    string methodName() const override { return "CASH"; }
};
