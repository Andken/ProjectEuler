#!/usr/bin/perl -w

## Problem 38

# Take the number 192 and multiply it by each of 1, 2, and 3:
# 
# 192  1 = 192
# 192  2 = 384
# 192  3 = 576
# By concatenating each product we get the 1 to 9 pandigital, 192384576. We will call 192384576 the concatenated product of 192 and (1,2,3)
# 
# The same can be achieved by starting with 9 and multiplying by 1, 2, 3, 4, and 5, giving the pandigital, 918273645, which is the concatenated product of 9 and (1,2,3,4,5).
# 
# What is the largest 1 to 9 pandigital 9-digit number that can be formed as the concatenated product of an integer with (1,2, ... , n) where n  1?

use strict;

for(my $i=1; $i<99999; $i = $i+1)
{
    my $working_string = "";
    while(length($working_string) < 9)
    {
	for(my $j=1; length($working_string) < 9;$j = $j+1)
	{
	    my $num_to_concat = $i*$j;
	    $working_string = sprintf("$working_string" . "$num_to_concat");
	}
    }

    if(isPandigital($working_string))
    {
	print "PANDIGITAL! $i $working_string\n";
    }
}


sub isPandigital
{
    my $num = shift;

    if(length($num) != 9)
    {
	return 0;
    }

    my $pandigits = "123456789";
    my $ordered_digits = join("", sort(split("", $num)));

    if($pandigits eq $ordered_digits)
    {
	return 1;
    }
    else
    {
	return 0;
    }
}
