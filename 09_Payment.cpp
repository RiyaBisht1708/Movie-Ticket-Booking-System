#include <string>
using namespace std;

class Payment {
public:
    virtual bool pay(double amount) = 0;
    virtual string methodName() const = 0;
    virtual ~Payment() = default;
};
