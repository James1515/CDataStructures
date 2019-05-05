//========================================================
// Author: James Anthony Ortiz
// File: rationalNum.c
// Description: ADT to reduce rational numbers to 
// their simplest form.
//========================================================

//macros
#define TRUE 1
#define FALSE 0

//ADT Struct
struct rational {

  int numerator;
  int denominator;

};

//Struct ptrs used for functions:

struct rational *inrat;
struct rational *outrat;


void reduce (inrat, outrat)
{
  int a, b, rem;

  if(inrat->numerator > inrat->denominator)
    {
      a = inrat->numerator;
      b = inrat->denominator;

    }//end if
  else
    {
      a = inrat->denominator;
      b = inrat->numerator;

    }//end else

  while(b != 0)
    {
      rem = a %  b;
      a = b;
      b = rem;

    }
  outrat->numerator /= a;
  outrat->denominator /= a;

}//end reduce()




int main(void)
{
  /*
  struct rational r1, r2;
  
  
  printf("Hello and welcome to the program!\n");
  printf("This program is designed to reduce rational numbers.\n");
  printf("Please enter four integer values followed by the space [num1] ... [num4]: ");
  scanf("&d &d &d &d", r1.numerator, r1.denominator, r2.numerator, r2.denominator);

  reduce(r1, r2);

  printf("The reduced values for both fractions is:\n");
  printf("%d / %d %d / %d", r1.numerator, r1.denominator, r2.numerator, r2.denominator);
  
  */
  return 0;
  
}//end MAIN



