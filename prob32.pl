#!/usr/bin/perl -w

# Problem 32

# We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once; for example, the 5-digit number, 15234, is 1 through 5 pandigital.
# 
# The product 7254 is unusual, as the identity, 39  186 = 7254, containing multiplicand, multiplier, and product is 1 through 9 pandigital.
# 
# Find the sum of all products whose multiplicand/multiplier/product identity can be written as a 1 through 9 pandigital.
# 
# HINT: Some products can be obtained in more than one way so be sure to only include it once in your sum.

use strict;
require List::Permutor;

my @results = ();

my $permutator = List::Permutor->new(1,2,3,4,5,6,7,8,9);
while( my @permutation = $permutator->next)
{
    for(my $prod_idx=1; $prod_idx <= $#permutation-1; $prod_idx=$prod_idx+1)
    {
	my @working_permutation = @permutation;
	splice (@working_permutation, $prod_idx, 0, "*");
	for(my $eq_idx = $prod_idx+2; $eq_idx <= $#working_permutation; $eq_idx=$eq_idx+1)
	{
	    my @working_permutation2 = @working_permutation;
	    splice (@working_permutation2, $eq_idx, 0, "==");
	    my $string = join("", @working_permutation2);
	    my $result = eval($string);
	    if($result == 1)
	    {
		my @product = split (/==/, $string);
		print "$string :: ";
		print "$product[1]\n";
		push(@results, $product[1]);
	    }
	}
    }
}

##12*483==5796 :: 5796
##138*42==5796 :: 5796
##157*28==4396 :: 4396
##159*48==7632 :: 7632
##1738*4==6952 :: 6952
##18*297==5346 :: 5346
##186*39==7254 :: 7254
##1963*4==7852 :: 7852
##198*27==5346 :: 5346
##27*198==5346 :: 5346
##28*157==4396 :: 4396
##297*18==5346 :: 5346
##39*186==7254 :: 7254
##4*1738==6952 :: 6952
##4*1963==7852 :: 7852
##42*138==5796 :: 5796
##48*159==7632 :: 7632
##483*12==5796 :: 5796

#my @results = (5796,
#	       5796,
#	       4396,
#	       7632,
#	       6952,
#	       5346,
#	       7254,
#	       7852,
#	       5346,
#	       5346,
#	       4396,
#	       5346,
#	       7254,
#	       6952,
#	       7852,
#	       5796,
#	       7632,
#	       5796);

my %saw;
@saw{@results} = ();
my @uniq = keys %saw;

my $answer = 0;

foreach(@uniq)
{
    $answer = $answer + $_;
}

print "$answer\n";
