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
    int id, row;
    string fname, lname, phone_num;
    char seat;
    cout << "Please enter the passenger id: ";
    cin >> id;
    cout << "Please enter the passenger first name: ";
    cin >> fname;
    cout << "Please enter the passenger last name: ";
    cin >> lname;
    cout << "Please enter the passenger phone number: ";
    cin >> phone_num;
    cout << "Enter the passenger's desired row: ";
    cin >> row;
    cout << "Enter the passenger's desired seat: ";
    cin >> seat;

    Passenger* p = new Passenger(fname, lname, phone_num, id, row, seat);

    int col_index = seatindex(seat);

    if (row < 1 || row > numRows || col_index < 0 || col_index >= seatsPerRow) {
        cout << "Invalid row/seat. Row must be between 1 and " << numRows
             << " and seat between A and "
             << char('A' + seatsPerRow - 1) << ".\n";
        delete p;
        return;
    }

    Seat*& s = seats.at(row - 1).at(col_index);

    if (s == nullptr) {
        s = new Seat(row, seat);
    }
    if (s->isEmpty()) {
        s->setOccupant(p);
    } else {
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
    } else {
        cout << "Seat " << row << col
             << " on flight " << flightID
             << " is already occupied. Skipping duplicate from file.\n";
    }
}

void Flight::removePassenger() {
    int pid;
    while (1) {
        cout << "Please enter the id of the passenger that needs to be removed: ";
        cin >> pid;

        Seat* s;

        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < seatsPerRow; j++) {
                s = seats.at(i).at(j);
                if (s == nullptr) {
                    cout << "Internal error: seat not initialized.\n" << endl;
                    return;
                }
                Passenger* p = s->getOccupant();
                if (p != nullptr && pid == p->getId()) {
                    cout << "Passenger " << p->getFirstName() << " " << p->getLastName()
                         << " was successfully removed from flight " << flightID << endl;
                    delete p;
                    s->setOccupant(nullptr);
                    return;
                }
            }
        }
        cout << "Passenger was not found please retry" << endl;
    }
}

void Flight::displaySeatMap() const {
    for (int i = 0; i < numRows; i++) {
        cout << "+---+---+---+---+---+---+ \n" << endl;

        for (int j = 0; j < seatsPerRow; j++) {
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
    cout << "+---+---+---+---+---+---+" << endl;
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

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < seatsPerRow; j++) {
            Seat* s = seats.at(i).at(j);
            if (s && !s->isEmpty()) {
                Passenger* p = s->getOccupant();

                cout << left
                     << setw(12) << p->getFirstName()
                     << setw(12) << p->getLastName()
                     << setw(15) << p->getPhone()
                     << setw(6)  << p->getRow()
                     << setw(6)  << p->getSeat()
                     << setw(8)  << p->getId() << endl;
            }
        }
    }
}

int Flight::seatindex(char col) {
    if (col < 'A' || col > 'F') { return -1; }
    else {
        return col - 'A';
    }
}
