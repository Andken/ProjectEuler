// Problem 37

// The number 3797 has an interesting property. Being prime itself, it is possible to continuously remove digits from left to right, and remain prime at each stage: 3797, 797, 97, and 7. Similarly we can work from right to left: 3797, 379, 37, and 3.
// 
// Find the sum of the only eleven primes that are both truncatable from left to right and right to left.
// 
// NOTE: 2, 3, 5, and 7 are not considered to be truncatable primes.

#include <iostream>
#include <math.h>
#include <sstream>
#include <vector>
#include <algorithm>

#define UB 1000000
#define NUMBER_OF_LR_TRUNC_PRIMES 11

using namespace std;

static inline bool isPrime(const unsigned int n, const vector<unsigned int> &primes)
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
  vector<unsigned int> primes;
  primes.push_back(2);
  for(unsigned int i=3; i<UB; i+=2)
	  {
		  if(isPrime(i))
			  {
				  primes.push_back(i);
			  }
	  }
  
  int total = 0;  
  int count = 0;
  for(vector<unsigned int>::const_iterator i = primes.begin(); 
      i != primes.end() && count < NUMBER_OF_LR_TRUNC_PRIMES;
      ++i)
	  {
		  if(*i >= 10)
			  {
				  bool prime = true;
				  for(string working = toString(*i); working.length() >= 1 && prime; working = nextTruncLeft(working))
					  {
						  if(!isPrime(toInt(working), primes))
							  {
								  prime = false;
							  }
					  }
				  
				  for(string working = toString(*i); working.length() >= 1 && prime; working = nextTruncRight(working))
					  {
						  if(!isPrime(toInt(working), primes))
							  {
								  prime = false;
							  }
					  }
				  
				  if(prime)
					  {
						  cout << *i << endl;
						  total += *i;
						  ++count;
					  }
			  }
	  }
		  cout << "answer: " << total << endl;
		  
		  return 0;
}   
