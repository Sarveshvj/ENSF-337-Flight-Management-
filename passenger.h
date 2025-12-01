#ifndef PASSENGER_H

#define PASSENGER_H

#include <string>
using std::string;


class Passenger{
    private:
    string firstname;

    string lastname;

    string phone;

    string id;

    int row;

    char seat;

    public:
    Passenger();

    Passenger(const string& first, const string& last, string& phone_num, const string& idNum, int rowNumber, char seatLetter);
    /*
    PROMISES: Convert all the spaces in idNum into '-'. Firstname, lastname, id, row, and seat are intilized to
    first, last, idNum, rowNumber, and seatLetter respectively
    */


    string getFirstName() const;
    /*
    PROMISES: Returns firstname
    */

    string getLastName() const;
    /*
    PROMISES: Returns lastname
    */

    string getPhone() const;
    /*
    PROMISES: Returns phone
    */

    string getId()const;
    /*
    PROMISES: id
    */

    int getRow()const;
    /*
    PROMISES: Returns row
    */

    char getSeat()const;
    /*
    PROMISES: Returns seat
    */

    void setFirstName(const string& first);
    /*
    PROMISES: Sets firstname to first
    */

    void setLastName(const string& last);
    /*
    PROMISES:Sets lastname to last
    */

    void setPhone(const string& phone_num);
    /*
    PROMISES: Sets phone to phone_num
    */

    void setId(const string& idNum);
    /*
    PROMISES:sets id to idNum
    */

    void setRow(int r);
    /*
    PROMISES: Sets row to r
    */
    
    void setSeat(char seat_letter);
    /*
    PROMISES: Sets seat to seat_letter
    */
};
#endif