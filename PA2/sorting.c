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
      //printf("point 5\n");
    }
  return ln;
}


int Print_Node(Node * ln)
{
  if(ln->next!=NULL)
    {
      printf("%li\n", ln->value);
    }
  Print_Node(ln->next);
  return(0);
}

/////////////////////////////////////////////////////////////////////////////


Node* Load_File(char *Filename)
{
  //Open file
  FILE* fptr = fopen(Filename, "r");
  Node* ln=NULL;
  Node* temp=NULL;
  Node* HeadNode=NULL;
  int scancheck = 0;
  long int x = 0;
  printf("point 1");

//Validity Check, return 0 if unsuccesful
  if(fptr ==NULL)
    {printf("File didnt open!"); return NULL;}

//Create the first one. this value will be returned and not modified. Give it a distinctive value
HeadNode = List_Create(ln);
ln= List_Create(ln);
 HeadNode->next = ln;
 HeadNode->value = -1;
 
 printf("point 2\n");
  while(!feof(fptr))
    {
      scancheck = fscanf(fptr,"%li",&x);
      if(scancheck ==0){printf("scanf failed"); return 0;}
      ln->value = x;
      temp = NULL;
      ln->next = List_Create(temp);
      ln = ln->next;    
 }
  /* int printthingy = 0;
  printthingy = Print_Node(HeadNode);
  */
  return(HeadNode);
  }


////////////////////////////////////////////////////////

int Save_File(char *Filename, Node* list)
{
  long int saveprintcount = 0;
  FILE* fptr=fopen(Filename,"w");

  //check if opened
  if(fptr==NULL){printf("File didnt open"); return(0);}
  Node* temp = list->next;

  while(temp!=NULL)
    {
      saveprintcount++;
      fprintf(fptr, "%li\n", temp->value);
      temp = temp->next;
    }
  return(saveprintcount);
  /*
 long int saveprintcount = 0;
  FILE* fptr=fopen(Filename,"w");
  long int *length;
  Node* traverseNode = list;
  int scanreturn = 0;
  length= 0;

  //Check validity of opened file
  if(fptr==NULL){printf("File did not load"); return -1;}


  printf("length is %li", *length);
 
  while(traverseNode!=NULL)
    { 
     scanreturn = fscanf(fptr, "%li",&traverseNode->value);

      if(scanreturn ==0){printf("File did not scan");return 0;}

      traverseNode=traverseNode->next;
    }
  return (-1);
  */
}



////////////////////////////////////////////////////////////////////////

Node* Shell_Sort(Node *list)
{
  printf("In shell sort, check!\n");
  return 0;

}
