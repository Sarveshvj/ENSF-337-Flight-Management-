#include "Flight.h"
#include <iostream>
#include <iomanip>
#ifndef FLIGHT_CPP
#define FLIGHT_CPP
using std::cout;
using std::endl;
using std::left;
using std::setw;

//Ctors
Flight::Flight()
: flightID(""), numRows(0), seatsPerRow(0), route(nullptr)
{
}
Flight::Flight(string& id, int rows, int cols, Route* r)
: flightID(id), numRows(rows), seatsPerRow(cols), route(r)
{
    seats.resize(numRows);

    for (int i = 0; i < numRows; ++i) {
        seats[i].resize(seatsPerRow);
        for (int j = 0; j < seatsPerRow; ++j) {
            seats[i][j] = nullptr;
        }
    }
}

//Destructor
Flight::~Flight() {
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < seatsPerRow; ++j) {
            delete seats[i][j];
            seats[i][j] = nullptr;
        }
    }
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
void Flight::addPassenger(Passenger& p){
    int row = p.getRow(); //Passenger getter function
    char col = p.getCol(); //Passenger getter function

    int col_index = seatindex(col);

    Seat*& s = seats.at(row-1).at(col_index);

    if(s == nullptr){
        s = new Seat(row, col);
    }
    if(s->isEmpty()){
        s->setOccupant(&p);
    }
    else{
        cout<<"The seat chosen is occupied \n Please re-enter the passenger info. \n"<<endl;
    }
}

void Flight::removePassenger(int row, char col){
    if(row < 1 || row > numRows){
        cout<<"Row entered is invalid, please try again. \n"<<endl;
        return;
    }

    int col_index = seatindex(col);
    if (col_index < 0 || col_index >= seatsPerRow) {
    cout<<"The seat letter you have chosen is invalid, please enter a valid seat.\n"<<endl;
    return;
    }

    Seat* s = seats.at(row-1).at(col_index);

    if(s == nullptr){
        cout<<"Internal error: seat not initialized. \n"<<endl;
        return;
    }

    if(s->isEmpty()){
        cout<<"There is no passenger in the seat. \n"<<endl;
        return;
    }

    s->setOccupant(nullptr); // Setter function in passenger

}

void Flight::displaySeatMap() const {
    for(int i = 0; i<numRows; i++){
        cout<<"+---+---+---+---+---+---+ \n"<<endl;

        for(int j = 0; j<seatsPerRow; j++){
            Seat* s = seats.at(i).at(j);
            cout<<"| ";
            if(s && !s->isEmpty()){
                cout<<"X";
            }
            else{
                cout<<" ";
            }
            cout<<" ";
        }
        cout<<"|\n";
    }
    cout<<"+---+---+---+---+---+---+"<<endl;
    cout << "<<< Press Return to Continue>>>" << endl;
}

void Flight::displayPassengers() const {
    cout<<"Passenger List (Flight:"<<flightID<<" from "<<route->getSource()<<" to "<<route->getDest()<<")\n\n";

    cout<<left
        <<setw(12) <<"First Name"
        <<setw(12) <<"Last Name"
        <<setw(12) <<"Phone"
        <<setw(6) <<"Row"
        <<setw(6) <<"Seat"
        <<setw(8) <<"ID"<<endl;
    
    cout<<"--------------------------------------------------------------\n";

    for(int i = 0; i<numRows; i++){
        for(int j = 0; j<seatsPerRow; j++){
            Seat* s = seats.at(i).at(j);
            if(s && !s->isEmpty()){
                Passenger* p = s->getPassenger();

                cout << left
                     << setw(12) << p->getFirstName() //passenger getter
                     << setw(12) << p->getLastName() //passenger getter
                     << setw(15) << p->getPhone() //passenger getter
                     << setw(6)  << p->getRow() //passenger getter
                     << setw(6)  << p->getSeat() //passenger getter
                     << setw(8)  << p->getId()<< endl; //passenger getter
            }
        }
    }
    cout<<"<<<Press Return to Continue>>>"<<endl;

}

int Flight::seatindex(char col){
    if(col < 'A' || col > 'F'){return -1;}
    else{
        return col- 'A';
    }
}

#endif