// Problem 46

// It was proposed by Christian Goldbach that every odd composite number can be written as the sum of a prime and twice a square.
// 
// 9 = 7 + 212
// 15 = 7 + 222
// 21 = 3 + 232
// 25 = 7 + 232
// 27 = 19 + 222
// 33 = 31 + 212
// It turns out that the conjecture was false.
// 
// What is the smallest odd composite that cannot be written as the sum of a prime and twice a square?

#include <iostream>
#include <math.h>
#include <sstream>
#include <vector>
#include <algorithm>
#include <stdio.h>

#define UB 1000000
#define NUMBER_OF_LR_TRUNC_PRIMES 11

using namespace std;

static inline bool isPrime(const int n, const vector<int> &primes)
{
  return primes.end() != find(primes.begin(), primes.end(), n);
}

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

static inline string toString(const unsigned int n)
{
  stringstream out;
  out << n;
  return out.str();
}

static inline string nextTruncLeft(string s)
{
	s.erase(s.begin());	
	return s;
}

static inline string nextTruncRight(string s)
{
	s.erase(s.length()-1);	
	return s;
}

static inline unsigned int toInt(const string &s)
{
  int retval;
  istringstream i(s);

  i >> retval;

  return retval;
}

int main()
{
  vector<int> primes;
  primes.push_back(2);
  for(int i=3; i<UB; i+=2)
    {
      if(isPrime(i))
	{
	  primes.push_back(i);
	}
      
    }
  
  vector<int> twoXsquares;
  for(int i=1; 2*i*i<UB; ++i)
    {
      twoXsquares.push_back(2*i*i);
    }
 
  for(int i=9; i<UB; i+=2)
    {
      if(!isPrime(i, primes))
	{
	  bool done = false;
	  for(vector<int>::const_iterator j = primes.begin();
	      !done && *j<i && j != primes.end();
	      ++j)
	    {
	      //	      printf("trying i=%d ... j=%d\n", i, *j);
	      for(vector<int>::const_iterator k = twoXsquares.begin();
		  ((*k+*j) <= i) && (k != twoXsquares.end());
		  ++k)
		{
		  //		  printf("\tk = %d (%d)\n", *k, *k+*j);
		  if(*j+*k == i)
		    {
		      //		      printf("\t%d + %d = %d\n", *j, *k, i);
		      done = true;
		      break;
		    }
		}
	    }
	  if(done == false)
	    {
	      printf("answer: %d\n", i);
	      return 0;
	    }
	}
    }
 
}
