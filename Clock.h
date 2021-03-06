#ifndef COMMON_CLOCK_H
#define COMMON_CLOCK_H

namespace Common {

class Clock {
	public:
		Clock();
		double limitFPS(int fps, bool output = true);
		static double getTime();
	private:
		double mLastTime;
		double mStatTime;
		int mFrames;
};

class Countdown {
	public:
		Countdown(float from);
		void doCountdown(float howmuch);
		bool checkAndRewind();
		bool countdownAndRewind(float howmuch);
		void rewind();
		bool check();
		bool running() const;
		float timeLeft() const;
		void clear();
		float getMaxTime() const;

	private:
		float mFrom;
		float mNow;
		bool mChecked;
};

class SteadyTimer {
	public:
		SteadyTimer(float steptime, float randomInit = 0.0f);
		bool check(float elapsedtime);

	private:
		float mStepTime;
		float mLeftTime;
};

}

#endif
