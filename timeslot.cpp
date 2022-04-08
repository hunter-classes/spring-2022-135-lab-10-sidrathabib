#include <iostream>
#include "timeslot.h"
#include "movie.h"
#include "time.h"

//------------------------------------------------------//

std::string TimeSlot::printTimeSlot() { 
    std::string g;
    switch (this->movie.genre) {
        case ACTION   : g = "ACTION"; break;
        case COMEDY   : g = "COMEDY"; break;
        case DRAMA    : g = "DRAMA";  break;
        case ROMANCE  : g = "ROMANCE"; break;
        case THRILLER : g = "THRILLER"; break;
    }

    Time new_time = this->startTime;
    new_time.addMinutes(new_time, this->movie.duration);
    std::string mins = std::to_string(new_time.m);

    if(new_time.m < 10) { 
        mins = "0" + mins;
    }

    return this->movie.title + " " + g + 
    " (" + std::to_string(this->movie.duration) + " min)" + 
    " [start time " + std::to_string(this->startTime.h) + ":" + std::to_string(this->startTime.m) + 
    ", end time " + std::to_string(new_time.h) + ":" + mins + "]";
}

//------------------------------------------------------//

TimeSlot TimeSlot::scheduleAfter(TimeSlot ts, Movie nextMovie) { 
    TimeSlot next; 
    next.movie = nextMovie;
    next.startTime = ts.startTime; 
    next.startTime.addMinutes(next.startTime, ts.movie.duration);

    return next;
}

//------------------------------------------------------//

bool TimeSlot::timeOverlap(TimeSlot ts1, TimeSlot ts2) { 
    if(ts1.startTime.minutesUntil(ts1.startTime, ts2.startTime) > 0) { 
        if(ts1.startTime.minutesUntil(ts1.startTime, ts2.startTime) < ts1.movie.duration) {
            return true;
        }     
    } else if(abs(ts1.startTime.minutesUntil(ts1.startTime, ts2.startTime)) < ts2.movie.duration) { 
        return true;
    }
    
    return false; 
} 
//------------------------------------------------------//