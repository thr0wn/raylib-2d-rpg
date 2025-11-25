#include "timer.h"

void timerStart(Timer *timer, double endTime) {
  timer->endTime = endTime;
  timer->startTime = GetTime();  
}

bool timerIsDone(Timer timer) {
  return timerGetElapsed(timer) >= timer.endTime;  
}

double timerGetElapsed(Timer timer) {
  return   (GetTime() - timer.startTime);
}  
