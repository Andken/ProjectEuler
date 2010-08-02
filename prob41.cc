// Problem 41

// We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once. For example, 2143 is a 4-digit pandigital and is also prime.
// 
// What is the largest n-digit pandigital prime that exists?

#include <stdio.h>
#include <math.h>
#include <sstream>
#include <vector>
#include <algorithm>

#define UB 987654321
#define NUMBER_OF_LR_TRUNC_PRIMES 11
#define NUM_PERMS 362880

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

void printstring(char a[], const unsigned int n)
{
	for(unsigned int i=0; i<n; ++i)
		{
			printf("%d%s", a[i], i<n-1 ? "" : "\n");
		}
}

static inline void next(char a[], const unsigned int n)
{
	int k;
	unsigned int l=0;
	for(k=n-2; 
		k>-1 && a[k] > a[k+1];
		--k)
		{			
		}

	if(k==-1)
		return;

	for(l=n-1; a[k] > a[l]; --l)
		;

	{
		const char temp = a[k];
		a[k] = a[l];
		a[l] = temp;
	}

	++k;
	for(unsigned int i=0; k+i<n-i; ++i)
		{
			const char temp = a[k+i];
			a[k+i] = a[(n-1)-i];
			a[(n-1)-i] = temp;
		}
}

static int toInt(const char a[], const int n)
{
	char temp[n+1];
	for(int i=0; i<n; ++i)
		{
			temp[i] = a[i]+0x30;
		}
	temp[n] = '\0';

	return atoi(temp);
}

int main()
{
	for(int j=2; j<=9; ++j)
		{
			char test[j];
			for(int i=0; i<j; ++i)
				{
					test[i] = i+1;
				}
			
			
			for(int i=0; i<NUM_PERMS+1; ++i)
				{
					if(isPrime(toInt(test, j)))
						{
							printf("%d\n", toInt(test, j));
						}
					next(test, j);
				}
		}
//
//  vector<unsigned int> primes;
//  primes.push_back(2);
//  for(unsigned int i=3; i<UB; i+=2)
//	  {
//		  if(isPandigital(i))
//			  {
//				  if(isPrime(i))
//					  {
//						  primes.push_back(i);
//					  }
//			  }
//	  }
//  
//  int total = 0;  
//  int count = 0;
//  for(vector<unsigned int>::const_iterator i = primes.begin(); 
//      i != primes.end() && count < NUMBER_OF_LR_TRUNC_PRIMES;
//      ++i)
//	  {
//		  if(*i >= 10)
//			  {
//				  bool prime = true;
//				  for(string working = toString(*i); working.length() >= 1 && prime; working = nextTruncLeft(working))
//					  {
//						  if(!isPrime(toInt(working), primes))
//							  {
//								  prime = false;
//							  }
//					  }
//				  
//				  for(string working = toString(*i); working.length() >= 1 && prime; working = nextTruncRight(working))
//					  {
//						  if(!isPrime(toInt(working), primes))
//							  {
//								  prime = false;
//							  }
//					  }
//				  
//				  if(prime)
//					  {
//						  cout << *i << endl;
//						  total += *i;
//						  ++count;
//					  }
//			  }
//	  }
//		  cout << "answer: " << total << endl;
//		  
//		  return 0;
}   
