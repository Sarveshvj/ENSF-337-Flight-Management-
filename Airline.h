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
	void displayfilghts() const;

public:
	Airline();
    ~Airline();

    void flightsFromfile(const string& filename);
    void passengerFromfile(const string& filename);

    void addFlight(Flight* f);
    Flight* findFlight(const string& id);

    const vector<Flight*>& getFlights() const{ return flights; }
	void saveData(const string& filename) const;
};

#endif
