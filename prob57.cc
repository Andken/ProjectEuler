#include <stdio.h>
#include <string.h>

typedef unsigned long long uint64_t;

#define MIN(X,Y) ((X) < (Y) ? (X) : (Y))

uint64_t least_common_multiple(const uint64_t a, const uint64_t b)
{
	for(uint64_t i=2; i<=MIN(a,b); ++i)
		{
			if(a%i==0 && b%i==0)
				{
					return i*least_common_multiple(a/i, b/i);
				}
		}
	
	return 1;
}

int length(uint64_t number)
{
	char num[32];
	sprintf(num, "%llu", number);

	return strlen(num);
}

class Fraction
{
public:
	Fraction(uint64_t numerator, uint64_t denominator=1) :
//		m_numerator		(numerator/least_common_multiple(numerator, denominator)),
//		m_denominator	(denominator/least_common_multiple(numerator, denominator))
		m_numerator		(numerator),
		m_denominator	(denominator)
	{}

	void reduce()
	{
		const uint64_t numerator = m_numerator*m_denominator;
  		const uint64_t denominator = m_denominator*m_denominator;
                                                                                                                      
		m_numerator = (numerator/least_common_multiple(numerator, denominator));
		m_denominator = (denominator/least_common_multiple(numerator, denominator));
	}

	void add(const Fraction &f)
	{
//		const uint64_t m_numerator = m_numerator*f.m_denominator + f.m_numerator*m_denominator;
//		const uint64_t m_denominator = m_denominator*f.m_denominator;
//
//		m_numerator = (numerator/least_common_multiple(numerator, denominator));
//		m_denominator = (denominator/least_common_multiple(numerator, denominator));

		m_numerator = m_numerator*f.m_denominator + f.m_numerator*m_denominator;
		m_denominator = m_denominator*f.m_denominator;
	}

	void invert()
	{
		const uint64_t temp = m_numerator;
		m_numerator = m_denominator;
		m_denominator = temp;
	}

	void print() const
	{
		printf("%llu/%llu\n", m_numerator, m_denominator);
	}

	bool isMagic() const
	{
		// the length of digits in the numerator is greater than the number of digits in the denominator
		Fraction one(1);
		one.add(*this);
		//		one.reduce();
		return length(one.m_numerator) > length(one.m_denominator);
	}

	uint64_t m_numerator;
	uint64_t m_denominator;
};

int main()
{
	const int ITERATIONS = 1000;

	int num_digits_greater_than_denom_digits = 0;

	Fraction working(1,2);
	for(int i = 0; i<=ITERATIONS; ++i)
		{
			if(i%25 == 0) printf("%d\n", i);

			Fraction f(2,1);
			working.add(f);
			working.invert();

			if(working.isMagic())
				{
					++num_digits_greater_than_denom_digits;
				}

			Fraction one(1);
			one.add(working);
			one.print();

			if(i==30)
				{
					printf("HERE\n");
					one.print();
					one.reduce();
					one.print();
				}

//			one.reduce();
//			one.print();
		}


	printf("answer: %d\n", num_digits_greater_than_denom_digits);
	
	return 0;
}
