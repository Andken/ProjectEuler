#!/usr/bin/perl -w
# Problem 42
# 
# The nth term of the sequence of triangle numbers is given by, tn = ½n(n+1); so the first ten triangle numbers are:
# 
# 1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...
# 
# By converting each letter in a word to a number corresponding to its alphabetical position and adding these values we form a word value. For example, the word value for SKY is 19 + 11 + 25 = 55 = t10. If the word value is a triangle number then we shall call the word a triangle word.
# 
# Using words.txt (right click and 'Save Link/Target As...'), a 16K text file containing nearly two-thousand common English words, how many are triangle words?

use strict;
use POSIX qw/ceil/;
use POSIX qw/floor/;

my $file = "prob42.txt";

local($/);
open( my $fh, $file ) or die "sudden flaming death\n";
my $text = <$fh>;
my @words = split(/,/, $text);

my $num = 0;


foreach(@words)
{
    chomp;
    my $edited = $_;
    $edited =~ s/\"//g;
    print $edited . "\n";
    if(isTriangle(value($edited)))
    {
	$num += 1;
    }
}

print "total = $num\n";



sub value
{
    my $word = shift;
    my $total = 0;
    my @array = unpack("C*", $word);
    foreach(@array)
    {
	$total += ($_ - 64);
    }

    return $total;
}

sub isTriangle
{
    my $Tn = shift;
    return ceil((-1 + sqrt(1+8*$Tn))/2) == floor((-1 + sqrt(1+8*$Tn))/2);
}


