#include <string>
#include <vector>
using namespace std;

class Cinema {
private:
    string name;
    vector<Screen> screens;

public:
    Cinema(string n = "") : name(n) {}

    void addScreen(Screen s) { screens.push_back(s); }
    vector<Screen> getScreen() const { return screens; }
    string getName() const { return name; }
};
