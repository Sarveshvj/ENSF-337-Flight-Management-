#include "Flight.h"

#ifndef FLIGHT_CPP
//Ctor

Flight::Flight(string& id, int rows, int cols, Route* r)
: flightID(id), numRows(rows), seatsPerRow(cols), route(r)
{
}

//Getters
string Flight::getFlightID() const {
    return flightID;
}

int Flight::getNumRows() const {
    return numRows;
}

int Flight::getSeatsPerRow() const {
    return seatsPerRow;
}

Route* Flight::getRoute() const {
    return route;
}

const vector<vector<Seat*>>& Flight::getSeats() const {
    return seats;
}

//Setters
void Flight::setFlightID(const string& id) {
    flightID = id;
}

void Flight::setNumRows(int rows) {
    numRows = rows;
}

void Flight::setSeatsPerRow(int cols) {
    seatsPerRow = cols;
}

void Flight::setRoute(Route* r) {
    route = r;
}
#endif