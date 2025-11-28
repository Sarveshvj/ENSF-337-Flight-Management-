#include "Route.h"

Route::Route() {
    source =" ";
    destination =" ";
}

Route::Route(const string& src, const string& dest) {
    source = src;
    destination = dest;
}

string Route::getSource() const{
    return source;
}

string Route::getDestination() const{
    return destination;
}

void Route::setSource(const string& src){
    source = src;
}

void Route::setDestination(const string& dest){
    destination = dest;
}
