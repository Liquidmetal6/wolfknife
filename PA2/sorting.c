#include"sortingheaders.h"
#include <stdio.h>
#include<stdlib.h>
#include<time.h>

///////////////////////////////
Node* List_Create(long int value,struct node* next)
{
  Node * ln = malloc(sizeof(Node));
  ln->value = value;
  ln->next = next;
  return ln;
}

/////////////////////////////////////////////////////////////////////////////
Node* Load_File(char *Filename)
{
  //Open file
  FILE* fptr = fopen(Filename, "r");

  //Validity Check, return 0 if unsuccesful
  if(fptr ==NULL)
    {printf("File didnt open!"); return 0;}
    
  //while not at the end of the file, scan into a function that returns a node
  while(!feof(fptr))
    {
      int scanreturn = 0;
      //Leaving off of here, how to fscanf into a linked list?  scanreturn = fscanf(fp,
    }


  return(0);
}






////////////////////////////////////////////////////////

int Save_File(char *Filename, Node* list)
{
  printf("In save, check\n");
  return 0;
}



////////////////////////////////////////////////////////////////////////

Node* Shell_Sort(Node *list)
{
  printf("In shell sort, check!\n");
  return 0;

}
