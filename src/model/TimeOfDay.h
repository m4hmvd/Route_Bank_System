#ifndef CCC_TIME_H
#define CCC_TIME_H

/**
   A class that describes a time of day
   (between 00:00:00 and 23:59:59)
*/
class TimeOfDay
{
public:
   /**
      Constructs a time of day.
      @param hour the hours
      @param min the minutes
      @param sec the seconds
   */
   TimeOfDay(int hour, int min, int sec);
   /**
      Constructs a TimeOfDay object that is set to
      the time at which the constructor executes.
   */
   TimeOfDay();

   /**
      Gets the hours of this time.
      @return the hours
   */
   int get_hours() const;
   /**
      Gets the minutes of this time.
      @return the minutes
   */
   int get_minutes() const;
   /**
      Gets the seconds of this time.
      @return the seconds
   */
   int get_seconds() const;

   /**
      Computes the seconds between this time and another.
      @param t the other time
      @return the number of seconds between this time and t
   */
   int seconds_from(TimeOfDay t) const;
   /**
      Adds a number of seconds to this time.
      @param s the number of seconds to add
   */
   void add_seconds(int s);

private:
   int time_in_secs;
};

#endif
