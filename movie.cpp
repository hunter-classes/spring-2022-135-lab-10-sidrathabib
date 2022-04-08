#include <iostream>
#include "movie.h"


std::string Movie::printMovie() {
    std::string g;
    switch (this->genre) {
        case ACTION   : g = "ACTION"; break;
        case COMEDY   : g = "COMEDY"; break;
        case DRAMA    : g = "DRAMA";  break;
        case ROMANCE  : g = "ROMANCE"; break;
        case THRILLER : g = "THRILLER"; break;
    }
    
    return this->title + " " + g + " (" + std::to_string(this->duration) + " min)";
}
