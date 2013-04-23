//
//  timer.h
//  test
//
//  Created by zhenzhen qi on 4/20/13.
//
//

#ifndef test_timer_h
#define test_timer_h
#include "ofMain.h"

class timer {
    
public:
    
    void start();
    bool isFinished();
    
    timer(unsigned long long tempTotalTime);
    
    unsigned long long savedTime; // When Timer started
    unsigned long long totalTime; // How long Timer should last
    unsigned long long passedTime;
};


#endif
