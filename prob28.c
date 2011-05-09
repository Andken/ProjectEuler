// Problem 28
// 
// Starting with the number 1 and moving to the right in a clockwise direction a 5 by 5 spiral is formed as follows:
// 
// 21 22 23 24 25
// 20  7  8  9 10
// 19  6  1  2 11
// 18  5  4  3 12
// 17 16 15 14 13
// 
// It can be verified that the sum of the numbers on the diagonals is 101.
// 
// What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral formed in the same way?



#include <stdio.h>

#define SPIRAL_SIZE 1001

enum
  {
    RIGHT,
    LEFT,
    UP,
    DOWN
  };

int spiral[SPIRAL_SIZE][SPIRAL_SIZE];

void print_spiral()
{
  int i;
  int j;
  printf("\n");

  for(i=0; i<SPIRAL_SIZE; ++i)
    {
      for(j=0; j<SPIRAL_SIZE; ++j)
	printf("%03d ", spiral[j][i]);  

      printf("\n");
    }
}

int main()
{
  int i, j;

  for(i=0; i<SPIRAL_SIZE; ++i)
    for(j=0; j<SPIRAL_SIZE; ++j)
      spiral[i][j] = -1;
  

  int x = SPIRAL_SIZE/2;
  int y = SPIRAL_SIZE/2;
  int cur_value = 1;
  int last_direction = UP;

  while(cur_value <= SPIRAL_SIZE*SPIRAL_SIZE)
    {      
      spiral[x][y] = cur_value;
      //      print_spiral(spiral);

      switch(last_direction)
	{
	case UP:
	  if(spiral[x+1][y] == -1)
	    {
	      ++x;
	      last_direction = RIGHT;
	    }
	  else
	    {
	      --y;
	      last_direction = UP;
	    }
	  break;
	case DOWN:
	  if(spiral[x-1][y] == -1)
	    {
	      --x;
	      last_direction = LEFT;
	    }
	  else
	    {
	      ++y;
	      last_direction = DOWN;
	    }
	  break;
	case RIGHT:
	  if(spiral[x][y+1] == -1)
	    {
	      ++y;
	      last_direction = DOWN;
	    }
	  else
	    {
	      ++x;
	      last_direction = RIGHT;
	    }
	  break;
	case LEFT:
	  if(spiral[x][y-1] == -1)
	    {
	      --y;
	      last_direction = UP;
	    }
	  else
	    {
	      --x;
	      last_direction = LEFT;
	    }
	  break;
	default:
	  printf("ERROR\n");
	  break;
	}

      ++cur_value;
    }


  // add up diagonals
  int total = 0;
  for(i=0; i<SPIRAL_SIZE; ++i)
    total += spiral[i][i];

  for(i=0; i<SPIRAL_SIZE; ++i)
    total += spiral[i][SPIRAL_SIZE-i-1];


  printf("%d\n", total-1);

  return 0;
}
