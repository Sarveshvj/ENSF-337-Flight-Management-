//passenger.cpp

#include "Passenger.h"

Passenger::Passenger(){
    firstname   = " ";

    lastname    = " ";

    phone = " ";
    
    id = "";

    row = 0;
    
    seat = 0;
}

Passenger::Passenger(const string& first, const string& last, string& phone_num, const string& idNum, int rowNumber, char seatLetter){
    firstname = first;

    lastname = last;

    for(int i = 0; i < phone_num.size(); i++){
        if(phone_num.at(i) == ' '){
            phone_num.at(i) = '-';
        }
    }
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
string Passenger::getId() const{
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

void Passenger::setPhone(const string& phone_num) {
    phone = phone_num;
}
void Passenger::setId(const string& idNum){
    id = idNum;
}

void  Passenger::setRow(int r){
    row = r;
}
    
void Passenger::setSeat(char seat_letter){
    seat = seat_letter;
}