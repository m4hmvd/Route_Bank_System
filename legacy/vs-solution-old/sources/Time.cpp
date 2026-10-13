#include "Time.h"
#define _CRT_SECURE_NO_WARNINGS
#include <ctime>
int remainder(int a, int n)
{
    if (a >= 0)
        return a % n;
    else
        return n - 1 - (-a - 1) % n;
}

Time::Time(int hour, int min, int sec)
{
    if (hour < 0 || hour >= 24)
        hour = 0;
    if (min < 0 || min >= 60)
        min = 0;
    if (sec < 0 || sec >= 60)
        sec = 0;

    time_in_secs = hour * 3600 + min * 60 + sec;
}

Time::Time()
{
    time_t now = time(0);
    tm* t = localtime(&now);

    time_in_secs =
        t->tm_hour * 3600 +
        t->tm_min * 60 +
        t->tm_sec;
}

int Time::get_hours() const
{
    return time_in_secs / 3600;
}

int Time::get_minutes() const
{
    return (time_in_secs / 60) % 60;
}

int Time::get_seconds() const
{
    return time_in_secs % 60;
}

int Time::seconds_from(Time t) const
{
    return time_in_secs - t.time_in_secs;
}

void Time::add_seconds(int s)
{
    const int SECONDS_PER_DAY = 24 * 3600;
    time_in_secs = remainder(time_in_secs + s, SECONDS_PER_DAY);
}
