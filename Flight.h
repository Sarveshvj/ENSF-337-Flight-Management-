#ifndef FLIGHT_H
#define FLIGHT_H

#include <string>
#include <vector>
#include "route.h"
#include "seat.h"
#include "passenger.h"

class Flight {
private:
    std::string flightID;
    int numRows;
    int seatsPerRow;
    Route route; 
    std::vector<std::vector<Seat*>> seats;

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
    const std::vector<std::vector<Seat*>>& getSeats() const;

    // Setters
    void setFlightID(const std::string& id);
    void setNumRows(int rows);
    void setSeatsPerRow(int cols);
    void setRoute(const Route& r);

    // Helper / other functions
    void addPassengerFromFile(Passenger& p);
    void addPassenger();
    void removePassenger();
    void displaySeatMap() const;
    void displayPassengers() const;
    int seatindex(char col);
};

#endif // FLIGHT_H
