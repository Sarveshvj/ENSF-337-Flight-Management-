#include <vector>
#include <string>
#include <iostream>

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

    public:   
    // Ctors
    Flight();
    Flight(string& id, int rows, int cols, Route* r);

    //Destructor
    ~Flight();
    
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
    void addPassengerFromFile(Passenger& p);
    void addPassenger();
    void removePassenger();
    void displaySeatMap() const;
    void displayPassengers() const;
    int seatindex(char col);
};
#endif