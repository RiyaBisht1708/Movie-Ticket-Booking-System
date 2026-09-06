#include <string>
#include <vector>
using namespace std;

class Booking {
private:
    static int nextBookingId;
    int bookingId;
    Show show;
    vector<ShowSeat> seats;
    double totalAmount;
    string status;

public:
    Booking(const Show& s, const vector<ShowSeat>& ss, double a)
        : bookingId(nextBookingId++), show(s), seats(ss), totalAmount(a), status("PENDING") {}

    Booking(const Show& s, const vector<ShowSeat>& ss)
        : bookingId(nextBookingId++), show(s), seats(ss), totalAmount(0), status("PENDING") {}

    void confirm() { status = "CONFIRMED"; }

    void cancel() {
        for (auto& seat : seats) {
            seat.releaseSeat();
        }
        status = "CANCELLED";
    }

    int getBookingId() const { return bookingId; }
    double getTotalAmount() const { return totalAmount; }
    string getStatus() const { return status; }
    Show getShow() const { return show; }
    const vector<ShowSeat>& getSeats() const { return seats; }
};

int Booking::nextBookingId = 1001;
