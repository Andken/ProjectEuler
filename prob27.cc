// Prob 27
// Euler published the remarkable quadratic formula:
// 
// n² + n + 41
// 
// It turns out that the formula will produce 40 primes for the consecutive values n = 0 to 39. However, when n = 40, 402 + 40 + 41 = 40(40 + 1) + 41 is divisible by 41, and certainly when n = 41, 41² + 41 + 41 is clearly divisible by 41.
// 
// Using computers, the incredible formula  n²  79n + 1601 was discovered, which produces 80 primes for the consecutive values n = 0 to 79. The product of the coefficients, 79 and 1601, is 126479.
// 
// Considering quadratics of the form:
// 
// n² + an + b, where |a|  1000 and |b|  1000
// 
// where |n| is the modulus/absolute value of n
// e.g. |11| = 11 and |4| = 4
// Find the product of the coefficients, a and b, for the quadratic expression that produces the maximum number of primes for consecutive values of n, starting with n = 0.
// 

#include <iostream>
#include <math.h>
#include <sstream>
#include <vector>
#include <algorithm>

#define UB (80*80)+(80*1000)+(1000)

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

static inline int qf(int a, int b, int n)
{
	return n*n + a*n + b;
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

  cout << "starting (" << UB << ")" << endl;
  
  int max_a = -1001;
  int max_b = -1001;
  int max_n = -1;

  for(vector<unsigned int>::const_iterator b = primes.begin();
	  b != primes.end() && *b<=1000;
	  ++b)
	  {
		  for(int a=-1*(*b); a<=1000; a+=2)			  
			  {
				  int n=0;
				  while(isPrime(qf(a,*b,n)))
					  {
						  ++n;
					  }
				  
				  if(n>max_n)
					  {
						  max_n = n;
						  max_a = a;
						  max_b = *b;
					  }
			  }
	  }
  
  cout << "answer: (n^2 + " << max_a << "n + " << max_b << ") and n = 0 - " << max_n << endl;
  cout << "answer: " << max_a * max_b << endl;
  return 0;
}
