#ifndef SEAT_H

#define SEAT_H


class Passenger;

class Seat {
    private:
    int rowNumber;

    char seatChar;

    Passenger* occupant;

    public:
    
    Seat();

    Seat(int row, char seat);

    int getRowNumber () const;

    char getSeatLetter () const;

    Passenger* getOccupant() const;


    void setRowNumber(int row);

    void setSeatNumber(char seat);

    void setOccupant(Passenger* p);

    
    void removeOccupant();


    bool isEmpty() const;

}; 
#endif