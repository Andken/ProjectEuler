#include <stdio.h>
#include <math.h>
#include <list>
#include <string.h>

using namespace std;

int digits(double num)
{
	char decimal[512];
	sprintf(decimal, "%lf", num);
	if(strcmp(decimal, "inf") == 0) return -1;

	char *pch = strtok (decimal,".");
	return strlen(decimal);
}

//long long power(int base, int exponent)
//{
//	long long result = 1;
//	for(int i=0; i<exponent; ++i)
//		{
//			const long long prev_result = result;
//			result *= base;
//			if(prev_result > result && base != 0) return -1;
//		}
//
//	return result;
//}

int main()
{
	list<long long>l;
	for(int n=0; digits(pow(2,n)) != -1; ++n)
		{
//			printf("pow(2,%d): %lf\n", n, pow(2,n));
//			printf("digits(pow(%d,%d)) : %d     n : %d     pow(%d,%d): %lf\n", 0, n, digits(pow(0,n)), n, 0, n, pow(0,n));
			for(int x=0; x<10; ++x)
				{
					//					printf("digits(pow(%d,%d)) : %d     n : %d     pow(%d,%d): %lf\n", x, n, digits(pow(x,n)), n, x, n, pow(x,n));
					if(digits(pow(x,n)) == n) 
						{
							l.push_back(pow(x,n));
							printf("x: %d, n: %d\n\tdigits(pow(x,n)): %d\n\tpow(x,n): %lf\n", x, n, digits(pow(x,n)), pow(x,n));
						}
				}
		}
	
	l.sort();
	l.unique();

	printf("answer: %d\n", l.size());

	return 0;
}
