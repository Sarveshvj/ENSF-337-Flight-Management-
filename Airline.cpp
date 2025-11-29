#include "Airline.h"
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

Airline::Airline()
    : name("Westjet") {}

Airline::~Airline() {
    for (int i = 0; i < flights.size(); i++) {
        delete flights[i];
    }
}

void Airline::addFlight(Flight* flight) {
    flights.push_back(flight);
}

Flight* Airline::findFlightByID(const string& id) {
    for (int i = 0; i < flights.size(); i++) {
        Flight* f = flights[i];
        if (f->getFlightID() == id)
            return f;
    }
    return nullptr;
}

Flight* Airline::findFlightByIndex(int i) {
    if (i > flights.size() || i < 1) {
        cout << "Invalid Flight chosen please enter a valid choice" << endl;
        return nullptr;
    } else {
        return flights.at(i - 1);
    }
}

void Airline::flightsFromfile(const string& filename) {
    ifstream fin(filename);

    if (!fin) {
        cout << "ERROR: Cannot open flights file: " << filename << endl;
        return;
    }

    string id, from, to;
    int rows, seats_per_row;

    while (fin >> id >> from >> to >> rows >> seats_per_row) {
        Route route(from, to);

        Flight* f = new Flight(id, rows, seats_per_row, route);

        addFlight(f);
    }
}

void Airline::passengerFromfile(const string& filename) {
    ifstream fin(filename);

    if (!fin) {
        cout << "ERROR: Cannot open passengers file: " << filename << endl;
        return;
    }

    string flightID;
    string first, last, phone, seatCode;
    int id;

    while (fin >> flightID >> first >> last >> phone >> seatCode >> id) {

        Flight* f = findFlightByID(flightID);
        if (!f) {
            continue;
        }

        int length = seatCode.size();
        char seatLetter = seatCode[length - 1];
        int row = stoi(seatCode.substr(0, length - 1));

        Passenger newP(first, last, phone, id, row, seatLetter);

        f->addPassengerFromFile(newP);
    }
}

void Airline::displayFlights() const {
    cout << "\nHere is a list of available flights.Please select one:\n";

    if (flights.empty()) {
        cout << "No flights loaded.\n";
        return;
    }

    for (int i = 0; i < flights.size(); i++) {
        if (!flights[i]) continue;

        const Route& r = flights[i]->getRoute();

        cout << (i + 1) << "." << left
             << setw(12) << flights[i]->getFlightID()
             << setw(12) << r.getSource()
             << setw(12) << r.getDestination()
             << setw(8)  << flights[i]->getNumRows()
             << setw(8)  << flights[i]->getSeatsPerRow()
             << endl;
    }
}

void Airline::saveData(const string& filename) const {
    ofstream fout(filename);

    if (!fout) {
        cout << "ERROR: Could not open file for saving: " << filename << endl;
        return;
    }

    for (int i = 0; i < flights.size(); i++) {

        Flight* f = flights[i];
        const vector<vector<Seat*>>& seatMap = f->getSeats();

        for (int r = 0; r < f->getNumRows(); r++) {
            for (int c = 0; c < f->getSeatsPerRow(); c++) {
                Seat* s = seatMap[r][c];
                if (s && !s->isEmpty()) {
                    Passenger* p = s->getOccupant();
                    fout << f->getFlightID() << " "
                         << p->getFirstName() << " "
                         << p->getLastName() << " "
                         << p->getPhone() << " "
                         << p->getRow() << p->getSeat() << " "
                         << p->getId() << "\n";
                }
            }
        }
    }
    cout << "\nAll the data in the passenger list were saved.\n";
}
