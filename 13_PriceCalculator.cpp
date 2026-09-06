#include <vector>
using namespace std;

class PriceCalculator {
private:
    const double SILVER_PRICE = 150.0;
    const double GOLD_PRICE = 250.0;
    const double PLATINUM_PRICE = 400.0;

public:
    double calculateTotal(const vector<ShowSeat>& seats) const {
        double total = 0.0;
        for (const auto& seat : seats) {
            if (seat.getSeatType() == "SILVER") {
                total += SILVER_PRICE;
            } else if (seat.getSeatType() == "GOLD") {
                total += GOLD_PRICE;
            } else if (seat.getSeatType() == "PLATINUM") {
                total += PLATINUM_PRICE;
            }
        }
        return total;
    }
};
