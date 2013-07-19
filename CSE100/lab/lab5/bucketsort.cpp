#include <iostream>
#include <list>

using namespace std;

void bucketSort (double A[], int n)
{
  list<double> B[n];
  list<double>::iterator Bi;
  for (int i = 0; i < n; i++)
	B[int(n*A[i])].push_back(A[i]);	
  for (int i = 0; i < n; i++)
        B[i].sort();
  for (int i = 0; i < n; i++) 
      for (Bi = B[i].begin(); Bi !=B[i].end(); ++Bi)
             cout << *Bi << endl;
       
  
}

int main ()
{

	int seqNum = 2;
	while (seqNum > 0)
     	{
	    	cin >> seqNum;
	    	double A[seqNum];
		if (seqNum == 0)
		   break;

	    	for (int i = 0; i < seqNum; i++)
		    cin >> A[i];
		bucketSort(A,seqNum);
		
        }
}
