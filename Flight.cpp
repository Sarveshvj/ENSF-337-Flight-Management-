#include "Flight.h"
#include "route.h"
#include "seat.h"

#include <iostream>
#include <iomanip>

using namespace std;

// Ctors
Flight::Flight()
    : flightID(""), numRows(0), seatsPerRow(0), route(Route("", "")) {
}

Flight::Flight(string& id, int rows, int cols, const Route& r)
    : flightID(id), numRows(rows), seatsPerRow(cols), route(r) {

    seats.resize(numRows);

    for (int i = 0; i < numRows; ++i) {
        seats[i].resize(seatsPerRow);
        for (int j = 0; j < seatsPerRow; ++j) {
            seats[i][j] = nullptr;
        }
    }
}

// Destructor
Flight::~Flight() {
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < seatsPerRow; ++j) {
            delete seats[i][j];
            seats[i][j] = nullptr;
        }
    }
}

// Getters
string Flight::getFlightID() const {
    return flightID;
}

int Flight::getNumRows() const {
    return numRows;
}

int Flight::getSeatsPerRow() const {
    return seatsPerRow;
}

const Route& Flight::getRoute() const {
    return route;
}

const vector<vector<Seat*>>& Flight::getSeats() const {
    return seats;
}

// Setters
void Flight::setFlightID(const string& id) {
    flightID = id;
}

void Flight::setNumRows(int rows) {
    numRows = rows;
}

void Flight::setSeatsPerRow(int cols) {
    seatsPerRow = cols;
}

void Flight::setRoute(const Route& r) {
    route = r;
}

// Helper Functions
void Flight::addPassenger() {
    int row;
    string fname, lname, phone_num, id;
    char seat;
    while(1){
        cout << "Please enter the passenger id: ";
        cin >> id;
        if(id.size() != 5){
            cout<<"Please enter a valid 5 character id\n";
            cin.clear();
            cin.ignore(100, '\n');
            continue;
        }
        cout << "Please enter the passenger first name: ";
        cin >> fname;
        if(fname.at(0) == ' '){
            cout<<"Please enter a valid first name\n";
            cin.clear();
            cin.ignore(100, '\n');
            continue;
        }
        cout << "Please enter the passenger last name: ";
        cin >> lname;
        if(lname.at(0) == ' '){
            cout<<"Please enter a valid last name\n";
            cin.clear();
            cin.ignore(100, '\n');
            continue;
        }
        cout << "Please enter the passenger phone number: ";
        cin.ignore(100, '\n');
        getline(cin, phone_num);
        bool phoneValid =
            phone_num.size() == 12 &&
            isdigit(phone_num[0]) && isdigit(phone_num[1]) && isdigit(phone_num[2]) &&
            phone_num[3] == ' ' &&
            isdigit(phone_num[4]) && isdigit(phone_num[5]) && isdigit(phone_num[6]) &&
            phone_num[7] == ' ' &&
            isdigit(phone_num[8]) && isdigit(phone_num[9]) &&
            isdigit(phone_num[10]) && isdigit(phone_num[11]);

        if (!phoneValid) {
            cout << "Please enter a valid phone number, in format (123 456 7890)\n";
            cin.clear();
            cin.ignore(100, '\n');
            continue;
        }
        cout << "Enter the passenger's desired row: ";
        cin >> row;
        cout << "Enter the passenger's desired seat: ";
        cin >> seat;
        break;
    }
    Passenger* p = new Passenger(fname, lname, phone_num, id, row, seat);

    int col_index = seatindex(seat);

    if (row < 1 || row > numRows || col_index < 0 || col_index >= seatsPerRow) {
        cout << "Invalid row/seat. Row must be between 1 and " << numRows
             << " and seat between A and "
             << char('A' + seatsPerRow - 1) << ".\n";
        cin.clear();
        cin.ignore(100, '\n');
        delete p;
        return;
    }

    Seat*& s = seats.at(row - 1).at(col_index);

    if (s == nullptr) {
        s = new Seat(row, seat);
    }
    if (s->isEmpty()) {
        s->setOccupant(p);
    } 
    else {
        cout << "The seat chosen is occupied \nPlease re-enter the passenger info.\n" << endl;
        delete p;
    }
}

