//--------------------------------------------------
// Dr. Art Hanna
// Problem #5
// Problem5.c
//--------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include <string.h>

#include "C:\Users\am201\OneDrive\Documents\CS2315\Random.h"

//--------------------------------------------------
int main()
//--------------------------------------------------
{
   void BuildRandomArray(int A[],const int n);
   void CopyArray(int copyA[],const int A[],const int n);
   void DisplayArraySlice(const char label[],const int A[],const int n,const int L,const int R);
   int NumberOfInversions(const int A[],const int n,bool (*AreInverted)(const int LHS,const int RHS));
   void DoBubbleSort(int A[],const int n,
                     bool (*ShouldSwap)(const int LHS,const int RHS),
                     int *numberCompares,
                     int *numberMoves);
   void DoSelectionSort(int *A,const int n,
                        bool (*ShouldSelect)(const int LHS,const int RHS),
                        int *numberCompares,
                        int *numberMoves);
   void DoInsertionSort(int *A,const int n,
                        bool (*ShouldInsert)(const int LHS,const int RHS),
                        int *numberCompares,
                        int *numberMoves);
   bool Ascending(const int LHS,const int RHS);
   bool Descending(const int LHS,const int RHS);

   int n;

   SetRandomSeed();
   printf("n? ");
   while ( scanf("%d",&n) != EOF )
   {
      int *A     = (int *) malloc(sizeof(int)*n);
      int copyA[n];
      int numberCompares;
      int numberMoves;

      BuildRandomArray(A,n);
      DisplayArraySlice("Unsorted",A,n,0,n-1);
      printf("# of  ascending-order inversions is %d\n",
         NumberOfInversions(A,n,Ascending));
      printf("# of descending-order inversions is %d\n",
         NumberOfInversions(A,n,Descending));

      CopyArray(copyA,A,n);
      DoBubbleSort(copyA,n,Ascending,&numberCompares,&numberMoves);
      DisplayArraySlice("Bubble Sort (Ascending)",copyA,n,0,n-1);
      printf("# of compares is %d\n",numberCompares);
      printf("# of moves    is %d\n",numberMoves);
      printf("# of  ascending-order inversions is %d\n",
        NumberOfInversions(copyA,n,Ascending));

      CopyArray(copyA,A,n);
      DoBubbleSort(copyA,n,Descending,&numberCompares,&numberMoves);
      DisplayArraySlice("Bubble Sort (Descending)",copyA,n,0,n-1);
      printf("# of compares is %d\n",numberCompares);
      printf("# of moves    is %d\n",numberMoves);
      printf("# of descending-order inversions is %d\n",
         NumberOfInversions(copyA,n,Descending));

      CopyArray(copyA,A,n);
      DoSelectionSort(copyA,n,Ascending,&numberCompares,&numberMoves);
      DisplayArraySlice("Selection Sort (Ascending)",copyA,n,0,n-1);
      printf("# of compares is %d\n",numberCompares);
      printf("# of moves    is %d\n",numberMoves);
      printf("# of  ascending-order inversions is %d\n",
         NumberOfInversions(copyA,n,Ascending));

      CopyArray(copyA,A,n);
      DoSelectionSort(copyA,n,Descending,&numberCompares,&numberMoves);
      DisplayArraySlice("Selection Sort (Descending)",copyA,n,0,n-1);
      printf("# of compares is %d\n",numberCompares);
      printf("# of moves    is %d\n",numberMoves);
      printf("# of descending-order inversions is %d\n",
         NumberOfInversions(copyA,n,Descending));

      CopyArray(copyA,A,n);
      DoInsertionSort(copyA,n,Ascending,&numberCompares,&numberMoves);
      DisplayArraySlice("Insertion Sort (Ascending)",copyA,n,0,n-1);
      printf("# of compares is %d\n",numberCompares);
      printf("# of moves    is %d\n",numberMoves);
      printf("# of  ascending-order inversions is %d\n",
         NumberOfInversions(copyA,n,Ascending));

      CopyArray(copyA,A,n);
      DoInsertionSort(copyA,n,Descending,&numberCompares,&numberMoves);
      DisplayArraySlice("Insertion Sort (Descending)",copyA,n,0,n-1);
      printf("# of compares is %d\n",numberCompares);
      printf("# of moves    is %d\n",numberMoves);
      printf("# of descending-order inversions is %d\n",
         NumberOfInversions(copyA,n,Descending));

      free(A);
      printf("\nn? ");
   }

   system("PAUSE");
   return( 0 );
}

//--------------------------------------------------
void BuildRandomArray(int A[],const int n)
//--------------------------------------------------
{
   int i;

   for (i = 0; i <= n-1; i++)
      A[i] = RandomInt(1,10*n);
}

//--------------------------------------------------
void CopyArray(int copyA[],const int A[],const int n)
//--------------------------------------------------
{
   int i;

// for (int i = 0; i <= n-1; i++)
   i = 0;
TOL1:
   if ( !(i <= n-1) ) goto BOL1;
   copyA[i] = A[i];
   i++;
   goto TOL1;
BOL1:
   ; // Do nothing
}

//--------------------------------------------------
void DisplayArraySlice(const char label[],const int A[],const int n,const int L,const int R)
//--------------------------------------------------
{
  /* Student provides missing code to display A[i], i ? [ L,R ], 10 elements per line.
      See the "Sample Program Dialog" for detailed formatting requirements. You are allowed to 
      use "real" loop control c?nstructs unless, of course, you don’t want to!? */
    printf("\n%s\n", label);
    for (int j = 1; j <= strlen(label); j++)
    {
    	printf("=");
	}
	printf("\n");
	for (int i = L; i <= R; i++)
	{
		if (((i) % 10) == 0)
		{
			printf("\n%d: ", i);
		}
		printf("%d ", A[i]);
	}
	printf("\n"); 
}

