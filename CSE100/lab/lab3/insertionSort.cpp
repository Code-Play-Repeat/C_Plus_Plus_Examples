#include <iostream>
#include <vector>
using namespace std;

int main ()
{

	int input, seqNum = 2, it = 0;
        cin >> seqNum;
        vector<int> sequence(seqNum);
	while (seqNum > 0)
     	{
		cin >> input;
		sequence[it] = input;
		it++;

		if (it == seqNum)
		{
	           	int i, j, tmp;
		   	for (i = 1; i < seqNum; i++)
		   	{
				j = i;
                                while (j > 0 && sequence[j-1] > sequence[j])
				{
				    tmp = sequence[j];
				    sequence[j] = sequence[j - 1];
                                    sequence[j - 1] = tmp;
                                    j--;
				}
			}
			for (int it2 = 0; it2 < seqNum; it2++)
				cout << sequence[it2] << endl;
			it = 0;
			cin >> seqNum;
			sequence.resize(seqNum);
		}		
		
         }
}
