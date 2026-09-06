#include <iostream>
#include <string>
#include <vector>
using namespace std;

class BookingService {
private:
    PriceCalculator priceCalculator;
    TicketPrinter ticketPrinter;

public:
    Booking bookTicket(Customer& customer, Show& show, const vector<string>& requestedSeats, Payment& payment) {
        cout << "\nCustomer: " << customer.getName() << "\n";

        vector<ShowSeat*> selected;
        for (const string& seatNumber : requestedSeats) {
            ShowSeat* seat = show.findSeat(seatNumber);
            if (!seat) {
                cout << "Seat " << seatNumber << " does not exist. Booking rejected.\n";
                return Booking(show, {});
            }

            if (!seat->isAvailable()) {
                cout << "Seat " << seatNumber << " is already BOOKED. Booking rejected.\n";
                return Booking(show, {});
            }

            for (auto* existingSeat : selected) {
                if (existingSeat->getSeatNumber() == seatNumber) {
                    cout << "Duplicate seat selected. Booking rejected.\n";
                    return Booking(show, {});
                }
            }

            selected.push_back(seat);
        }

        vector<ShowSeat> bookingSeats;
        for (auto* seat : selected) {
            seat->bookSeat();
            bookingSeats.push_back(*seat);
        }

        double total = priceCalculator.calculateTotal(bookingSeats);
        Booking booking(show, bookingSeats, total);

        if (payment.pay(total)) {
            booking.confirm();
            cout << "Payment successful. Booking confirmed.\n";
            ticketPrinter.printTicket(booking);
        } else {
            booking.cancel();
            cout << "Payment failed. Seats released.\n";
        }

        return booking;
    }

    void cancelBooking(Booking& booking) {
        if (booking.getStatus() != "CONFIRMED") {
            cout << "Only a CONFIRMED booking can be cancelled.\n";
            return;
        }

        booking.cancel();
        cout << "Booking BK" << booking.getBookingId() << " cancelled. Seats are AVAILABLE again.\n";
    }
};
