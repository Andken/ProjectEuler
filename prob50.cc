// Problem 50
// The prime 41, can be written as the sum of six consecutive primes:
// 
// 41 = 2 + 3 + 5 + 7 + 11 + 13
// This is the longest sum of consecutive primes that adds to a prime below one-hundred.
// 
// The longest sum of consecutive primes below one-thousand that adds to a prime, contains 21 terms, and is equal to 953.
// 
// Which prime, below one-million, can be written as the sum of the most consecutive primes?

#include <iostream>
#include <math.h>
#include <sstream>
#include <vector>
#include <algorithm>
#include <stdio.h>

#define LB 3
#define UB 1000000

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

  int answer = -1;
  int current_max = -1;

  for(int i=primes.size()-1; i>=0; --i)
    {
      for(unsigned int k=0; k<primes.size(); ++k)
	{
	  int num_consecutive_primes = 0;
	  int total = 0;
	  for(unsigned int j=k; j<primes.size() && total < primes[i]; ++j)
	    {
	      total += primes[j];
	      ++num_consecutive_primes;
	      
	      if(total == primes[i])
		{
		  if(current_max < num_consecutive_primes)
		    {
		      current_max = num_consecutive_primes;
		      answer = primes[i];
		      printf("current_max: %d ... ans: %d\n", current_max, answer);
		    }
		}
	    }
	}
    }

  printf("%d\n", answer);

  return 0;
}
 
