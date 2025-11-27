#include "Passenger.h"

Passenger::Passenger(){
    firstname   = " ";

    lastname    = " ";

    phone = " ";
    
    id = 0;

    row = 0;
    
    seat = 0;
}

Passenger::Passenger(const string& first, const string& last, const string& phone_num, int idNum, int rowNumber, char seatLetter){
    firstname = first;

    lastname = last;

    phone = phone_num;

    id = idNum;

    row = rowNumber;

    seat = seatLetter;
}


string Passenger::getFirstName() const {
    return firstname;
}

string Passenger::getLastName() const {
    return lastname;
}
string Passenger::getPhone() const {
    return phone;
}
int Passenger::getId() const{
    return id;
}

int Passenger::getRow() const{
    return row;
}

char Passenger::getSeat() const{
    return seat;
}
void Passenger::setFirstName(const string& first) {
    firstname = first;
}

void Passenger::setLastName(const string& last) {
    lastname = last;
}

void Passenger::setPhone(const string& phone) {
    phone = phone_number;
}
void Passenger::setId(int num){
    id = num;
}

void  Passenger::setRow(int r){
    row = r;
}
    
void Passenger::setSeat(char seat_letter){
    seat = seat_letter;
}