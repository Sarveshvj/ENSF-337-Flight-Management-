#ifndef AIRLINE_H
#define AIRLINE_H

#include <vector>
#include <string>
#include <iostream>

#include "Flight.cpp"

class Airline {
private:
    string name;
    vector<Flight*> flights;

public:
	Airline();
    ~Airline();

    void flightsFromfile(const string& filename);
    void passengerFromfile(const string& filename);

    void addFlight(Flight* f);
    Flight* findFlightByIndex(int i);

    const vector<Flight*>& getFlights() const{ return flights; }
	void saveData(const string& filename) const;
    void displayFlights() const;
    Flight* findFlightByID(const string& id);
};

#endif
