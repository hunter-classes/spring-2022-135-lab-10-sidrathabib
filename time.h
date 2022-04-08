#pragma once

class Time { 
public:
    
    int h;
    int m;
    
    std::string printTime();
    int minutesSinceMidnight();
    int minutesUntil(Time first, Time second);
    void addMinutes(Time t, int min);  
};