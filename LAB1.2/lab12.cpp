#include <iostream>
// FIXME include vector library
#include <vector>
using namespace std;

// parameter order will always be jersey #s then ratings
void outputRoster(const vector<int> &, const vector<int> &);
void addPlayer(vector<int> &, vector<int> &);
void removePlayer(vector<int> &, vector<int> &);
void updatePlayerRating(const vector<int> &, vector<int> &);
void outputPlayersAboveRating(const vector<int> &, const vector<int> &);

void doInitialInput(vector<int> &, vector<int> &);
void mainMenu(vector<int> &, vector<int> &);
void printPlayer(const int, const int, const int);
int indexOfJerseyNum(const vector<int> &); // returns -1 if the jersey number cannot be found

int main() {

   /* Type your code here. */
   vector<int> players;
   vector<int> ratings;
    
    doInitialInput(players, ratings);
    outputRoster(players, ratings);
    mainMenu(players, ratings);

   return 0;
}

void doInitialInput(vector<int> &p, vector<int> &r) {
    for (unsigned i = 0; i < 5; ++i) {
        cout << "Enter player " << i + 1 << "'s jersey number:" << endl;
        int pNum;
        cin >> pNum;
        p.push_back(pNum);
        cout << "Enter player " << i + 1 << "'s rating:" << endl;
        int rNum;
        cin >> rNum;
        r.push_back(rNum);
        cout << endl;
    }
}

void mainMenu(vector<int> &p, vector<int> &r) {
    string arg;
    cout << "MENU" << endl;
    cout << "a - Add player" << endl;
    cout << "d - Remove player" << endl;
    cout << "u - Update player rating" << endl;
    cout << "r - Output players above a rating" << endl;
    cout << "o - Output roster" << endl;
    cout << "q - Quit" << endl << endl;
    cout << "Choose an option:";
    cin >> arg;
    cout << endl;
    
    if (arg == "a") {
        addPlayer(p, r);
        mainMenu(p, r);
    }
    else if (arg == "d") {
        removePlayer(p, r);
        mainMenu(p, r);
    }
    else if (arg == "u") {
        updatePlayerRating(p, r);
        mainMenu(p, r);
    }
    else if (arg == "r") {
        outputPlayersAboveRating(p, r);
        mainMenu(p, r);
    }
    else if (arg == "o") {
        outputRoster(p, r);
        mainMenu(p, r);
    }
    else if (arg == "q") {
        // do nothing!
    }
    else
    {
        cout << "Invalid menu option. Please try again!" << endl << endl;
        mainMenu(p, r);
    }
}

void printPlayer(const int i, const int p, const int r) {
    cout << "Player " << i << " -- Jersey number: " << p << ", Rating: " << r << endl;
}

int indexOfJerseyNum(int jNum, const vector<int> &p) { // returns -1 if the jersey number cannot be found
    for (unsigned i = 0; i < p.size(); ++i) {
        if (jNum == p.at(i))
        {
            return i;
        }
    }
    return -1;
}

void outputRoster(const vector<int> &p, const vector<int> &r) {
    cout << "ROSTER" << endl;
    for (unsigned i = 0; i < p.size(); ++i) {
        printPlayer(i + 1, p.at(i), r.at(i));
    }
    cout << endl;
}

void addPlayer(vector<int> &p, vector<int> &r) {
    cout << "Enter another player's jersey number:" << endl;
    int newP;
    cin >> newP;
    p.push_back(newP);
    cout << "Enter another player's rating:" << endl;
    int newR;
    cin >> newR;
    r.push_back(newR);
    cout << endl;
}

void removePlayer(vector<int> &p, vector<int> &r) {
    cout << "Enter a jersey number:" << endl;
    int jerseyNum;
    cin >> jerseyNum;
    int index = indexOfJerseyNum(jerseyNum, p);
    if (index == -1) {
        cout << "Could not find a player with the jersey number " << jerseyNum << "." << endl;
        cout << "Please try again." << endl;
    }
    else {
        int pOut = p.at(index);
        int rOut = r.at(index);
        p.erase(p.begin() + index);
        r.erase(r.begin() + index);
        cout << "Removed the following player from the roster: " << endl;
        printPlayer(index + 1, pOut, rOut);
    }
    cout << endl;
}

void updatePlayerRating(const vector<int> &p, vector<int> &r) {
    cout << "Enter a jersey number:" << endl;
    int jerseyNum;
    cin >> jerseyNum;
    int index = indexOfJerseyNum(jerseyNum, p);
    if (index == -1) {
        cout << "Could not find a player with the jersey number " << jerseyNum << "." << endl;
        cout << "Please try again." << endl;
    }
    else {
        cout << "Enter a new rating for player:" << endl;
        int newRating;
        cin >> newRating;
        r.at(index) = newRating;
        cout << "Updated the rating for player with jersey number " << jerseyNum << "." << endl;
        cout << "New player information: " << endl;
        printPlayer(index + 1, p.at(index), r.at(index));
    }
    cout << endl;
}

void outputPlayersAboveRating(const vector<int> &p, const vector<int> &r) {
    cout << "Enter a rating:" << endl;
    int rating;
    cin >> rating;
    cout << endl << "ABOVE " << rating << endl;
    for (unsigned i = 0; i < r.size(); ++i) {
        if (r.at(i) > rating) {
            printPlayer(i + 1, p.at(i), r.at(i));
        }
    }
    cout << endl;
}