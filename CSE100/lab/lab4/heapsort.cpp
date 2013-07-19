#include <iostream>
#include <limits>
#include <cmath>

using namespace std;
// method declarations
static int heapsize;
static void updateHeapSize(int x);


int left(int i)
{
   return 2*i;
}

int right (int i)
{
   return 2*i + 1;
}

void maxHeapify(int A[], int i)
{
  int l = left(i);
  int r = right(i);
  int largest;
  if (l < heapsize && A[l] > A[i])
	largest = l;
  else
	largest = i;

  if (r < heapsize && A[r] > A[largest])
	largest = r;

  if (largest != i)
  {
	int temp = A[i];
	A[i] = A[largest];
	A[largest] = temp;
	maxHeapify(A,largest);
  }
}

static void updateHeapSize(int x)
{
	heapsize = x;
}

void buildMaxHeap(int A[])
{

  for (int i = floor((heapsize-1)/2); i >= 0; i--)
    maxHeapify(A,i);
}

void heapSort(int A[])
{
	buildMaxHeap(A);
	for (int i = heapsize; i > 0; i--)
	{
	  int temp = A[0];
          A[0] = A[i-1];
	  A[i-1] = temp;
	  heapsize = heapsize - 1;
          maxHeapify(A,0);
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
		updateHeapSize(seqNum);
		heapSort(A);
		for (int i = 0; i < seqNum; i++)
			cout << A[i] << endl;

        }
}
