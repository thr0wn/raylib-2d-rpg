#include "../common.h"

#ifndef TIMER_H
#define TIMER_H

typedef struct Timer {
  double startTime;
  double endTime;
} Timer;

void timerStart(Timer *timer, double endTime);
bool timerIsEnded(Timer timer);
double timerGetElapsed(Timer timer);

#endif
