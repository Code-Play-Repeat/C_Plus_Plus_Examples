#include <iostream>
#include <vector>
using namespace std;
/*int hashFunction (int k, int T[], int m)
{
   int i = 0, h, h1, h2;
   while (i < m)
   {
	h1 = k % m;
        h2 = 1 + (k % (m-2));
	h = (h1 + i * h2) % m;
	i++;
        if (T[h] == -1)
          break;
   }
   return h;
}*/
int hashSearch (int T[], int k, int m)
{

   for (int i = 0; i < m; i++)
   {
	int h1 = k % m;
        int h2 = 1 + (k % (m-2));
	int h = (h1 + i * h2) % m;
	if (T[h] == k)
	   return h;
   }
   return -1;
}
void hashInsert(int T[], int k, int m)
{
   int i = 0;
   while (i != m)
   {
	int h1 = k % m;
        int h2 = 1 + (k % (m-2));
	int h = (h1 + i * h2) % m;
	if (T[h] == -1)
	{
	   T[h] = k; 
	   break;
	}
	else
	  i = i + 1;

   }
   
}

void hashDelete(int T[], int k, int m)
{ 
   for (int i = 0; i < m; i++)
   {
	int h1 = k % m;
        int h2 = 1 + (k % (m-2));
	int h = (h1 + i * h2) % m;
	if (T[h] == k)
	   T[h] = -1;
   }

}
int main ()
{

	int input = 0, m = 13, h = -1;
	int T[m];
	vector <int> searchSeq;
        vector <int> deleteSeq;
		

		for (int j = 0; j < m; j++)
		    T[j] = -1;

		cin >> input;

		while (input != -1)
		{
		    hashInsert(T,input, m);
		    cin >> input;
		}
		for (int i = 0; i < m; i++)
		{
		   if( T[i] == -1)
		      cout << endl;
		   else
		      cout << T[i] << endl;
		}

		 cin >> input;

		 while (input != -2)
		 {
		      h = hashSearch(T,input,m);
		      searchSeq.push_back(h);
		      cin >> input;
		 }

		 for (int i = 0; i < searchSeq.size(); i++) 
		 {

           	    if (searchSeq[i] == -1)
		       cout << "NOT_FOUND" << endl;
	            else
		       cout << searchSeq[i] << endl;
			
                 }

		 cin >> input;
		 while (input != -3)
		 {
		      hashDelete(T,input,m);
		      cin >> input;
		 }

		 for (int i = 0; i < m; i++)
		 {
		   if( T[i] == -1)
		      cout << endl;
		   else
		      cout << T[i] << endl;
		 }
			
}
