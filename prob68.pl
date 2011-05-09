#!/usr/bin/perl
# Problem 68
# 
# Consider the following "magic" 3-gon ring, filled with the numbers 1 to 6, and each line adding to nine.
# 
# 
# Working clockwise, and starting from the group of three with the numerically lowest external node (4,3,2 in this example), each solution can be described uniquely. For example, the above solution can be described by the set: 4,3,2; 6,2,1; 5,1,3.
# 
# It is possible to complete the ring with four different totals: 9, 10, 11, and 12. There are eight solutions in total.
# 
# Total	Solution Set
# 9	4,2,3; 5,3,1; 6,1,2
# 9	4,3,2; 6,2,1; 5,1,3
# 10	2,3,5; 4,5,1; 6,1,3
# 10	2,5,3; 6,3,1; 4,1,5
# 11	1,4,6; 3,6,2; 5,2,4
# 11	1,6,4; 5,4,2; 3,2,6
# 12	1,5,6; 2,6,4; 3,4,5
# 12	1,6,5; 3,5,4; 2,4,6
# By concatenating each group it is possible to form 9-digit strings; the maximum string for a 3-gon ring is 432621513.
# 
# Using the numbers 1 to 10, and depending on arrangements, it is possible to form 16- and 17-digit strings. What is the maximum 16-digit string for a "magic" 5-gon ring?

#include <sstream>
#include <iostream>
#include <math.h>
#include <vector>

### using namespace std;
### 
### static unsigned long long convertToULL(const string &src)
### {
###   unsigned long long output;
###   stringstream converter(src);
###   converter >> output;
###   
###   return output;
### }
### 
### class fiveGon
### {
### public:
###   fiveGon(unsigned int c0,
### 	  unsigned int c1,
### 	  unsigned int c2,
### 	  unsigned int c3,
### 	  unsigned int c4,
### 	  unsigned int c5,
### 	  unsigned int c6,
### 	  unsigned int c7,
### 	  unsigned int c8,
### 	  unsigned int c9)
###   {
###     c[0] = c0;
###     c[1] = c1;
###     c[2] = c2;
###     c[3] = c3;
###     c[4] = c4;
###     c[5] = c5;
###     c[6] = c6;
###     c[7] = c7;
###     c[8] = c8;
###     c[9] = c9;
###   }
### 
###   string stringValue() const
###   {
###     string s("");
### 
###     int index = lowestStartingPoint();
### 
###     for(int i=0; i<5; ++i)
###       {
### 	s+=getSetString(index);
### 	index = nextIndex(index);
###       }
###     
###     return s;
###   }
### 
### private:
###   unsigned int c[10];
### 
###   int nextIndex(int index) const
###   {
###     return (index+1)%5;
###   }
### 
###   string getSetString(int index) const
###   {
###     stringstream ss;
### 
###     if(index < 4)
###       ss << c[index] << c[index+5] << c[index+6];
###     else
###       ss << c[4] << c[9] << c[5];
### 
###     return ss.str();
###   }
### 
### public:
###   int getSetValue(int index) const
###   {
###     if(index < 4)
###       return c[index]+c[index+5]+c[index+6];
###     else
###       return c[4]+c[9]+c[5];
###   }
### 
###   int lowestStartingPoint() const
###   {
###     int working_index = 0;
###     if(c[working_index] > c[1]) working_index = 1;
###     if(c[working_index] > c[2]) working_index = 2;
###     if(c[working_index] > c[3]) working_index = 3;
###     if(c[working_index] > c[4]) working_index = 4;
###     return working_index;
###   }
### 
### public:
###   void print() const
###   {
###     cout << "\t\t\t " << c[0] << endl;
###     cout << "\t\t\t\t\t" << c[1] << endl;
###     cout << "\t\t\t\t" << c[5] << endl;
###     cout << "\t\t\t" << c[9] << "\t\t " << c[6] << endl;
###     cout << "\t\t" << c[4] << endl;
###     cout << "\t\t\t  " << c[8] << "\t\t" << c[7] << "\t" << c[2] << endl;
###     cout << "\t\t\t   " << c[3] << endl;
### 
###     cout << c[0] << " " << c[5] << " " << c[6] << " = " << getSetValue(0) << endl;
###     cout << c[1] << " " << c[6] << " " << c[7] << " = " << getSetValue(1) << endl;
###     cout << c[2] << " " << c[7] << " " << c[8] << " = " << getSetValue(2) << endl;
###     cout << c[3] << " " << c[8] << " " << c[9] << " = " << getSetValue(3) << endl;
###     cout << c[4] << " " << c[9] << " " << c[5] << " = " << getSetValue(4) << endl;
### 
###     cout << "Number: " << convertToULL(stringValue()) << endl;
###   }
### 
### };
### 
### int main()
### {
###   vector<int> v;
### 
###   for(int i=1; i<=10; ++i)
###     {
###       v.push_back(i);
###     }
### 
###   
### 
### 
###   return 0;
### } 
### 

use strict;
require List::Permutor;

my @results = ();

my $permutator = List::Permutor->new(1,2,3,4,5,6,7,8,9,10);
while( my @permutation = $permutator->next)
{
    if(isMagic(@permutation))
    {
	
    }
}

sub isMagic
{
    my @set = @_;
    foreach(@set)
    {
	print "$_\n";
    }
}
