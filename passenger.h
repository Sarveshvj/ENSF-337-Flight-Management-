#ifndef PASSENGER_H

#define PASSENGER_H

#include <string>
using std::string;


class Passenger{
    private:
    string firstname;

    string lastname;

    string phone;

    int id;

    int row;

    char seat;

    public:
    Passenger();

    Passenger(const string& first, const string& last, const string& phone_num, int idNum, int rowNumber, char seatLetter);

    string getFirstName() const;

    string getLastName() const;

    string getPhone() const;

    int getId()const;

    int getRow()const;

    char getSeat()const;

    void setFirstName(const string& first);

    void setLastName(const string& last);

    void setPhone(const string& phone_num);

    void setId(int num);

    void setRow(int r);
    
    void setSeat(char seat_letter);
};
#endif