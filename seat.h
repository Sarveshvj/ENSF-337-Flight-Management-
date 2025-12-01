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
    /*
    PROMISES: Creates an object and sets RowNumber to row and seatChar to seat
    */

    int getRowNumber () const;
    /*
    PROMISES: Returns rowNumber
    */

    char getSeatLetter () const;
    /*
    PROMISES: Returns seatCHar
    */
    

    Passenger* getOccupant() const;
    /*
    PROMISES: Returns Occupant
    */

    void setRowNumber(int row);
    /*
    PROMISES: Sets rowNumber to row
    */

    void setSeatNumber(char seat);
    /*
    PROMISES: Sets seatChar to seat
    */

    void setOccupant(Passenger* p);
    /*
    PROMISES: Sets Occupant to P
    */

<<<<<<< HEAD
    

    bool isEmpty() const;
    /*
    PROMISES: Returns True if Occupant is a null ptr, otherweise returns false 
    */
=======
    void removeOccupant();

    bool isEmpty() const;
    /* PROMISIES: Will return True if occupant points to nothing, otherwise returns False*/
>>>>>>> 77c5bf01d2baca6cd5935cd63aefe5320151a214

}; 
#endif