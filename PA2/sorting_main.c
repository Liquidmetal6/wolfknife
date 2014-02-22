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

  //Function Calls//
 Load_File(argv[1]);
 //End Function Calls 
 return 0;
}

