/* Problem 31 */

/* In England the currency is made up of pound, £, and pence, p, and there are eight coins in general circulation:
 * 
 * 1p, 2p, 5p, 10p, 20p, 50p, £1 (100p) and £2 (200p).
 * It is possible to make £2 in the following way:
 * 
 * 1£1 + 150p + 220p + 15p + 12p + 31p
 * How many different ways can £2 be made using any number of coins?
 */

#include <stdio.h>

int main()
{
  int p1;
  int p2;
  int p5;
  int p10;
  int p20;
  int p50;
  int p100;
  int p200;
  int count = 0;
  
  for(p1=0; p1<=200; ++p1)
    for(p2=0; p2<=100; ++p2)
      for(p5=0; p5<=40; ++p5)
	for(p10=0; p10<=20; ++p10)
	  for(p20=0; p20<=10; ++p20)
	    for(p50=0; p50<=4; ++p50)
	      for(p100=0; p100<=2; ++p100)
		for(p200=0; p200<=1; ++p200)
		  {
		    if(1*p1 + 
		       2*p2 +
		       5*p5 +
		       10*p10 +
		       20*p20 +
		       50*p50 +
		       100*p100 +
		       200*p200 == 200)
		      {
			++count;
		      }
		  }
  
  printf("answer = %d\n", count);
  
  return 0;
}
