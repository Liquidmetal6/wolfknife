#include <stdlib.h>
#include <stdio.h>
#include <time.h>

long *Load_File(char *Filename, int *Size);
int Save_File(char *Filename, long *Array, int Size);
void Shell_Insertion_Sort(long *Array, int Size, double *N_Comp, double *N_Move);
void Shell_Selection_Sort(long *Array, int Size, double *N_Comp, double *N_Move);
int Print_Seq(char *Filename, int Size);


int main(int argc,char** argv)
{
  clock_t start_t, end_t,start_tSave,end_tSave;
  clock_t sortI1_t = 0;
  clock_t sortI2_t = 0;
  long double total_tL;
  long double total_tSave;
  long double sort_t;
 long double total_t;
 
  //Check number of inputs
  //  if((argv[0][1])!=5)
  // {
  //   printf("Error, check number of inputs. The usage is i input.txt sequenceoutput.txt sortedoutput.txt \nwhere i is insertion sort and s is selection sort"); 
  //      return 0;
  //  }
 
  //Will be the target for the first value from load
  int Size=0;
 
  //The total number printed by save
  int printcount = 0;

  //The number of sequences printed
  int printseqnumber = 0;

  //The targets for the number of moves and comps
  double N_Move = 0;
  double N_Comp = 0;
 
  //This holds the array that gets read into
  //long *Array;

  //Peforms load, sends it to temparray

  start_t=clock();
  long *Array=Load_File(argv[2], &Size);
  //printf("%li", Array[0]);
  end_t=clock();
  total_tL = (long double)(end_t-start_t)/(long double)CLOCKS_PER_SEC;

  // if argv[1] is i then insertion  
  if((*argv[1])=='i')
  {
    sortI1_t=clock();
    Shell_Insertion_Sort(Array, Size, &N_Comp, &N_Move);
    sortI2_t = clock();
    // sort_t= (long double)(sortI2_t - sortI1_t)/(long double)CLOCKS_PER_SEC;
  }
  
  else
    {
    sortI1_t=clock();
    Shell_Selection_Sort(Array, Size, &N_Comp, &N_Move);
    sortI2_t = clock();
    }
  //If argv[1] is s then selection
  // else if((argv[1])[0]=='s')
  // {
  // Shell_Selection_Sort(Array,Size, &N_Comp, &N_Move);
  // }
 
  //Save the array sorted previously, argv[3] is the filename, start clock, end clock, get total
  sort_t= (long double)(sortI2_t - sortI1_t)/(long double)CLOCKS_PER_SEC;
  start_tSave = clock();
  printcount = Save_File(argv[4],Array, Size);
  end_tSave=clock();
  total_tSave =(long double)(end_tSave -start_tSave)/(long double)CLOCKS_PER_SEC;
  total_t =( total_tL) + (total_tSave);
 
  //Print the sequence used to shell sort, argv[4] is the filename of output
 printseqnumber= Print_Seq(argv[3],Size);
 
  printf("Number of comparisons: %le\n",N_Comp);
  printf("Number of moves: %le\n",N_Move);
  printf("I/O Time:  %Le\n",total_t);
  printf("Sorting time: %Le\n",sort_t);
  free(Array);
  return (0);
    }
