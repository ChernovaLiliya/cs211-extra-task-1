double seconds_difference(double time_1, double time_2)
{
    return time_2 - time_1;
}

int main()
{
	assert(seconds_difference(1800.0, 3600.0) == 1800.0);
	assert(seconds_difference(3600.0, 1800.0) == -1800.0);
	assert(seconds_difference(1800.0, 2160.0) == 360.0);
	assert(seconds_difference(1800.0, 1800.0) == 0.0);
}


double hours_difference(double time_1, double time_2)
{
   return (time_2 - time_1) / 3600.0;
}

int main()
{
	assert(hours_difference(1800.0, 3600.0) == 0.5);
	assert(hours_difference(3600.0, 1800.0) == -0.5);
	assert(hours_difference(1800.0, 2160.0) ==	0.1);
	assert(hours_difference(1800.0, 1800.0) ==	0.0);
}

double to_float_hours(int hours, int minutes, int seconds)
{
    assert (minutes >= 0 && minutes <= 60 && seconds >= 0 && seconds <= 60);
    
    return (hours * 3600 + minutes * 60 + seconds) / 3600.0;
}

int main()
{
	assert(to_float_hours(0, 15, 0) == 0.25);
	assert(to_float_hours(2, 45, 9) == 2.7525);
	assert(to_float_hours(1, 0, 36) == 1.01);
}

double to_24_hour_clock(double hours)
{
    assert(hours >= 0);
	double int_part = 0;
	double frac = modf(hours, &int_part);
	return ((int)int_part % 24) + frac;
}
int main()
{
	assert(to_24_hour_clock(24) == 0);
	assert(to_24_hour_clock(48) == 0);
	assert(to_24_hour_clock(25) == 1);
	assert(to_24_hour_clock(4) == 4);
	assert(to_24_hour_clock(28.5) == 4.5);
}

/*
    Implement three functions
        * get_hours
        * get_minutes
        * get_seconds
    They are used to determine the hours part, minutes part and seconds part 
    of a time in seconds. E.g.:

    >>> get_hours(3800)
    1

    >>> get_minutes(3800)
    3

    >>> get_seconds(3800)
    20

    In other words, if 3800 seconds have elapsed since midnight, 
    it is currently 01:03:20 (hh:mm:ss).
*/

double time_to_utc(int utc_offset, double time)
{
    assert(time >= 0 && time <= 24);
	assert(utc_offset >= -12 && utc_offset <= 12);
	return ((int)time - utc_offset) % 24;
}
int main()
{
	assert(time_to_utc(+0, 12.0) == 12.0);
	assert(time_to_utc(+1, 12.0) == 11.0);
	assert(time_to_utc(-1, 12.0) == 13.0);
	assert(time_to_utc(-11, 18.0) == 5.0);
	assert(time_to_utc(-1, 0.0) == 1.0);
	assert(time_to_utc(-1, 23.0) == 0.0);
}

double time_from_utc(int utc_offset, double time)
{
    assert(time >= 0 && time <= 24);
    assert(utc_offset >= -12 && utc_offset <= 12);
    if (fabs(utc_offset) > fabs(time))
	{
		double dif = fabs(utc_offset) - fabs(time);
		return 24 - dif;
	}
	else
	{
		return ((int)time + utc_offset) % 24;
	}
}
int main()
{
	assert(time_from_utc(+0, 12.0) == 12.0);
	assert(time_from_utc(+1, 12.0) == 13.0);
	assert(time_from_utc(-1, 12.0) == 11.0);
	assert(time_from_utc(+6, 6.0) == 12.0);
	assert(time_from_utc(-7, 6.0) == 23.0);
	assert(time_from_utc(-1, 0.0) == 23.0);
	assert(time_from_utc(-1, 23.0) == 22.0);
	assert(time_from_utc(+1, 23.0) == 0.0);
}
