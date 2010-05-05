// problem 23
// 
// A perfect number is a number for which the sum of its proper divisors is exactly equal to the number. For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.
// 
// A number n is called deficient if the sum of its proper divisors is less than n and it is called abundant if this sum exceeds n.
// 
// As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that can be written as the sum of two abundant numbers is 24. By mathematical analysis, it can be shown that all integers greater than 28123 can be written as the sum of two abundant numbers. However, this upper limit cannot be reduced any further by analysis even though it is known that the greatest number that cannot be expressed as the sum of two abundant numbers is less than this limit.
// 
// Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

inline bool isAbundant(const int n)
{
	int factor_sum = 1;

	for(int i=2;
		i<=sqrt(n);
		++i)
		{
			if(n%i == 0)
				{
					factor_sum += i;
					if(sqrt(n) != i)
						{
							factor_sum += n/i;
						}
					
					if(factor_sum > n)
						{
							return true;
						}
				}
		}
	return factor_sum > n;
}


void printVector(const vector<int> &v)
{
	for(vector<int>::const_iterator i = v.begin();
		i != v.end();
		++i)
		{
			cout << *i << " ";
		}
	cout << endl;
}

int main()
{
	vector<int> abundant_numbers;

	for(int i=12;
		i < 28123;
		++i)
		{
			if(isAbundant(i))
				{
					abundant_numbers.push_back(i);
				}
		}

	vector<int> abundant_number_sums;
	for(unsigned int i=0; i<abundant_numbers.size(); ++i)
		{
			for(unsigned int j=i; j<abundant_numbers.size(); ++j)
				{
					if((abundant_numbers[i]+abundant_numbers[j])<28123)
						{
							abundant_number_sums.push_back(abundant_numbers[i]+abundant_numbers[j]);
						}
				}
		}

	std::sort(abundant_number_sums.begin(), abundant_number_sums.end());

	long long running_total = 0;
	vector<int>::const_iterator i = abundant_number_sums.begin();
	for(int j=1; j<28123; ++j)
		{
			while(*i < j)
				{
					++i;
				}

			if(*i != j)
				{
					running_total += j;
				}
		}

	cout << "answer: " << running_total << endl;
	return 0;
}
