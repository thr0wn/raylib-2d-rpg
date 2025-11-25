#include "../common.h"

#ifndef TIMER_H
#define TIMER_H

typedef struct {
  double startTime;
  double endTime;
} Timer;

void timerStart(Timer *timer, double endTime);
bool timerIsDone(Timer timer);
double timerGetElapsed(Timer timer);

#endif
