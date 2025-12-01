#include "seat.h"
#include "passenger.h"

Seat::Seat(){
    rowNumber = 0;
    seatChar = ' ';
    occupant = nullptr;

}
Seat::Seat(int row, char seat){
    rowNumber = row;
    seatChar = seat;
    occupant = nullptr;
}

int Seat::getRowNumber () const{
    return rowNumber;
}
char Seat::getSeatLetter() const{
    return seatChar;
}
Passenger* Seat::getOccupant() const{
    return occupant;
}

void Seat::setRowNumber(int row){ 
    rowNumber = row;
}
void Seat::setSeatNumber(char seat){
    seatChar = seat;
}
void Seat::setOccupant(Passenger* p){
    occupant = p;
}

bool Seat::isEmpty() const{
    return occupant == nullptr;
}