// Problem 51
// By replacing the 1st digit of *3, it turns out that six of the nine possible values: 13, 23, 43, 53, 73, and 83, are all prime.
// 
// By replacing the 3rd and 4th digits of 56**3 with the same digit, this 5-digit number is the first example having seven primes among the ten generated numbers, yielding the family: 56003, 56113, 56333, 56443, 56663, 56773, and 56993. Consequently 56003, being the first member of this family, is the smallest prime with this property.
// 
// Find the smallest prime which, by replacing part of the number (not necessarily adjacent digits) with the same digit, is part of an eight prime value family.

#include <iostream>
#include <math.h>
#include <sstream>
#include <list>
#include <algorithm>
#include <stdio.h>

#define LB 998LL
#define UB 10000000000LL

using namespace std;

static long long toInt(const string &s)
{
	long long retval;
	istringstream i(s);
	
	i >> retval;
	
	return retval;
}

static bool isPrime(const long long n)
{
	if(n == 1) return false;
	if(n%2 == 0) return false;
	
	for(long long i=3; i<=ceil(sqrt(n)); i+=2)
		{
			if(n%i == 0)
				{
					return false;
				}
		}
	
	return true;
}



static string toString(long long n)
{
	stringstream out;
	out << n;
	return out.str();
}

static list<string> eligibles(long long n)
{
	list<string> response;
	
	string num = toString(n);
	const int length = num.length();
	
	for(int i=0; i<length-1; ++i)
		{
			for(int j=0; j<length-1; ++j)
				{
					if(num[i] == num[j] && 
					   i != j)
						{
							for(int k=0; k<length-1; ++k)
								{
									if(num[i] == num[k] &&
									   num[j] == num[k] &&
									   i != k &&
									   j!= k)
										{
											string pusher(num);
											pusher[i] = '-';
											pusher[j] = '-';
											pusher[k] = '-';
											response.push_back(pusher);
										}
								}
						}
				}
		}
	
	response.sort();
	response.unique();

	return response;
}

static void printList(const list<string> &v)
{
	for(list<string>::const_iterator i = v.begin();
		i!=v.end();
		++i)
		{
			printf("%s ", (*i).c_str());
		}
}

static void printList(const list<long long> &v)
{
	for(list<long long>::const_iterator i = v.begin();
		i!=v.end();
		++i)
		{
			printf("%lld ", *i);
		}
}

list<long long> primeFamily(const string &s)
{
	list<long long> pf;
	const string searchString("-");
	for(char c='0'; c<='9'; ++c)
		{
			string working_string(s);
			string replaceString(1, c);
			
			// replace the 'a's with the number
			string::size_type pos = 0;
			while ( (pos = working_string.find(searchString, pos)) != string::npos ) 
				{
					working_string.replace( pos, searchString.size(), replaceString );
					pos++;
				}

			const long long working_num = toInt(working_string);
			
			if(isPrime(working_num))
				{
					if(working_string[0] != '0')
						{
							pf.push_back(working_num);
						}
				}
			
			// if we haven't gotten a prime yet, we should quit now
			if(c >= '2' && pf.size() == 0)
				{
					break;
				}
		}
	
	return pf;
}

int main()
{
	long long counter = LB;
	for(long long x=LB+1; x<UB; x+=2)
		{
			if(isPrime(x))
				{
					if(x > counter)
						{
							printf("%lld\n", x);
							counter += 100000;
						}

					list<string> l = eligibles(x);
					for(list<string>::const_iterator i = l.begin();
						i != l.end();
						++i)
						{
							list<long long> pf = primeFamily(*i);
							if(pf.size() >= 8)
								{
									printList(pf);
									printf("\n");
									return 0;
								}
						}
				}
		}
	return 1;
}

