/* Problem 33 */

/* The fraction 49/98 is a curious fraction, as an inexperienced mathematician in attempting to simplify it may incorrectly believe that 49/98 = 4/8, which is correct, is obtained by cancelling the 9s.
 * 
 * We shall consider fractions like, 30/50 = 3/5, to be trivial examples.
 * 
 * There are exactly four non-trivial examples of this type of fraction, less than one in value, and containing two digits in the numerator and denominator.
 * 
 * If the product of these four fractions is given in its lowest common terms, find the value of the denominator.
 */
 
#include <stdio.h>

inline void getDigits(const int number, int digits[])
{
  digits[0] = number/10;
  digits[1] = number%10;
}

inline void dumbCancelResult(const int num_digits[], const int denom_digits[], int *canceled_num, int *canceled_denom)
{
  if(num_digits[0] == denom_digits[0] && num_digits[0] != 0)
    {
      *canceled_num = num_digits[1];
      *canceled_denom = denom_digits[1];
    }
  else if(num_digits[0] == denom_digits[1] && num_digits[0] != 0)
    {
      *canceled_num = num_digits[1];
      *canceled_denom = denom_digits[0];
    }
  else if(num_digits[1] == denom_digits[0] && num_digits[1] != 0)
    {
      *canceled_num = num_digits[0];
      *canceled_denom = denom_digits[1];
    }
  else if(num_digits[1] == denom_digits[1] && num_digits[1] != 0)
    {
      *canceled_num = num_digits[0];
      *canceled_denom = denom_digits[0];
    }
  else
    {
      *canceled_num = 1;
      *canceled_denom = 1;
    }
}

int main()
{
  int num, denom;
  int canceled_denom = 0;
  int canceled_num = 0;
  int num_digits[2];
  int denom_digits[2];
  int num_answer = 1;
  int denom_answer = 1;
  
  for(num = 10; num<=99; ++num)
    {
      for(denom = num+1; denom<99; ++denom)
	{
	  getDigits(num, num_digits);
	  getDigits(denom, denom_digits);
	  
	  dumbCancelResult(num_digits, denom_digits, &canceled_num, &canceled_denom);
	  if((float)num/(float)denom == (float)canceled_num/(float)canceled_denom)
	    {
	      printf("%d/%d (%d/%d)\n", num, denom, canceled_num, canceled_denom);
	      num_answer *= num;
	      denom_answer *= denom;
	    }
	}
    }
  
  printf("result: %d/%d\n", num_answer, denom_answer);
  printf("answer: %d\n", denom_answer/num_answer);
  
  return 0;
}
