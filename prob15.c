/* Problem 15
 * Starting in the top left corner of a 22 grid, there are 6 routes (without backtracking) to the bottom right corner.
 * 
 * 
 * How many routes are there through a 2020 grid?
 */

#include <stdio.h>

#define GRID_SIZE 20

int main()
{
  long long grid[GRID_SIZE+1][GRID_SIZE+1];
  int i,j;
  for(i=0; i<GRID_SIZE+1; ++i)
    {
      grid[i][GRID_SIZE] = 1;
      grid[GRID_SIZE][i] = 1;
    }

  for(i=GRID_SIZE-1; i>=0; --i)
    {
      for(j=GRID_SIZE-1; j>=0; --j)
	{
	  grid[i][j]=grid[i][j+1] + grid[i+1][j];
	}
    }

  for(i=0; i<=GRID_SIZE; ++i)
    {
      for(j=0; j<=GRID_SIZE; ++j)
	{
	  printf("%020lld ", grid[i][j]);
	}
      printf("\n");
    }

  printf("\nanswer=%lld\n", grid[0][0]);

  return 0;
}



