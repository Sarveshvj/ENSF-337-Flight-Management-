//route.h

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
    /*
    REQUIRES: Src and dest are valid strings 
    PROMISIES: Sets destination to dest and source to src
    */

    string getSource() const;
    /*PROMISIES: Returns source */
    
    string getDestination() const;
    /*PROMISES: Returns destination*/

    void setSource(const string& src);
    /*PROMISIES: Sets source to src*/

    void setDestination(const string& dest);
    /*PROMISIES: Sets destination to dest */
};

#endif
