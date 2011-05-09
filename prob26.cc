// Problem 26

// A unit fraction contains 1 in the numerator. The decimal representation of the unit fractions with denominators 2 to 10 are given:
// 
// 1/2	= 	0.5
// 1/3	= 	0.(3)
// 1/4	= 	0.25
// 1/5	= 	0.2
// 1/6	= 	0.1(6)
// 1/7	= 	0.(142857)
// 1/8	= 	0.125
// 1/9	= 	0.(1)
// 1/10	= 	0.1
// Where 0.1(6) means 0.166666..., and has a 1-digit recurring cycle. It can be seen that 1/7 has a 6-digit recurring cycle.
// 
// Find the value of d  1000 for which 1/d contains the longest recurring cycle in its decimal fraction part.


#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

#define LENGTH 10000
#define OFFSET 250
#define MAX_ATTEMPT 1000

inline int cycleLength(const int denom)
{
  cout << "########### " << denom << endl;
  vector<int> v;
  
  {
    int working_num=10;
    int remainder = -1;
    
    for(int i=0; i<LENGTH && remainder != 0; ++i)
      {
	int quotiant = working_num / denom;
	remainder = working_num % denom;
	if(i>=OFFSET) 
	  {
	    v.push_back(quotiant);
	  }
	working_num = (working_num - (quotiant * denom)) * 10;
      }
  }
  
  //	for(vector<int>::const_iterator i=v.begin();
  //		i != v.end();
  //		++i)
  //		{
  //			cout << *i;
  //		}
  //	cout << endl;
  
  if(v.size() == LENGTH-OFFSET)
    {
      int start_of_cycle = 1;
      while(v.at(0) != v.at(start_of_cycle++))
	{
	}
      --start_of_cycle;
      
      while(1)
	{
	  bool match = true;
	  for(int i=0; i<start_of_cycle; ++i)
	    {
	      match = match 
		&& v.at(i) == v.at(start_of_cycle+i) 
		&& v.at(i) == v.at(2*(start_of_cycle)+i) 
		&& v.at(i) == v.at(3*(start_of_cycle)+i);
	    }
	  
	  
	  if(match) 
	    {
	      return start_of_cycle;
	    }
	  else
	    {
	      ++start_of_cycle;
	      while(v.at(0) != v.at(start_of_cycle++))
		{
		}
	      --start_of_cycle;
	    }
	}
    }
  return 0;
}


int main()
{
  int max_generator = 1;
  int max = -1;
  
  for(int i=1; i<=MAX_ATTEMPT; ++i)
    {
      if(cycleLength(i) > max)
	{
	  max = cycleLength(i);
	  max_generator = i;
	}
    }
  
  cout << max_generator << ":" << cycleLength(max_generator) << endl;
  
  return 0;
}

