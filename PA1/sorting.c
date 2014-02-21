#include <stdio.h>
#include <stdlib.h>
#include<time.h>


////////////////////////////////////
long *Load_File(char *Filename, int *Size)
{
  //Open the file and assign as fp
  FILE* fp = fopen(Filename,"r");

  //Target for success of fscanf
  int scanreturn = 0;
  //if 0 do nothing 
  if(fp == NULL)
    {
      return(0);
    }

  int counter = 0;
  //Scan first line into Size and scanreturn indicates success
  scanreturn = fscanf(fp,"%i\n",Size);

  //Check return, if 0 then return
  if(scanreturn ==0)
    {
      return 0;
    } 

 //malloc for array the size of long * *size
  long * Array=malloc(sizeof(long)*(*Size));

  //for counter to the length
  for(counter = 0; counter<*Size; counter++)
    {     
      scanreturn = fscanf(fp,"%li",&Array[counter]);
    } 
  fclose(fp);//Close the file

   return(Array);
}
////////////////////////////////////////////////////////////////

int Save_File(char *Filename, long *Array, int Size)
{
  //Open the file and assign handle to fp
  FILE* fp = fopen(Filename,"w");

  //If Null do nothing  
if(fp ==NULL)
    {
      return 0;
    }

//Printcount will increment each succesful array write
  int printcount = 0; 

  //i is counter for the for loop, to print 
 int i = 0;

 //First fprintf will print the size to the first line of the file
  fprintf(fp,"%d\n",Size);
  
  //For loop to print each line
for(i=0;i<Size;i++)
    {
      fprintf(fp, "%li\n",Array[i]);
      printcount++;
    }

  fclose(fp);
  
  return (printcount);
}

//////////////////////////////////////
void Shell_Insertion_Sort(long *Array, int Size, double *N_Comp, double *N_Move)
{
  int k=1;
  int p=0;
  int gap = 0;
  int seqcount = 0;
  int j=0;
  int i = 0;
  int temp = 0;

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
	for(j=gap;j<Size;j++)
	  {
	    //the first value is the temp smallest
	    temp=Array[j];(*N_Move)++;
	    i=j;
	    (*N_Comp)+=2;    
	    while(i>=gap && Array[i-gap]>temp)
	      {//swap in here
		Array[i] = Array[i-gap];(*N_Move)++;
		i=i-gap;
	      }
	    Array[i] = temp;(*N_Move)++;
	  }
	gap = (gap/3)*2 ;//bring the gap down
	seqcount = seqcount-1;
      }while(seqcount>=0);
      k = k/3;
      p=p-1;
    }

  
}
//////////////////////////
void Shell_Selection_Sort(long *Array, int Size, double *N_Comp, double *N_Move)
{
 
  int k=1;
  int p=0;
  int gap = 0;
  int seqcount = 0;
  int temp = 0;
  int y = 0;
  int q = 0;
 
  while(k<Size)
    {
      k=k*3;
      p=p+1;
    }
  k=k/3;
  p=p-1;
  while(p>=0)
    {
      gap=k;
      seqcount = p;

      do{

	for(y=0;y<Size;y++)
	  {	  
	    int min = y;(*N_Move)++;
	    temp = Array[y];(*N_Move)++;
	    for(q = y+gap;q<Size;q+=gap)
	      {
		if(Array[q] <Array[min])(*N_Comp)++;
		  {
		    min = q;(*N_Move)++;
		  }
	      }
	    if (min!=q)(*N_Comp)++;
	      {
		Array[y] = Array[min];
		Array[min] = temp;
	      }
	  }
	gap = gap/3*2;
	seqcount=seqcount-1;
      }while(seqcount>0);
      k = k/3;
      p=p-1;
      
    }
 
  return;
}
/////////////////////////////////
int Print_Seq(char *Filename, int Size)
{
  FILE* fp = fopen(Filename, "w");
  int k=1;
  int gap = 0;
  int p =0;
  int initial = 1;
  while(k<Size)
    {
      k=k*3;
      p=p+1;
    }

  k=k/3;
  p=p-1;
  int bigsize = 0;//This will be the size
  int out = 0;
  bigsize = (p+1)*(p+2) /2;//This calculates the size
  fprintf(fp, "%d\n", bigsize);//prints the size

  fprintf(fp,"%d\n",initial);//prints 1
  gap=1;//starts out the gap
  out = 0;
  int m =0;
  for( out = 0;out<p; out++)//outerloop
    {
      m++;
      gap = gap*2;
      int sequence = 0;
      sequence = gap;
      fprintf(fp, "%d\n", gap);
      int in = 0;
      for(in=1; in<m+1;in++)
	{
	  sequence = (sequence*3)/2;
	  fprintf(fp, "%d\n",sequence);//this line prints each sequence
	}
    }
  
  fclose(fp);
  return bigsize;
}






 
