#include <iostream>
#include <limits>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>

using namespace std;


int partition (int A[], int p, int r)
{
	int pivot = A[r];
	int i = p-1;
	for (int j = p; j <= (r-1); j++)
	{
           if (A[j] <= pivot)
	   {
	      i = i + 1;
              int temp = A[i];
	      A[i] = A[j];
	      A[j] = temp;
	   }
	}
	int temp2 = A[i+1];
	A[i+1] = A[r];
	A[r] = temp2;
	
	return (i+1);
     
}

int randomizedPartition (int A[], int p, int r)
{
	int i = rand() % 1 + r;
	int temp = A[r];
	A[r] = A[i];
	A[i] = temp;
	return partition(A, p, r);
    
}
void randomizedQuickSort(int A[], int p, int r) 
{
	if (p < r)
	{
	  int q = randomizedPartition(A,p,r);
	  randomizedQuickSort(A,p,q-1);
	  randomizedQuickSort(A,q+1,r);
	}
}
int main ()
{

	int seqNum = 2;
	while (seqNum > 0)
     	{
	    	cin >> seqNum;
	    	int A[seqNum];
		if (seqNum == 0)
		   break;

	    	for (int i = 0; i < seqNum; i++)
		    cin >> A[i];

		randomizedQuickSort(A,0,seqNum-1);
		for (int i = 0; i < seqNum; i++)
			cout << A[i] << endl;

        }
}
