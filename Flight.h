//Flight.h

#ifndef FLIGHT_H
#define FLIGHT_H

#include <string>
#include <vector>
#include "route.h"
#include "seat.h"
#include "passenger.h"

using namespace std;

class Flight {
private:
    std::string flightID;
    int numRows;
    int seatsPerRow;
    Route route; 
    vector<vector<Seat*>> seats;

public:
    // Ctors
    Flight();
    // PROMISES: Creates an empty Flight object with default values.
    // flightID = empty string, numRows = 0, seatsPerRow = 0,
    // route is default constructed, and seats vector is empty.

    Flight(string& id, int rows, int cols, const Route& r);
    // REQUIRES: rows > 0, cols > 0.
    // PROMISES: Initializes a Flight object using the given
    // id, row count, seat count per row, and route.
    // Allocates a rows x cols 2D vector of Seat* initialized to nullptr.
    
    // Destructor
    ~Flight();
    // PROMISES: Deallocates all dynamically allocated Seat objects stored
    // in the seats 2D vector. Ensures no memory leaks by deleting all Seat*
    // before program termination.
    
    // Getters
    std::string getFlightID() const;
    // PROMISES: Returns the flight ID stored for this flight.

    int getNumRows() const;
    // PROMISES: Returns the number of seat rows in the aircraft.

    int getSeatsPerRow() const;
    // PROMISES: Returns the number of seats per row.

    const Route& getRoute() const;
    // PROMISES: Returns a const reference to the flight's Route object.

    const vector<vector<Seat*>>& getSeats() const;
    // PROMISES: Returns a const reference to the 2D vector storing Seat pointers.
    // Caller must not delete or modify these pointers directly.


    // Setters
    void setFlightID(const string& id);
    // REQUIRES: id is not empty.
    // PROMISES: Updates the flightID with the new value.

    void setNumRows(int rows);
    // REQUIRES: rows > 0.
    // PROMISES: Updates numRows. Does NOT reallocate seats vector.

    void setSeatsPerRow(int cols);
    // REQUIRES: cols > 0.
    // PROMISES: Updates seatsPerRow. Does NOT reallocate seats vector.

    void setRoute(const Route& r);
    // PROMISES: Replaces the current Route with the provided Route object.


    // Helper / other functions
    void addPassengerFromFile(Passenger& p);
    //REQUIRES: A passenger object
    //PROMISES: Checks the validity of the row and seat letter for the passenger
    // If the passenger is valid the seat the passenger would like is initialized on heap
    // and the passenger is then assigned to that seat

    void addPassenger();
    // PROMISES: Prompts user for information about added passenger, along with this it will error check inputs
    // Creates a new passenger on the heap, if the desiered seat is not initialized or taken then passenger is put in that seat
    // If seat is taken then it lets user know that the seat is occupied

    void removePassenger();
    // PROMISES: Prompts user for the id of passenger they would like to remove
    // System then scans through seats vector trying to find id
    // If the ID is found the passenger is deleted and pointer is set to nullptr
    // If passenger ID not found prompt again for a valid ID

    void displaySeatMap() const;
    //PROMISES: Displays the seat map in same template as given to us

    void displayPassengers() const;
    //PROMISES: Displays the passengers in same template as given to us
    // in order of ID of the passengers 

    int seatindex(char col);
    //PROMISES: Makes sure the char is any letter A-F, otherwise return is -1
    //If char is valid will return assigned index value of char
};
#endif
