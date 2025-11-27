#include <vector>
#include <string>
#include <iostream>
#include "../function.h"

using std::string;
using std::vector;

#ifndef FLIGHT_H
#define FLIGHT_H

class Flight {
    private:
    string flightID;
    int numRows;
    int seatsPerRow;
    Route* route;
    vector<vector<Seat*>> seats;
    
    // Ctor
    Flight(string& id, int rows, int cols, Route* r);
    
    //Getters
    string getFlightID() const;
    int getNumRows() const;
    int getSeatsPerRow() const;
    Route* getRoute() const;
    const vector<vector<Seat*>>& getSeats() const;

    //Setters
    void setFlightID(const string& id);
    void setNumRows(int rows);
    void setSeatsPerRow(int cols);
    void setRoute(Route* r);

    //Helper
    bool seatAvailable(int row, char col) const;
    void addPassenger(Passenger& p);
    void removePassenger(int id);
    void displaySeatMap() const;
    void displayPassengers() const;
};
#endif