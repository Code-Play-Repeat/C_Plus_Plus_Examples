#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main (int argc, char *argv[])
{  

   int as = 0, input = 0, size = 0, k = 0, x = 0, result = 0, l = 0, r = 0;
   double m = 0.0;
   cin >> size;
   k++;
   vector<int> a(size);

   while (size != 0)
   {
     cin >> input;

     if (k == 1)
     {
        k++;
        as = input;
     }
     else if (k > 1)
     {
        a[x] = input;
	x++;
     }

     if (x == size)
     {

       for (int i = 0; i < size; i++)
          {
             if (a[i] == as)
             {
               result = i;
               break;
             }
             else
              result = -1;
          }
       cout << result << endl;
       cin >> size;
       a.resize(size);
       x = 0;
       k = 1;        
    }
    
   
  }
}