//--------------------------------------------------
int NumberOfInversions(const int A[],const int n,bool (*AreInverted)(const int LHS,const int RHS))
//--------------------------------------------------
{
   int i,r;

   for (i = 0,r = 0; i <= n-2; i++)
      for (int j = i+1; j <= n-1; j++)
         if ( AreInverted(A[i],A[j]) ) r++;
   return( r );
}

//--------------------------------------------------
bool Ascending(const int LHS,const int RHS)
//--------------------------------------------------
{
   return( (LHS > RHS) ? true : false );
}

//--------------------------------------------------
bool Descending(const int LHS,const int RHS)
//--------------------------------------------------
{
   return( LHS < RHS );
}
//--------------------------------------------------
void DoBubbleSort(int A[],const int n,
                  bool (*ShouldSwap)(const int LHS,const int RHS),
                  int *numberCompares,
                  int *numberMoves)
//--------------------------------------------------
{

 /*  Student provides missing code to Bubble Sort the n elements in the array A 
      (A[i], i ? [ 0,n-1 ]) using the function-pointer parameter ShouldSwap()
      to determine whether adjacent elements should be swapped. Count the 
      number of comparisons, *numberCompares, and the number of moves, *numberMoves,
      needed to sort the n elements. The non-goto version of the Bubble Sort 
      (taken from page 101 of our textbook) is given below.

      *Note* There are three nested structured control constructs, (1) do/while-statement; 
      (2) for-statement; and (3) if-statement that you are obliged to replace with goto-equivalents. */

   int pass;
   bool swapMade;

	pass = 1;
	* numberCompares = 0;
	* numberMoves = 0;
TOL:
	swapMade = false;
	int i = 0;
TOL2:
	if ( !(i <= n-(pass+1)) ) goto BOL2;
	{
		*numberCompares += 1;
		if ( !ShouldSwap(A[i],A[i+1]) ) goto BOIF;
	{
	int T = A[i]; A[i] = A[i+1]; A[i+1] = T;
	*numberMoves += 3;
	swapMade = true;
	}
BOIF:
	i++;
	goto TOL2;
	}

BOL2:
	pass++;
	if ( swapMade ) goto TOL;

}

//--------------------------------------------------
void DoSelectionSort(int *A,const int n,
                     bool (*ShouldSelect)(const int LHS,const int RHS),
                     int *numberCompares,
                     int *numberMoves)
//--------------------------------------------------
{

 /*  Student provides missing code to Selection Sort the n elements in the array A 
      (A[i], i ? [ 0,n-1 ]) using the function-pointer parameter ShouldSelect()
      to determine whether an element should be selected. Count the 
      number of comparisons, *numberCompares, and the number of moves, *numberMoves,
      needed to sort the n elements. The non-goto version of the Selection Sort 
      (taken from page 99 of our textbook) is given below.

      *Note* There are two nested structured control constructs, (1) for-statement; and
      (2) for-statement that you are obliged to replace with goto-equivalents. */

	int i;
	i = 0;
   *numberCompares = 0;
   *numberMoves = 0;
   //for (int i = 0; i <= n-2; i++)
TOL1:
	if (!(i <= n - 2)) goto BOL1;
   {
      int T,select = i;
	  int j;
	  j = i + 1;
      //for (int j = i+1; j <= n-1; j++)
TOL2:
	if (!(j <= n - 1)) goto BOL2;
      {
         //if ( (*ShouldSelect)(A[select],A[j]) ) 
         if (!((*ShouldSelect)(A[select], A[j]))) goto BOL3; 
		 {
		 	select = j;
		 }
BOL3:
         *numberCompares += 1;
         j++;
         goto TOL2;
      }
BOL2:
      T = A[i]; A[i] = A[select]; A[select] = T;
      ++*numberMoves, *numberMoves += 1, (*numberMoves)++;
      i++;
      goto TOL1;
   }
BOL1:
	;
}

//--------------------------------------------------
void DoInsertionSort(int A[1],const int n,
                     bool (*ShouldInsert)(const int LHS,const int RHS),
                     int *numberCompares,
                     int *numberMoves)
//--------------------------------------------------
{

 /*  Student provides missing code to Insertion Sort the n elements in the array A 
      (A[i], i ? [ 0,n-1 ]) using the function-pointer parameter ShouldInsert()
      to determine when/where an element should be inserted. Count the 
      number of comparisons, *numberCompares, and the number of moves, *numberMoves,
      needed to sort the n elements. The non-goto version of the Insertion Sort 
      (taken from page 134 of our textbook) is given below.

      *Note* There are two nested structured control constructs, (1) for-statement; and
      (2) for-statement that you are obliged to replace with goto-equivalents. */

   int i;
   i = 1;
   *numberCompares = 0;
   *numberMoves = 0;
   //for (i = 1; i <= n-1; i++)
TOL1:
	if (!(i <= n - 1)) goto BOL1;
   {
      int v = A[i];
      int j = i-1;
      
      *numberMoves += 1;
//      while ( (j >= 0) && (*ShouldInsert)(A[j],v) )
TOL2:
	if (!((j >= 0) && (*ShouldInsert)(A[j], v))) goto BOL2;
      {
         *numberCompares += 1;
         A[j+1] = A[j];
         *numberMoves += 1;
         j--;
         goto TOL2;
      }
BOL2:
      *numberCompares += 1;
      A[j+1] = v;
      *numberMoves += 1;
      i++;
      goto TOL1;
   }
BOL1:
	;
}
