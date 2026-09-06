#include <iostream>
#include <string>
using namespace std;

class UpiPayment : public Payment {
private:
    string upiId;

public:
    UpiPayment(string id = "customer@upi") : upiId(id) {}

    bool pay(double amount) override {
        cout << "Processing UPI payment of Rs." << amount << "...\n";
        return true;
    }

    string methodName() const override { return "UPI"; }
};
