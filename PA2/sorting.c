#include"sortingheaders.h"
#include <stdio.h>
#include<stdlib.h>
#include<time.h>

///////////////////////////////
Node* List_Create(long int value,struct node* next);
{
  Node * ln = malloc(sizeof(Node));
  ln->value = value;
  ln->next = NULL;
}

/////////////////////////////////////////////////////////////////////////////
Node* Load_File(char *Filename)
{
  //Open file
  FILE* fptr = fopen(Filename, "r");

  //Validity Check
  if(fptr ==NULL)
    {printf("File didnt open!"); return NULL);



 
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
