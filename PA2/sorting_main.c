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

 Node* ln;

  //Function Calls//
ln= Load_File(argv[1]);
 int printthingy = 0;
 printthingy = Print_Node(ln);



 //End Function Calls 
 return 0;
}

