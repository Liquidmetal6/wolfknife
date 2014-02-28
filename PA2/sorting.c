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
  // Node* ln=NULL;
  // Node* temp=NULL;
  Node* HeadNode=NULL;
  int scancheck = 0;
  long int x = 0;

//Validity Check, return 0 if unsuccesful
  if(fptr ==NULL)
    {printf("File didnt open!"); return NULL;}

  //scancheck = fscanf(fptr, "%li", &x);
  //HeadNode = Tie_Nodes(HeadNode, 0);

  while(fscanf(fptr, "%li", &x)!=-1)
    {
     HeadNode=  Tie_Nodes(HeadNode,x);
     
    }
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
     
      //  if(temp->value!=-1)
      //	{     
	  saveprintcount++;
	  fprintf(fptr, "%li\n", temp->value);
	  //	}
      temp = temp->next;
    }
  return(saveprintcount);
}




////////////////////////////////////////////////////////////////////////
List * List_Create(Node * ln)
{
  List * hold = malloc(sizeof(Node));
  hold->node = ln;
  hold->next = NULL;
  hold->prev = NULL
    return(hold);
}

List_Tie(Node* hold,List* listhold)
{


}



/////////////////////////////
Node* Shell_Sort(Node *list)
{

  int k=1;
  int p=0;
  int gap = 0;
  int seqcount = 0;
  int Size = 0;
  // int j=0;
  // int i = 0;
  //  int temp = 0;
  
  //While k is less then size, k grows at a *3 rate and p increments
  while(k<Size)
   
    { {
      k=k*3;
      p=p+1;
    }
  k=k/3;//Bring k and back from the overshoot
  p=p-1;
  
  while(p>=0)//Start of the while loop, it restarts up here
   {
     
   }
  gap = (gap/3)*2 ;//bring the gap down
  seqcount = seqcount-1;
}while(seqcount>=0);
k = k/3;
p=p-1;


 
return 0;

}
