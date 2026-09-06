#include <iomanip>
#include <iostream>
using namespace std;

class TicketPrinter {
public:
    void printTicket(const Booking& booking) const {
        cout << "\n========================================\n"
             << "MOVIE TICKET\n"
             << "========================================\n";
        cout << "Booking ID : BK" << booking.getBookingId() << "\n";
        cout << "Movie      : " << booking.getShow().getMovie().getTitle() << "\n";
        cout << "Screen     : " << booking.getShow().getScreen().getScreenNumber() << "\n";
        cout << "Show Time  : " << booking.getShow().getShowTime() << "\n";
        cout << "Seats      : ";

        for (size_t i = 0; i < booking.getSeats().size(); ++i) {
            if (i > 0) {
                cout << ", ";
            }
            cout << booking.getSeats()[i].getSeatNumber();
        }

        cout << "\n" << fixed << setprecision(2)
             << "Total      : Rs." << booking.getTotalAmount() << "\n"
             << "Status     : " << booking.getStatus() << "\n"
             << "========================================\n";
    }
};