void Flight::addPassengerFromFile(Passenger& p) {
    int row = p.getRow();
    char col = p.getSeat();

    int col_index = seatindex(col);

    if (row < 1 || row > numRows || col_index < 0 || col_index >= seatsPerRow) {
        cout << "Invalid seat " << row << col
             << " for flight " << flightID
             << " in passengers file. Skipping this passenger.\n";
        return;
    }

    Seat*& s = seats.at(row - 1).at(col_index);

    if (s == nullptr) {
        s = new Seat(row, col);
    }

    if (s->isEmpty()) {
        Passenger* newP = new Passenger(p); 
        s->setOccupant(newP);
    }
}

void Flight::removePassenger() {
    string pid;
    while (1) {
        cout << "Please enter the id of the passenger that needs to be removed: ";
        cin >> pid;

        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < seatsPerRow; j++) {

                Seat* s = seats.at(i).at(j);

                if (s != nullptr) {
                    Passenger* p = s->getOccupant();
                    if (p != nullptr && pid == p->getId()) {

                        cout << "Passenger " << p->getFirstName() << " "
                             << p->getLastName()
                             << " was successfully removed from flight "
                             << flightID << endl;

                        delete p;
                        s->setOccupant(nullptr);
                        return;
                    }
                }
            }
        }
        cout << "Passenger was not found please retry" << endl;
        cin.clear();
        cin.ignore(100, '\n');
    }
}


void Flight::displaySeatMap() const {
    cout << "\nSeat map for flight " << flightID << "\n\n";

    cout << "     ";
    for (int j = 0; j < seatsPerRow; ++j) {
        char seatLetter = 'A' + j;
        cout << "  " << seatLetter << " ";
    }
    cout << '\n';

    for (int i = 0; i < numRows; ++i) {
        cout << "    ";
        for (int j = 0; j < seatsPerRow; ++j) {
            cout << "+---";
        }
        cout << "+\n";
        if (i + 1 < 10)
            cout << "  " << (i + 1) << " ";   
        else
            cout << " " << (i + 1) << " ";    

        for (int j = 0; j < seatsPerRow; ++j) {
            Seat* s = seats.at(i).at(j);
            cout << "| ";
            if (s && !s->isEmpty()) {
                cout << "X";
            } else {
                cout << " ";
            }
            cout << " ";
        }
        cout << "|\n";
    }

    cout << "    ";
    for (int j = 0; j < seatsPerRow; ++j) {
        cout << "+---";
    }
    cout << "+\n";

    cout << "\nX = occupied seat\n";
}

void Flight::displayPassengers() const {
    cout << "Passenger List (Flight:" << flightID
         << " from " << route.getSource()
         << " to " << route.getDestination() << ")\n\n";

    cout << left
         << setw(12) << "First Name"
         << setw(12) << "Last Name"
         << setw(12) << "Phone"
         << setw(6)  << "Row"
         << setw(6)  << "Seat"
         << setw(8)  << "ID" << endl;

    cout << "--------------------------------------------------------------\n";

    vector<Passenger*> plist;

    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < seatsPerRow; ++j) {
            Seat* s = seats.at(i).at(j);
            if (s && !s->isEmpty()) {
                plist.push_back(s->getOccupant());
            }
        }
    }

    size_t n = plist.size();

    if (n >= 2) {
        for (size_t i = 0; i < n - 1; ++i) {
            size_t minIndex = i;
            for (size_t j = i + 1; j < n; ++j) {
                if (plist[j]->getId() < plist[minIndex]->getId()) {
                    minIndex = j;
                }
            }

            if (minIndex != i) {
                Passenger* tmp = plist[i];
                plist[i] = plist[minIndex];
                plist[minIndex] = tmp;
            }
        }
    }

    for (size_t k = 0; k < n; ++k) {
        Passenger* p = plist[k];

        cout << left
             << setw(12) << p->getFirstName()
             << setw(12) << p->getLastName()
             << setw(15) << p->getPhone()
             << setw(6)  << p->getRow()
             << setw(6)  << p->getSeat()
             << setw(8)  << p->getId() << endl;
        
        cout << "--------------------------------------------------------------\n";
    }
}


int Flight::seatindex(char col) {
    if (col < 'A' || col > 'F') { return -1; }
    else {
        return col - 'A';
    }
}
