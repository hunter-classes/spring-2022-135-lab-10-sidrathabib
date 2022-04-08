#include <iostream>
#include "time.h"

//------------------------------------------------------//

std::string printTime(Time time) {
    std::string result = std::to_string(time.h) + ":" + std::to_string(time.m);
    return result;
}

//------------------------------------------------------//

int minutesSinceMidnight(Time time) {
  int minutes = 0;
  minutes += time.h * 60;
  minutes += time.m;

  return minutes;
}

//------------------------------------------------------//

int minutesUntil(Time early, Time late) {
  if (early.m > late.m) {
    late.h -= 1;
    late.m += 60;
  } 

  int minutes = 0;
  minutes += (late.h - early.h) * 60;
  minutes += (late.m - early.m);

  return minutes;
}

//------------------------------------------------------//

Time addMinutes(Time time0, int min) {
  int new_h = time0.h;
  int new_m = time0.m;

  while(min > 60) {
    new_h += 1;
    min -= 60;
  }

  new_m += min;

  if (new_m > 60) {
    new_h += 1;
    new_m -= 60;
  }

  return {new_h, new_m};
}

//------------------------------------------------------//