//
// A Simple C program to introduce a linked list
//
//
//

#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
};



int main(void)
{
  //Create three nodes:
  struct Node* head = NULL;
  struct Node* second = NULL;
  struct Node* third = NULL;
  struct Node* fourth = NULL;


  
  //Allocate Storage on heap for all three nodes:
  head = (struct Node*)malloc(sizeof(struct Node));
  second  = (struct Node*)malloc(sizeof(struct Node));
  third = (struct Node*)malloc(sizeof(struct Node));
  fourth = (struct Node *)malloc(sizeof(struct Node));
  
  head->data = 5; //Assign data to 5 on head of node:
  head->next = second; //Point to the second node

  second->data = 10; //Assign data to 10 on second node
  second->next = third; //Point to the next node (third)

  third->data = 15; //Assign data to 15 on third node:
  third->next = fourth; //Point to fourth node

  fourth->data = 20;   //Assign data to 20 on the fourth node:
  fourth->next = NULL; //Point to NULL - Assignment is now completed.

  printf("( ");
  
  while(head != NULL) //While the head of the Linked list isnt NULL
    {
      //Display value of the data in the node
      //Traverse linked-list from the Head...
      
      printf("%d ", head->data);
      
      //Point to the next node
      head = head->next;
      
    }

  printf(")");

  
  return 0;
}





  
