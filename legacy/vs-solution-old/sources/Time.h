#pragma once
class Time
{
private:
    int time_in_secs;
public:
    Time(int hour, int min, int sec);
    Time();

    int get_hours() const;
    int get_minutes() const;
    int get_seconds() const;

    int seconds_from(Time t) const;
    void add_seconds(int s);



};

