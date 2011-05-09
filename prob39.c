/* If p is the perimeter of a right angle triangle with integral length sides, {a,b,c}, there are exactly three solutions for p = 120.
 * 
 * {20,48,52}, {24,45,51}, {30,40,50}
 * 
 * For which value of p  1000, is the number of solutions maximised?
 */

#include <stdio.h>

inline int solutions(const int p)
{
  int num_solutions = 0;
  int i, j;	
  
  for(i=2; i<=p-2; ++i)
    {
      for(j=1; j < i && j <= (p-i)-1; ++j)
	{
	  if((i*i + j*j) == (p-(i+j))*(p-(i+j)))
	    {
	      num_solutions++;
	    }
	}
    }
  
  return num_solutions;
}

int main()
{
  int max = -1;
  int max_perim = 0;
  int p;
  
  for(p = 3; p <=1000; ++p)
    {
      if(max < solutions(p))
	{
	  max = solutions(p);
	  max_perim = p;
	}
    }
  
  printf("max_perim: %d\n", max_perim);
  
  return 0;
}

