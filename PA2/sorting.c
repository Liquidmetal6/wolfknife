#include"sortingheaders.h"
#include <stdio.h>
#include<stdlib.h>
#include<time.h>

#include"sortingheaders.h"
#include <stdio.h>
#include<stdlib.h>
#include<time.h>

///////////////////////////////
Node* Node_Create(long int x)
{
  Node* ln = malloc(sizeof(Node));
  ln->value = x;
  ln->next = NULL;
  return ln;
}

Node* Tie_Nodes(Node* ln, long int x)
{
  Node* newnode = Node_Create(x);
  newnode->next= ln;
  return(newnode);
}


int Print_Node(Node * ln)
{
  if(ln->next!=NULL)
    {
      //  printf("%li\n", ln->value);
    }
  Print_Node(ln->next);
  return(0);
}

/////////////////////////////////////////////////////////////////////////////


Node* Load_File(char *Filename)
{
  //Open file
  FILE* fptr = fopen(Filename, "r");
  // Node* ln=NULL;
  // Node* temp=NULL;
  Node* HeadNode=NULL;
  long int x = 0;

//Validity Check, return 0 if unsuccesful
  if(fptr ==NULL)
    {printf("File didnt open!"); return NULL;}


  while(fscanf(fptr, "%li", &x)!=-1)
    {
     
     HeadNode=  Tie_Nodes(HeadNode,x);
    }
  fclose(fptr);
  return(HeadNode);
}


void memFree(Node* list)
{
  Node* temp =NULL;
  while(list!=NULL)
    {
      temp = list->next;
      list->next =NULL;
      free(list);
      list = temp;
    }
}

////////////////////////////////////////////////////////

int Save_File(char *Filename, Node* list)
{
  long int saveprintcount = 0;
  FILE* fptr=fopen(Filename,"w");

  //check if opened
  if(fptr==NULL){printf("File didnt open"); return(0);}
  Node* temp = list;

  while(temp!=NULL)
    {
      saveprintcount++;
      fprintf(fptr, "%li\n", temp->value);
      temp = temp->next;
    }
  fclose(fptr);
  return(saveprintcount);
}




////////////////////////////////////////////////////////////////////////
/*List * ListofList_Create(Node * ln)
{

  List * hold = malloc(sizeof(Node));
  hold->node = ln;
  hold->next = NULL;
  hold->prev = NULL;
  // printf("%li\n", hold->node->value);
    return(hold);
}

List* CreateLinkedList(Node* NodeHead, List* HeadList)
{
 
  List* NewList = ListofList_Create(NodeHead);
  if(HeadList == NULL)
    {
      return NewList;
    }
  //printf("HeadList is %li\n",HeadList->node->value);

  HeadList->next = NewList;
  NewList->prev = HeadList;
  return(NewList);
  }*/
///////////

Node* traverse(Node* ln,long value)
{
  int i=0;
  for(i=0;i<value; i++)
    {
      ln=ln->next;
    }
  return ln;
}

/////////////////////////////
Node* Shell_Sort(Node *list)
{
  int Size=0;  
  Node* GetSize = list;
  while(GetSize!=NULL)
    {
      if (GetSize->next!=NULL)
	{
	  Size++;
	}
      GetSize = GetSize->next;
    }
  int k=1;
  int p=0;
  int gap = 0;
  int seqcount = 0;
  int j=0;
  int i = 0;
  int temp = 0;
  Node* copy = list;
  //While k is less then size, k grows at a *3 rate and p increments
  while(k<Size)
    {
      k=k*3;
      p=p+1;
    }
  k=k/3;//Bring k and back from the overshoot
  p=p-1;

  while(p>=0)//Start of the while loop, it restarts up here
    {
      //Assign gap to k
      gap=k;
      //seqcount to p
      seqcount = p;
      do{
	//this is the outerloop
	for(j=gap;j<Size+1;j++)
	  {
	    //the first value is the temp smallest
	    temp=traverse(copy,j)->value;
	    i=j;
	       
	    while(i>=gap && ((traverse(list, i-gap))->value)>temp)
	      {//swap in here
		traverse(copy, i)->value  = traverse(copy, i-gap)->value;
		i=i-gap;
	      }
	    traverse(copy, i)->value = temp;
	  }
	gap = (gap/3)*2 ;//bring the gap down
	seqcount = seqcount-1;
      }while(seqcount>=0);
      k = k/3;
      p=p-1;
    }
  return list;

}

  

  

