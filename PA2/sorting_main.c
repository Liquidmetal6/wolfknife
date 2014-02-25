#include"sortingheaders.h"
#include <stdio.h>
#include<stdlib.h>
#include<time.h>




int main(int argc,char **argv)
{
  //Validity Check///
  if(argc!=3) {printf("Error, check usage. Must have ./proj2 input.txt output.txt");return(0);}
  //End Validity Check//

  //Stack Declarations
  Node* ln;
  long int saveprintcount = -1;
  
  clock_t startload_t,endload_t;
  clock_t startsave_t, endsave_t;
  clock_t startsort_t, endsort_t;

    long double load_total;
    long double save_total;
  long double sort_total;
  long double IOtime ;

  //Function Calls//

  //Load file targets ln with timing
  startload_t = clock();
  ln= Load_File(argv[1]);
  endload_t = clock();

  //Save file targets savepprintcount with timing
  startsave_t = clock();
  saveprintcount = Save_File(argv[2], ln);
  endsave_t = clock();

  //Calcs load total
  load_total= (long double)(endload_t-startload_t)  / (long double)(CLOCKS_PER_SEC);  

  //calcs save total
  save_total= (long double)(endsave_t - startsave_t) / (long double)(CLOCKS_PER_SEC);

  //sum of load and save is total IO time
  IOtime= load_total+save_total;

  //print the IO time
  printf("I/O Time:    %Le\n",IOtime);
 //End Function Calls 
  return 0;
}

