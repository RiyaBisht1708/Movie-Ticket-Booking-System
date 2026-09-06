#include <memory>
#include <string>
using namespace std;

class ShowSeat {
private:
    Seat seat;
    shared_ptr<string> status;

public:
    ShowSeat(Seat s = Seat(), string st = "AVAILABLE")
        : seat(s), status(make_shared<string>(st)) {}

    bool isAvailable() const { return *status == "AVAILABLE"; }

    void bookSeat() {
        if (isAvailable()) {
            *status = "BOOKED";
        }
    }

    void releaseSeat() { *status = "AVAILABLE"; }

    string getSeatNumber() const { return seat.getNumber(); }
    string getSeatType() const { return seat.getType(); }
    string getStatus() const { return *status; }
};
