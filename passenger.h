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

    Passenger(const string& first, const string& last, const string& phone_num, const string& idNum, int rowNumber, char seatLetter);

    string getFirstName() const;

    string getLastName() const;

    string getPhone() const;

    string getId()const;

    int getRow()const;

    char getSeat()const;

    void setFirstName(const string& first);

    void setLastName(const string& last);

    void setPhone(const string& phone_num);

    void setId(const string& num);

    void setRow(int r);
    
    void setSeat(char seat_letter);
};
#endif