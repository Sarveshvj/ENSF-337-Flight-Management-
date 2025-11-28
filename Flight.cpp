#include "Flight.h"
#include "seat.cpp"
#include "passenger.cpp"
#include "route.cpp"
#include <iostream>
#include <iomanip>
#ifndef FLIGHT_CPP
#define FLIGHT_CPP
using namespace std;

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
void Flight::addPassenger(){
    int id, row;
    string fname, lname, phone_num;
    char seat;
    cout <<"Please enter the passenger id: ";
    cin >> id;
    cout <<"Please enter the passenger first name: ";
    cin >> fname;
    cout <<"Please enter the passenger last name: ";
    cin >> lname;
    cout <<"Please enter the passenger phone number: ";
    cin >> phone_num;
    cout <<"Enter the passenger's desired row: ";
    cin >> row;
    cout <<"Enter the passenger's desired seat: ";
    cin >> seat;
    Passenger* p = new Passenger(fname, lname, phone_num, id, row, seat);
    
    int row = p->getRow(); //Passenger getter function
    char col = p->getSeat(); //Passenger getter function

    int col_index = seatindex(col);

    Seat*& s = seats.at(row-1).at(col_index);

    if(s == nullptr){
        s = new Seat(row, col);
    }
    if(s->isEmpty()){
        s->setOccupant(p);
    }
    else{
        cout<<"The seat chosen is occupied \n Please re-enter the passenger info. \n"<<endl;
    }
}
void Flight::addPassengerFromFile(Passenger& p){
    int row = p.getRow(); //Passenger getter function
    char col = p.getSeat(); //Passenger getter function

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
void Flight::removePassenger(){
    int pid;
    while(1){
        cout << "Please enter the id of the passenger that needs to be removed:";
        cin >> pid;

        Seat* s;

        for(int i = 0; i < numRows; i++){
            for(int j = 0; j<seatsPerRow; j++){
                s = seats.at(i).at(j);
                if(s == nullptr){
                    cout<<"Internal error: seat not initialized. \n"<<endl;
                    return;
                }
                Passenger* p = s->getOccupant();
                if(s!= nullptr && pid == p->getId()){
                    cout<<"Passenger "<<p->getFirstName()<<" "<<p->getLastName()<<" was successfully removed from flight "<< flightID<<endl;
                    delete p;
                    s->setOccupant(nullptr); // Setter function in passenger
                    return;
                }
            }
        }
        cout<<"Passenger was not found please retry"<<endl;
        continue;
    }
    
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
    cout<<"Passenger List (Flight:"<<flightID<<" from "<<route->getSource()<<" to "<<route->getDestination()<<")\n\n";

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
                Passenger* p = s->getOccupant();

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