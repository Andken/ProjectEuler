/*A permutation is an ordered arrangement of objects. For example, 3124 is one possible permutation of the digits 1, 2, 3 and 4. If all of the permutations are listed numerically or alphabetically, we call it lexicographic order. The lexicographic permutations of 0, 1 and 2 are:
 *
 *012   021   102   120   201   210
 *
 *What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?
 */
#include <stdio.h>

#define MAX_VAL 10

void printVector(const int *v)
{
  int i;
  for(i=0; i< MAX_VAL; ++i)
    {
      printf("%d", v[i]);
    }
  printf("\n");
}


int main()
{
  int w[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int i, j, k, l, temp;
  
  for(i=1; i<1000000; ++i)
    {
      for(j=MAX_VAL-2; j>=0; --j)
	{
	  
	  if(w[j] < w[j+1])
	    {
	      for(l=MAX_VAL-1; l>=0; --l)
		{
		  if(w[j] < w[l])
		    {
		      temp = w[j];
		      w[j] = w[l];
		      w[l] = temp;
		      break;
		    }
		}							
	      
	      for(k=j+1; k<MAX_VAL-((MAX_VAL-(j+1))/2); ++k)
		{
		  temp = w[k];
		  w[k] = w[MAX_VAL-(k-j)];
		  w[MAX_VAL-(k-j)] = temp;
		}
	      break;
	    }
	}
      
    }
  printVector(w);					
  return 0;
}

