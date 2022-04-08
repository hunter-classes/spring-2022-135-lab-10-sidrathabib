#pragma once
#include "movie.h"
#include "time.h"

class TimeSlot { 
public: 
    Movie movie;     // what movie
    Time startTime;  // when it starts

    std::string printTimeSlot(); 
    TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie);
    bool timeOverlap(TimeSlot ts1, TimeSlot ts2); 
};