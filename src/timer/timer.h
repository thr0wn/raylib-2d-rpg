#pragma once
#include "../common.h"

void timerStart(Timer *timer, double endTime);
bool timerIsEnded(Timer timer);
double timerGetElapsed(Timer timer);
