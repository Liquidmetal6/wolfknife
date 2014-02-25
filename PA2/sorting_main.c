#include"sortingheaders.h"
#include <stdio.h>
#include<stdlib.h>
#include<time.h>




int main(int argc,char **argv)
{
  //Validity Check///
  if(argc!=3)
    { 
      printf("Error, check usage. Must have ./proj2 input.txt output.txt");return(0);}
  //End Validity Check//

  //Stack Declarations
  Node* ln;
  long int saveprintcount = -1;

  //Function Calls//
  ln= Load_File(argv[1]);
  saveprintcount = Save_File(argv[2], ln);
  printf("The number of integers successfully printed was %li\n", saveprintcount);

  /* int printthingy = 0;
     printthingy = Print_Node(ln);
  */


 //End Function Calls 
  return 0;
}

