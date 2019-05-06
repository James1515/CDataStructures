//=======================================
// Author: James Ortiz
// File: oneDim.c
// Description: The use of a
// one-dimensional array in C.
//=======================================

#include <stdio.h>

#define NUMELTS 100

void aver()
{
  int num[NUMELTS]; /* array of numbers */
  int i;
  long int total;   //Holds total value
  float avg;   //Average of the numbers
  float diff;  //Diff. between each number and the average

  total = 0;

  for(i = 0; i < NUMELTS; i++)
    {
      //Read the numbers into the array and add them:

      scanf("%d", &num[i]);
      total += num[i];
    } //end for

  avg = total/NUMELTS;

  printf("\nnumber  |   difference"); //Compute the average:

  //print each number and the difference:

  for(i = 0; i < NUMELTS; i++)
    {
      diff = num[i] - avg;
      printf("\n %d    %f", num[i], diff);
    }

  printf("\naverage is: %f\n", avg);

  return;

}//end aver function:

//MAIN
int main(void)
{
  aver();
  return 0;
}
