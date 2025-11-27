#include "Flight.h"
#include <iostream>
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

//Helper Functions
bool Flight::seatAvailable(int row, char col) const{
    if(col>= 'A' || col<= 'F'){
        int col_index = seatindex(col); // Helper function that will be implemented under seat class
        Seat* s = seats.at(row-1).at(col_index);
        return s->isEmpty();
    }
    else{
        std::cout<<"The seat letter you have chosen is invalid, please enter a valid seat.\n"<<std::endl;
        return false;
    }
}

void Flight::addPassenger(Passenger& p){
    int row = p.getRow(); //Passenger getter function
    char col = p.getCol(); //Passenger getter function

    int col_index = seatindex(col); // Helper function that will be implemented under seat class

    Seat* s = seats.at(row-1).at(col_index);

    if(s->isEmpty()){
        s->setoccupant(&p); // Seat setter function
    }
    else{
        std::cout<<"The seat chosen is occupied \n Please re-enter the passenger info. \n"<<std::endl;
    }
}

void Flight::removePassenger(int row, char col){
    if(row < 1 || row > numRows){
        std::cout<<"Row entered is invalid, please try again. \n"<<std::endl;
    }
    if(col < 'A' || col > 'F'){
        std::cout<<"The seat letter you have chosen is invalid, please enter a valid seat.\n"<<std::endl;
    }

    int col_index = seatindex(col); // Helper function that will be implemented under seat class

    Seat* s = seats.at(row-1).at(col_index);   

    delete s;
    s == nullptr;
}

#endif