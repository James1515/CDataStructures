//==============================================
// Author: James Anthony Ortiz
// File: airport.c
// Description: Examining a linked list in C
// that takes in Airport Codes.
//==============================================

#include <string.h>
#include <stdlib.h>
#include <stdio.h>


//Holds value of the AirportCode:
typedef char AirportCode[4];

typedef struct NodeTag{
  AirportCode Airport;
  struct NodeTag *Link;
}NodeType;

NodeType *N, *L;

NodeType *ListSearch(char *A, NodeType *L)
{
  NodeType *N;
  
  /* Initialization */

  N = L;
  
  /* While N points to a non null node on list L */

  /* Examine the node to which N points */

  while (N != NULL)
    {
      if(strcmp(N->Airport, A) == 0) //if N's airport == A
	{
	  return N; //Return the node pointer in N
	}
      else  //otherwise
	{
	  N = N->Link; //Advance N to the next node on the list
	}
    }

  return N; //Return NULL if no nodes Airport == A

}// ListSearch

void DeleteLastNode(NodeType **L)
{
  //Note: **L is the address of the variable L, 
  //whose value points to the first node of list L

  NodeType *PreviousNode, *CurrentNode;
  
  if(*L != NULL)
    {
      if((*L)->Link == NULL)
	{
	  free(*L);
	  *L = NULL;
	}
      else{

	//Initialize a pair of pointers, (PreviousNode, CurrentNode)
	//To point to the first and second nodes

	PreviousNode = *L;
	CurrentNode = (*L)->Link;
	
	//Advance the pointer pair along L until CurrentNode
	//points to the last node.

	while(CurrentNode->Link != NULL)
	  {
	    PreviousNode = CurrentNode;
	    CurrentNode = CurrentNode->Link;
	  }

	//Now PreviousNode points to the next-to-last nodeon the list
	//and CurrentNode points to the last node on the list.

	PreviousNode->Link = NULL; //last node gets null link.
	free(CurrentNode);         //recycle storeage for discarded node.

      }
    }
}//end DeleteLastNode

void InsertNewLastNode(char *A, NodeType **L)
{

  //Expect **L to hold the address of a variable L 
  //Containing the pointer to the first node of the 
  //list.

  NodeType *N, *P;
  
  //Allocate a new node N with Airport  == A and Link == NULL

  N = (NodeType *)malloc(sizeof(NodeType));
  strcpy(N->Airport, A);
  N->Link = NULL;
  
  
  if(*L == NULL)
    {
      *L = N; //Let N become the new value for L:

    }else
    {
      //Locate the last node of list L, using 
      //pointer variable P.

      P = *L;
      
      while(P->Link != NULL) P = P->Link;

      //Finally, link node N onto the end of the list.

      P->Link = N;

    }
}//end InsertNewLastNode()

void PrintList(NodeType *L)
{

  //N points to sucessive nodes on list L:

  NodeType *N;
  
  //First, print a left parenthesis:
  printf("(");
  
  //Let N start by pointing to the first node 
  //on the list L.

  N = L;

  //Provided N doesn't point to an empty node, print N's 
  //Airport and advance N to point to the next node on the list.

  while(N != NULL)
    {
      printf("%s", N->Airport);
      N = N->Link;
      if(N != NULL) printf(",");

    }

  //Finally, print a closing right parenthesis:
  printf(")\n");

}//end PrintList()

//Main - Driver for above functions:

//Here, insert the typedefs and functions above for the 
//types: AirportCode, and NodeType and the functions InsertNewLastNode
//InsertNewSecondNode, DeleteLastNode, and PrintLast.

//Then, declare a new pointer variable L, as shown below:

int main(void)
{

  NodeType *L;

  //First construct the list L = (DUS, ORD, SAN) and print it:

  L = NULL;
  
  //Insert a new last node in L with airport code DUS:
  InsertNewLastNode("DUS", &L);

  //Insert a new last node in L with airport code "ORD":
  InsertNewLastNode("ORD", &L);
  
  //Insert a new last node in L with airport code "SAN":
  InsertNewLastNode("SAN", &L);

  //Now print the list, to show what it looks like changing it:
  PrintList(L);
  
  //Then insert an new second node with the airport code "BRU":
  

  InsertNewLastNode("BRU", &L);

  PrintList(L);

  //Delete the last node of the list:

  DeleteLastNode(&L);

  //Finally print the shortened list:

  PrintList(L);

  return 0;
}
