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
    Flight(std::string& id, int rows, int cols, const Route& r);

    // Destructor
    ~Flight();
    
    // Getters
    std::string getFlightID() const;
    int getNumRows() const;
    int getSeatsPerRow() const;
    const Route& getRoute() const;
    const vector<vector<Seat*>>& getSeats() const;

    // Setters
    void setFlightID(const string& id);
    void setNumRows(int rows);
    void setSeatsPerRow(int cols);
    void setRoute(const Route& r);

    // Helper / other functions

    //REQUIRES: A passenger object
    //PROMISES: Checks the validity of the row and seat letter for the passenger
    // If the passenger is valid the seat the passenger would like is initialized on heap
    // and the passenger is then assigned to that seat
    void addPassengerFromFile(Passenger& p);

    // PROMISES: Prompts user for information about added passenger, along with this it will error check inputs
    // Creates a new passenger on the heap, if the desiered seat is not initialized or taken then passenger is put in that seat
    // If seat is taken then it lets user know that the seat is occupied
    void addPassenger();

    // PROMISES: Prompts user for the id of passenger they would like to remove
    // System then scans through seats vector trying to find id
    // If the ID is found the passenger is deleted and pointer is set to nullptr
    // If passenger ID not found prompt again for a valid ID
    void removePassenger();

    //PROMISES: Displays the seat map in same template as given to us
    void displaySeatMap() const;

    //PROMISES: Displays the passengers in same template as given to us
    // in order of ID of the passengers 
    void displayPassengers() const;
    
    //PROMISES: Makes sure the char is any letter A-F, otherwise return is -1
    //If char is valid will return assigned index value of char
    int seatindex(char col);
};

#endif
