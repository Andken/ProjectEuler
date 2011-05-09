// Problem 35
// The number, 197, is called a circular prime because all rotations of the digits: 197, 971, and 719, are themselves prime.
// 
// There are thirteen such primes below 100: 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, and 97.
// 
// How many circular primes are there below one million?

#include <iostream>
#include <math.h>
#include <sstream>
#include <vector>
#include <algorithm>

#define UB 1000000

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

static inline string nextCircular(string s)
{
	s.push_back(s.at(0));
	s.erase(s.begin());
	
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
  for(unsigned int i=3; i<UB; i+=2)
	  {
		  if(isPrime(i))
			  {
				  primes.push_back(i);
			  }
	  }
  
  
  int count = 1; // for 2
  for(vector<unsigned int>::const_iterator i = primes.begin(); 
      i != primes.end();
      ++i)
	  {
		  bool all_prime = true;
		  string working_value = toString(*i);
		  while((working_value = nextCircular(working_value)) != toString(*i))
			  {
				  if(!isPrime(toInt(working_value), primes))
					  {
						  all_prime = false;
						  break;
					  }
			  }
		  
		  if(all_prime) 
			  {
				  ++count;
			  }
	  }
  
  cout << "answer: " << count << endl;
  
  return 0;
}   
