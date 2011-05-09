#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

typedef unsigned long long uint64_t;

uint64_t nextInChain(uint64_t num)
{
	char number[32];
	sprintf(number, "%llu", num);

	uint64_t next_in_chain = 0;
	for(int i=0; i<strlen(number); ++i)
		{
			const int digit = number[i]-48;
			next_in_chain += (digit*digit);
		}
	
	return next_in_chain;
}


int main()
{
	int num_ending_in_89 = 0;
	for(int i=1; i<10000000; ++i)
		{
			uint64_t working_num = i;
			while(working_num != 1 && working_num != 89)
				{
					working_num = nextInChain(working_num);
				}
			
			if(working_num == 89)
				{
					++num_ending_in_89;
				}
		}

	printf("answer: %d\n", num_ending_in_89);

	return 0;
}
