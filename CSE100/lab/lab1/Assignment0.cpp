#include <iostream>
#include <vector>
using namespace std;

int main()
{
     
     int num, seqNum, i = 0;
     bool correct = false;
     cin >> seqNum;
     vector<int> sequence(seqNum);
     while (seqNum !=0)
     {
	cin >> num;
	sequence[i] = num;
	i++;

	if (i == seqNum)
	{
	  for(int x = 0; x < seqNum; x++)
	  {

	     if (x == seqNum-1)
	     {
	        correct = true;
		break;
	     }	 
	     
             if ((sequence[x+1] < sequence[x]))
             {
	        correct = false;
	        break;
	     }
	     else
		correct = true;
          }

	  if (correct == true)
	   for(int j = seqNum-1; j >= 0; j--)
		cout << sequence[j] << endl;
	 else
	    cout << "INCORRECT SEQUENCE" << endl;

	  i = 0;
	  cin >> seqNum;
	  sequence.resize(seqNum);
	}
	
     }
}
