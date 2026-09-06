#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;
#include "01_Movie.cpp"
#include "02_Seat.cpp"
#include "03_Screen.cpp"
#include "04_Cinema.cpp"
#include "05_ShowSeat.cpp"
#include "06_Show.cpp"
#include "07_Customer.cpp"
#include "08_Booking.cpp"
#include "09_Payment.cpp"
#include "10_UpiPayment.cpp"
#include "11_CardPayment.cpp"
#include "12_CashPayment.cpp"
#include "13_PriceCalculator.cpp"
#include "14_TicketPrinter.cpp"
#include "15_BookingService.cpp"

void listMovies(const vector<Movie>& m){
    cout<<"\n--- Movies ---\n";
    for(size_t i=0;i<m.size();++i)
    {
        cout<<i+1<<". "<<m[i].getTitle()<<" | "<<m[i].getLanguage()<<" | "<<m[i].getDuration()<<" min\n";
    }
}
void listShows(const vector<Show>& s){
    cout<<"\n--- Shows ---\n";
    for(size_t i=0;i<s.size();++i)
    {
        cout<<i+1<<". Screen "<<s[i].getScreen().getScreenNumber()<<" | "<<s[i].getShowTime()<<" | "<<s[i].getMovie().getTitle()<<"\n";
    }
}
int main(){
    Cinema cinema("City Cinema");
    Screen s1(1),s2(2);
    for(auto x:vector<pair<string,string>>{{"A1","SILVER"},{"A2","SILVER"},{"B1","GOLD"},{"B2","GOLD"},{"C1","PLATINUM"},{"C2","PLATINUM"}}){
        s1.addSeat(Seat(x.first,x.second));
        s2.addSeat(Seat(x.first,x.second));
    }
    cinema.addScreen(s1);
    cinema.addScreen(s2);
    Movie m1("3 Idiots","Hindi",170),m2("Inception","English",148),m3("Dangal","Hindi",161);
    vector<Show> shows{{m1,s1,"06:00 PM"},{m1,s1,"09:00 PM"},{m2,s2,"07:00 PM"},{m3,s2,"10:00 PM"}};
    Customer customer("Riya","9876543210");
    BookingService service;
    vector<Booking> bookings;
    while(true){
        cout<<"\n========================================\nMOVIE TICKET BOOKING SYSTEM\n========================================\n1. List Movies\n2. Display Shows and Seats\n3. Book Ticket and Make Payment\n4. Cancel Booking\n5. Display All Bookings\n0. Exit\nEnter choice: ";
        int c;
        if(!(cin>>c)){
            cin.clear();
            string bad;
            cin>>bad;
            cout<<"Invalid input.\n";
            continue;
        }
        if(c==0)
            break;
        if(c==1){
            listMovies({m1,m2,m3});
        }
        else if(c==2){
            listShows(shows);
            int x;
            cout<<"Select show: ";
            cin>>x;
            if(x<1||x>(int)shows.size()){
                cout<<"Invalid show choice.\n";
                continue;
            }
            shows[x-1].displaySeats();
        }
        else if(c==3){
            listShows(shows);
            int x;
            cout<<"Select show: ";
            cin>>x;
            if(x<1||x>(int)shows.size()){
                cout<<"Invalid show choice.\n";
                continue;
            }
            Show& show=shows[x-1];
            show.displaySeats();
            int n;
            cout<<"How many seats? ";
            cin>>n;
            if(n<=0){
                cout<<"Invalid number of seats.\n";
                continue;
            }
            vector<string> seats;
            for(int i=0;i<n;++i){
                string q;
                cout<<"Enter seat "<<i+1<<": ";
                cin>>q;
                seats.push_back(q);
            }
            cout<<"1. UPI\n2. Card\n3. Cash\nChoose payment: ";
            int p;
            cin>>p;
            Payment* pay=nullptr;
            if(p==1)
                pay=new UpiPayment();
            else if(p==2)
                pay=new CardPayment();
            else if(p==3)
                pay=new CashPayment();
            else{
                cout<<"Invalid payment method.\n";
                continue;
            }
            bookings.push_back(service.bookTicket(customer,show,seats,*pay));
            delete pay;
            show.displaySeats();
        }
        else if(c==4){
            if(bookings.empty()){
                cout<<"No bookings.\n";
                continue;
            }
            cout<<"\n--- Bookings ---\n";
            for(size_t i=0;i<bookings.size();++i){
                cout<<i+1<<". Booking BK"<<bookings[i].getBookingId()<<" | "<<bookings[i].getShow().getMovie().getTitle()<<" | "<<bookings[i].getShow().getShowTime()<<" | "<<bookings[i].getStatus()<<"\n";
            }
            int b;
            cout<<"Select booking to cancel: ";
            cin>>b;
            if(b<1||b>(int)bookings.size()){
                cout<<"Invalid booking choice.\n";
                continue;
            }
            service.cancelBooking(bookings[b-1]);
        }
        else if(c==5){
            if(bookings.empty()){
                cout<<"No bookings.\n";
                continue;
            }
            cout<<"\n--- Bookings ---\n";
            for(size_t i=0;i<bookings.size();++i){
                cout<<i+1<<". Booking BK"<<bookings[i].getBookingId()<<" | "<<bookings[i].getShow().getMovie().getTitle()<<" | "<<bookings[i].getShow().getShowTime()<<" | "<<bookings[i].getStatus()<<"\n";
            }
        }
        else{
            cout<<"Invalid choice.\n";
        }
    }
    cout<<"Exiting...\n";
    return 0;
}