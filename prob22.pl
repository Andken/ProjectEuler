#!/usr/bin/perl -w

use strict;

# slurp in the file
open(FH, "names.txt") or die "couldn't open";
my @name_file = <FH>;
close FH;

my @names = sort(split(/,/, $name_file[0]));

#printf "XXX: " . nameScore("\"COLIN\"") . "\n";
#die "XXXXXXXXX";

my $index = 0;
my $total = 0;
foreach(@names)
{
    my $name_score = nameScore($_);
    $index=$index+1;
    $total = $total + ($index*$name_score);
}

print "total: $total\n";

sub nameScore
{
    my ($name) = @_;
    my @letters = split(//,$name);

    my $total = 0;

    foreach(@letters)
    {
	if($_ ne "\"")
	{
	    $total = $total + ord($_)-64;
	}
    }

    return $total;
}
