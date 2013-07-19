#include <iostream>
#include <limits>
#include <cmath>

using namespace std;



void merge(int A[], int p, int q, int r)
{
    int n1 = q-p+1;
    int n2 = r-q;

    int L[n1+1];
    int R[n2+1];
    int i = 0;
    int j = 0;

   for (i = 0; i < n1; i++)
   	L[i] = A[p+i];
   for (j = 0; j < n2; j++)
   	R[j] = A[q+j+1];

    L[n1] =  numeric_limits<int>::max();
    R[n2] =  numeric_limits<int>::max();

    i = 0;
    j = 0;
    for (int k = p; k <= r; k++)
    {
	if (L[i] <= R[j])
	{
	   A[k] = L[i];
	   i = i + 1;
	}
	else 
	{
	   A[k] = R[j];
	   j = j + 1;
	}
    }		
}
void mergeSort(int A[], int p, int r)
{
    if (p < r)
    {
        int q = floor((p + r)/2);
        mergeSort(A, p, q);
        mergeSort(A, q+1, r);
        merge(A, p, q, r);
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

		mergeSort(A, 0, seqNum-1);
		for (int i = 0; i < seqNum; i++)
			cout << A[i] << endl;

        }
}
