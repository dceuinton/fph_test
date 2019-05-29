#include <time.h>
#include <iostream>

class Timer {
	public:
		void start();
		void stop();
		void reset();
		double seconds();
		unsigned int milliseconds();

	private:
		time_t mStart, mStop;
};