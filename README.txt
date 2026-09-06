MOVIE TICKET BOOKING SYSTEM - SYSTEM DESIGN ASSIGNMENT

Run on Mac/Linux:
  g++ -std=c++17 main.cpp -o movie_booking
  ./movie_booking

Run on Windows:
  g++ -std=c++17 main.cpp -o movie_booking.exe
  .\movie_booking.exe

This project follows the UML class structure discussed in the assignment:
Core: Movie, Seat, Screen, Cinema, Show, ShowSeat, Customer, Booking.
Services: Payment, UpiPayment, CardPayment, CashPayment, PriceCalculator,
TicketPrinter, BookingService.

The source is deliberately modular with one class per .cpp file and no header files.
Payment uses an abstract base class and runtime polymorphism.
The booking flow validates all seats before changing their status.
Cancellation releases the booked seats.
