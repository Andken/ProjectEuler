// Problem 49
// 
// The arithmetic sequence, 1487, 4817, 8147, in which each of the terms increases by 3330, is unusual in two ways: (i) each of the three terms are prime, and, (ii) each of the 4-digit numbers are permutations of one another.
// 
//   There are no arithmetic sequences made up of three 1-, 2-, or 3-digit primes, exhibiting this property, but there is one other 4-digit increasing sequence.
// 
// What 12-digit number do you form by concatenating the three terms in this sequence?

#include <iostream>
#include <math.h>
#include <sstream>
#include <vector>
#include <algorithm>
#include <stdio.h>

#define LB 1001
#define UB 10000

using namespace std;

static bool isPrime(const unsigned int n)
{
  if(n%2 == 0) return false;
  
  for(int i=3; i<=ceil(sqrt(n)); i+=2)
    {
      if(n%i == 0)
	{
	  return false;
	}
    }
  
  return true;
}

static string toString(const unsigned int n)
{
  stringstream out;
  out << n;
  return out.str();
}

static unsigned int toInt(char c)
{
  return c-48;
}

static vector<int> toVector(short a)
{
  vector<int> v;

  string sa(toString(a));

  for(string::const_iterator i = sa.begin();
      i != sa.end();
      ++i)
    {
      
      v.push_back(toInt(*i));
    }

  sort(v.begin(), v.end());

  return v;
}

static bool isPermute(short a, short b)
{
  vector<int> va = toVector(a);
  vector<int> vb = toVector(b);

  return va == vb;
}

int main()
{
  vector<int> primes;
  primes.push_back(2);
  for(int i=LB; i<UB; i+=2)
    {
      if(isPrime(i))
	{
	  primes.push_back(i);
	} 
    } 

  const vector<int> primes2 = primes;
  const vector<int> primes3 = primes;

  for(vector<int>::const_iterator i = primes.begin();
      i!=primes.end();
      ++i)
    {
      for(vector<int>::const_iterator j = primes2.begin();
	  j!=primes2.end();
	  ++j)
	{
	  if(*i < *j && isPermute(*i, *j))
	    {
	      int diff = *j-*i;
	      if(*j+diff < 10000 && isPrime(*j+diff) && isPermute(*j, *j+diff))
		{
		  printf("%d %d %d\n", *i, *j, *j+diff);
		}
	    }
	}      
    }

  return 0;
}
 
