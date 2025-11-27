#ifndef ROUTE_H
#define ROUTE_H

#include <string>

using std::string;

class Route {
private:
    string source;

    string destination;

public:
    Route();

    Route(const string& src, const string& dest);

    string getSource() const;
    
    string getDestination() const;

    void setSource(const string& src);

    void setDestination(const string& dest);
};

#endif
