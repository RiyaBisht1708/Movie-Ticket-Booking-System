#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Show {
private:
    Movie movie;
    Screen screen;
    string showTime;
    vector<ShowSeat> showSeats;

public:
    Show(Movie m = Movie(), Screen s = Screen(), string t = "")
        : movie(m), screen(s), showTime(t) {
        for (const auto& seat : s.getSeats()) {
            showSeats.emplace_back(seat);
        }
    }

    Movie getMovie() const { return movie; }
    Screen getScreen() const { return screen; }
    string getShowTime() const { return showTime; }

    vector<ShowSeat>& getShowSeats() { return showSeats; }
    const vector<ShowSeat>& getShowSeats() const { return showSeats; }

    ShowSeat* findSeat(const string& n) {
        for (auto& seat : showSeats) {
            if (seat.getSeatNumber() == n) {
                return &seat;
            }
        }
        return nullptr;
    }

    void displaySeats() const {
        cout << "\nSeat Layout:\n";
        for (const auto& seat : showSeats) {
            cout << seat.getSeatNumber() << " - " << seat.getSeatType()
                 << " [" << seat.getStatus() << "]\n";
        }
    }
};
