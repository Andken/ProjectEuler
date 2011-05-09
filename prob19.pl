#!/usr/bin/perl -w

use strict;

my $year = 1901;

# Jan 1 1901 is a tuesday
my $day = 2;

my $num_sundays_on_first = 0;

while($year <= 2000)
{
    # Jan
    if($day % 7 == 0)
    {
	$num_sundays_on_first = $num_sundays_on_first + 1;
    }
    
    $day = $day+31;
    
    #Feb
    if($day % 7 == 0)
    {
	$num_sundays_on_first = $num_sundays_on_first + 1;
    }
    
    if(leap_year($year))
    {
	$day = $day+29;
    }
    else
    {
	$day = $day+28;
    }
    
    # Mar
    if($day % 7 == 0)
    {
	$num_sundays_on_first = $num_sundays_on_first + 1;
    }
    
    $day = $day+31;
    
    # Apr
    if($day % 7 == 0)
    {
	$num_sundays_on_first = $num_sundays_on_first + 1;
    }
    
    $day = $day+30;
    
    # May
    if($day % 7 == 0)
    {
	$num_sundays_on_first = $num_sundays_on_first + 1;
    }
    
    $day = $day+31;
    
    # Jun
    if($day % 7 == 0)
    {
	$num_sundays_on_first = $num_sundays_on_first + 1;
    }
    
    $day = $day+30;
    
    # Jul
    if($day % 7 == 0)
    {
	$num_sundays_on_first = $num_sundays_on_first + 1;
    }
    
    $day = $day+31;
    
    # Aug
    if($day % 7 == 0)
    {
	$num_sundays_on_first = $num_sundays_on_first + 1;
    }
    
    $day = $day+31;
    
    # Sept
    if($day % 7 == 0)
    {
	$num_sundays_on_first = $num_sundays_on_first + 1;
    }
    
    $day = $day+30;
    
    # Oct
    if($day % 7 == 0)
    {
	$num_sundays_on_first = $num_sundays_on_first + 1;
    }
    
    $day = $day+31;
    
    # Nov
    if($day % 7 == 0)
    {
	$num_sundays_on_first = $num_sundays_on_first + 1;
    }
    
    $day = $day+30;
    
    # Dec
    if($day % 7 == 0)
    {
	$num_sundays_on_first = $num_sundays_on_first + 1;
    }
    
    $day = $day+31;
    
    
    $year++;
}

printf "num_sundays = $num_sundays_on_first\n";





sub leap_year {
    my($year) = @_;
    if($year % 4 == 0)
    {
	if($year % 100 == 0)
	{
	    if($year % 400 == 0)
	    {
		return 1;
	    }
	    else
	    {
		return 0;
	    }
	}
	else
	{
	    return 1;
	}
    }
    else
    {
	return 0;
    }
}

