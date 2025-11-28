#include <vector>
#include <string>
using std::string;
using std::vector;

class Passenger{
    private:
    string firstname;
    string lastname;
    string phone;
    int id;
    int row;
    char seat;

    public:
    // Getters Setters Ctors
};

class Seat {
    private:
    int rowNumber;
    char seatChar;
    Passenger* occupant;

    public:
    // Getters Setters Ctors
    bool isEmpty() const {return occupant == nullptr;}
    void assignPassenger(Passenger* p) {occupant = p;}
    void removePassenger(Passenger* p) {occupant = nullptr;}
};

class Route {
    private:
    string source;
    string dest;

    public:
    // Getters Setters Ctors
};

class Flight {
    private:
    string flightID;
    int numRows;
    int seatsPerRow;
    Route* route;
    vector<vector<Seat*>> seats;
    
    public:
    bool seatAvailable(int row, char col);
    void addPassenger(Passenger& p);
    void removePassenger(int row, char col);
    void displaySeatMap() const;
    void displayPassengers() const;
    int seatindex(char col);
};

class Airline {
    private:
    string name;
    vector<Flight*> flights;
    void displayfilghts() const;

    public:
    // Getters Setters Ctors
    void flightsFromfile(const string& filename);
    void passengerFromfile(const string& filename);
    Flight* findFlight(string& id);
    void addFlight(Flight& flight);
    const vector<Flight*>& getFlights() const;
};
