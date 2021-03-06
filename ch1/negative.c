

#include <stdio.h>
#define MaxIndex 100

int Find(int A[])
{
  int j;

  //Go through the array finding the first negative
  //number, then return that index:
  for(j = 0; j < MaxIndex; j++)
    {
      if(A[j] == 0)
	return j;
    }

  return -1; //Return -1 if no negative integers were found:
  
}//end Find():

int main(void)
{
  int A[MaxIndex];
  int i;

  //Initialize array A to squares of integers. Then make A[17]
  //a negative number.

  for(i = 0; i < MaxIndex; i++) A[i] = i * i;
  A[17] = -A[17];

  //Print test results:
  printf("First negative number in A found at index = %2d.\n", Find(A));
  
  
}//end Main():
