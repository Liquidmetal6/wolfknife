#include"sortingheaders.h"
#include <stdio.h>
#include<stdlib.h>
#include<time.h>

///////////////////////////////
Node* List_Create(Node * ln)
{
  if(ln==NULL)
    { 
   ln = malloc(sizeof(Node));
      ln->value = 0;
      ln->next = NULL;
    }
  return ln;
}

/////////////////////////////////////////////////////////////////////////////
Node* Load_File(char *Filename)
{
  //Open file
  FILE* fptr = fopen(Filename, "r");
  Node* ln=NULL;
  Node* temp=NULL;
  int scancheck = 0;
  long int x = 0;

//Validity Check, return 0 if unsuccesful
  if(fptr ==NULL)
    {printf("File didnt open!"); return 0;}
  //HeadNode = List_Create(ln); 
ln= List_Create(ln);
// HeadNode->next= ln;
  while(!feof(fptr))
    {
      temp = NULL;
      scancheck = fscanf(fptr,"%li",&x);
      if(scancheck ==0){printf("scanf failed"); return 0;}
      ln->value = x;
      ln->next = List_Create(temp);
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
