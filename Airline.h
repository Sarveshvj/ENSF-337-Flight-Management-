//Airline.h

#ifndef AIRLINE_H
#define AIRLINE_H

#include <vector>
#include <string>
#include <iostream>

#include "Flight.h"

class Airline {
private:
    string name;
    vector<Flight*> flights;

public:
    Airline();
    // PROMISES:
    //        Creates an Airline object with the default name.
    //        Starts with an empty list of flights.
    ~Airline();
    // PROMISES:
    //        Deletes all Flight objects stored in the flights vector.

    void flightsFromfile(const string& filename);
    // REQUIRES:
    //        it requires a valid text filename 
    //        contains the information about filghts
    // PROMISES:
    //        Dynamically allocates Flight objects for each record.
    //        Stores the Flight* objects into the 'flights' vector.
    //        If the file cannot be opened, prints an error and does nothing.
    void passengerFromfile(const string& filename);
    // REQUIRES:
    //        it requires a valid text filename 
    //        contains the information about passengers 
    // PROMISES:
    //        Reads each passenger record from the file.
    //        Adds the passenger to the correct flight based on FlightID.
    //        Ignores passengers whose FlightID does not match any flight.
    //        Prints an error message if the file cannot be opened.

    void addFlight(Flight* f);
    // REQUIRES:
    //        it requires a valid flight name and valide routes
    // PROMISES:
    //        Stores the pointer in the 'flights' vector.
    //        Airline destructor will delete the flight later.
    Flight* findFlightByIndex(int i);
    // PROMISES:
    //        Returns the pointer to the corresponding flight.
    //        If invalid, prints an error and returns nullptr.


    const vector<Flight*>& getFlights() const { return flights; }
    // PROMISES:
    //        Returns a constant reference to the vector of Flight pointer.
    //        Can read the list of flights but cannot modify it. 

    void saveData(const string& filename) const;
    // REQUIRES:
    //        filename is a valid path for writing data.
    // PROMISES:
    //        Iterates through every flight and every seat.
    //        Writes out all occupied seats to the specified file.
    //        Prints a success message when done.
    //        If file cannot be opened, prints an error and does nothing.
    void displayFlights() const;
    // PROMISES:
    //        it shows a information about filghts
    //        If no flights exist, prints a message.
    Flight* findFlightByID(const string& id);
    // REQUIRES:
    //        id must be a valid string.
    // PROMISES:
    //        Returns pointer to matching flight if found.
    //        Returns nullptr if no such flight exists.
};

#endif
