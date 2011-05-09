// Problem 58
//
//Starting with 1 and spiralling anticlockwise in the following way, a square spiral with side length 7 is formed.
//
//37 36 35 34 33 32 31
//38 17 16 15 14 13 30
//39 18  5  4  3 12 29
//40 19  6  1  2 11 28
//41 20  7  8  9 10 27
//42 21 22 23 24 25 26
//43 44 45 46 47 48 49
//
//  It is interesting to note that the odd squares lie along the bottom right diagonal, but what is more interesting is that 8 out of the 13 numbers lying along both diagonals are prime; that is, a ratio of 8/13  62%.
//
//																							   If one complete new layer is wrapped around the spiral above, a square spiral with side length 9 will be formed. If this process is continued, what is the side length of the square spiral for which the ratio of primes along both diagonals first falls below 10%?
//

#include <stdio.h>
#include <math.h>


static bool isPrime(const unsigned int n)
{
  for(unsigned int i=3; i<=ceil(sqrt(n)); i+=2)
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
  unsigned int num_primes = 8;

  unsigned int ne=31;
  unsigned int ne_inc=26;

  unsigned int nw=37;
  unsigned int nw_inc=28;

  unsigned int sw=43;
  unsigned int sw_inc=30;

  unsigned int se=49;
  unsigned int se_inc=32;

  unsigned int side_length = 7;
  
  while((float)num_primes/(float)((side_length*2)-1) > 0.10)
    {
      side_length+=2;
      
      ne+=ne_inc;
      if(isPrime(ne)) ++num_primes;
      ne_inc+=8;
      
      nw+=nw_inc;
      if(isPrime(nw)) ++num_primes;
      nw_inc+=8;
      
      sw+=sw_inc;
      if(isPrime(sw)) ++num_primes;
      sw_inc+=8;
      
      se+=se_inc;
      if(isPrime(se)) ++num_primes;
      se_inc+=8;
      
      //      printf("%f\n", (float)num_primes/(float)((side_length*2)-1));
    }
  
  printf("answer: %d\n", side_length);

  return 0;
}
