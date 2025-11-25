#include "timer.h"
#include <stdio.h>

// Start timer at current time to end at current time plus elapsed
void timerStart(Timer *timer, double endTime) {
  timer->endTime = endTime;
  timer->startTime = GetTime();
}

// Check if the timer has ended
bool timerIsEnded(Timer timer) {
  return timerGetElapsed(timer) >= timer.endTime;
}

// Check how much time has passed since the timer.startTime
double timerGetElapsed(Timer timer) { return (GetTime() - timer.startTime); }
