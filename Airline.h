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
    ~Airline();

    void flightsFromfile(const string& filename);
    // REQUIRES:
    //        it requires a valid text filename 
    //        contains the information about filghts
    // PROMISES:
    //        it loads filghts from the text file into the vector flights
    void passengerFromfile(const string& filename);
    // REQUIRES:
    //        it requires a valid text filename 
    //        contains the information about passengers 
    // PROMISES:
    //        it loads passengers from the text file into the corresponding 
    //        dynamically allocated passenger class 
    
    void addFlight(Flight* f);
    // REQUIRES:
    //        it requires a valid flight name and valide routes
    // PROMISES:
    //        it pushes the flight pointer into the vector flights
    Flight* findFlight(const string& id);
    // PROMISES:
    //        by flight_id it finds the flight in the vector flights

    const vector<Flight*>& getFlights() const;
    // PROMISES:
    //        it returns the vector of flight pointers 

    void displayfilghts() const; 
    // PROMISES:
    //        it shows a information about filghts
};

#endif
