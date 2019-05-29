#include "timer.h"

void Timer::start() {
	mStart = clock();
}

void Timer::stop() {
	mStop = clock();
}
void Timer::reset() {
	mStart = 0;
	mStop = 0;
}

double Timer::seconds() {
	return double (mStop - mStart)/CLOCKS_PER_SEC;
}

unsigned int Timer::milliseconds() {
	return (double (mStop - mStart)/CLOCKS_PER_SEC) * 1000;
}