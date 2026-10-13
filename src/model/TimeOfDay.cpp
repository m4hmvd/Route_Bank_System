#include <ctime>
#include <cassert>

using namespace std;

#include "TimeOfDay.h"

/**
   Computes the correct remainder for negative dividend
   @param a - an integer
   @param n - an integer > 0
   @return the mathematically correct remainder r such that
   a - r is divisible by n and 0 <= r and r < n
*/
int remainder(int a, int n)
{
   if (a >= 0)
      return a % n;
   else
      return n - 1 - (-a - 1) % n;
}

TimeOfDay::TimeOfDay(int hour, int min, int sec)
{
   assert(0 <= hour);
   assert(hour < 24);
   assert(0 <= min);
   assert(min < 60);
   assert(0 <= sec);
   assert(sec < 60);

   time_in_secs = 60L * 60 * hour + 60 * min + sec;
}

TimeOfDay::TimeOfDay()
{
   time_t now = time(0);
   tm local;
   localtime_s(&local, &now);
   time_in_secs = 60L * 60 * local.tm_hour + 60 * local.tm_min + local.tm_sec;
}

int TimeOfDay::get_hours() const
{
   return time_in_secs / (60 * 60);
}

int TimeOfDay::get_minutes() const
{
   return (time_in_secs / 60) % 60;
}

int TimeOfDay::get_seconds() const
{
   return time_in_secs % 60;
}

int TimeOfDay::seconds_from(TimeOfDay t) const
{
   return time_in_secs - t.time_in_secs;
}

void TimeOfDay::add_seconds(int s)
{
   const int SECONDS_PER_DAY = 60 * 60 * 24;
   time_in_secs = remainder(time_in_secs + s, SECONDS_PER_DAY);
}
