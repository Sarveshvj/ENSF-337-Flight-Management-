#ifndef AIRLINE_H
#define AIRLINE_H

#include <vector>
#include <string>
#include <iostream>

#include "Flight.h"

class Airline {
private:
    std::string name;
    std::vector<Flight*> flights;

public:
    Airline();
    ~Airline();

    void flightsFromfile(const std::string& filename);
    void passengerFromfile(const std::string& filename);

    void addFlight(Flight* f);
    Flight* findFlightByIndex(int i);

    const std::vector<Flight*>& getFlights() const { return flights; }

    void saveData(const std::string& filename) const;
    void displayFlights() const;
    Flight* findFlightByID(const std::string& id);
};

#endif
