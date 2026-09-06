#include <vector>
using namespace std;

class Screen {
private:
    int screenNumber;
    vector<Seat> seats;

public:
    Screen(int n = 0) : screenNumber(n) {}

    void addSeat(Seat s) { seats.push_back(s); }
    vector<Seat> getSeats() const { return seats; }
    int getScreenNumber() const { return screenNumber; }
};
