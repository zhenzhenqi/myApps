//
//  timer.cpp
//  test
//
//  Created by zhenzhen qi on 4/20/13.
//
//

#include "timer.h"

timer::timer(unsigned long long tempTotalTime)
{
    totalTime = tempTotalTime;
    }


void timer::start() {
        // When the timer starts it stores the current time in milliseconds.
        savedTime = ofGetSystemTime();
    }

    // The function isFinished() returns true if 5,000 ms have passed.
    // The work of the timer is farmed out to this method.

bool timer::isFinished() {
        // Check how much time has passed
        passedTime = ofGetSystemTime();
        if (passedTime - savedTime > totalTime) {
            return true;
        } else {
            return false;
        }
}
