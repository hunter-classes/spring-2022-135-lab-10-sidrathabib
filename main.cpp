#include <iostream>
#include "time.h"
#include "movie.h"
#include "timeslot.h"

int main() { 
    Time t1 = {10, 30};
    Time t2 = {13, 40}; 
    Time t3 =  {5, 25};
    Time t4 =  {0, 17};
    Time t5 =  {6, 55};

    Movie movie1 = {"Back to the Future", COMEDY, 116};
    Movie movie2 = {"Black Panther", ACTION, 134};
    Movie movie3 = {"3-Idiots", COMEDY, 5};
    Movie movie4 = {"Your Name", ROMANCE, 112};
    Movie movie5 = {"Venom", ACTION, 112}; 

    TimeSlot morning = {movie1, {9, 15}};  
    TimeSlot daytime = {movie2, {12, 15}}; 
    TimeSlot evening = {movie3, {16, 45}}; 
    TimeSlot overlap2 = {movie5, {16, 30}};
    TimeSlot overlap1 = {movie4, {12, 15}}; 

//------------------------------------------------------//

    std::cout << "Task A: Simple functions for time" << std::endl; 
    std::cout << "From time " << t1.printTime() << " to time " << t2.printTime() << " is " 
              << t1.minutesUntil(t1, t2) << " mins" << std::endl;
    std::cout << "Time left" << t5.printTime() << " until midnight is " 
              << t5.minutesSinceMidnight() << " mins" << std::endl;
    std::cout << "\n------------------------------------------------------" << std::endl;

//------------------------------------------------------//

    std::cout << "Task B: Making it more interesting" << std::endl;
    t1.addMinutes(t1, 30);
    std::cout << "Adding 30 mins to time: " << t1.printTime() << std::endl;
    std::cout << "First Movie: " << movie1.printMovie() << std::endl;
    std::cout << "Second Movie: " << movie2.printMovie() << std::endl;

//------------------------------------------------------//

    std::cout << "\n------------------------------------------------------" << std::endl;
    std::cout << "Task C: TimeSlot ending time and printTimeSlot" << std::endl;
    std::cout << "Morning Time Slot: " << morning.printTimeSlot() << std::endl;
    std::cout << "Day Time Slot: " << daytime.printTimeSlot() << std::endl;

//------------------------------------------------------//

    std::cout << "\n------------------------------------------------------" << std::endl;
    std::cout << "Task D: Scheduling X after Y?" << std::endl;
    TimeSlot temp1 = morning.scheduleAfter(morning, movie2); 
    std::cout << "Next Morning Movie\n" << "Result: " << temp1.printTimeSlot() << std::endl;
    TimeSlot temp2 = daytime.scheduleAfter(daytime, movie3);
    std::cout << "Next Day Movie\n;" << "Result: " << temp2.printTimeSlot() << std::endl; 

//------------------------------------------------------//

    std::cout << "\n------------------------------------------------------" << std::endl;
    std::cout << "Task E: Overlapping time slots?" << std::endl;
    std::cout << "Return false: " << daytime.timeOverlap(daytime, morning) << std::endl;
    std::cout << "Return true: " << daytime.timeOverlap(daytime, overlap1) << std::endl;

    return 0; 
}

//------------------------------------------------------//
