#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

int main (int argc, char *argv[])
{  

   int size = 1;


   while (size != 0)
   {
     
     cin >> size;
     vector<int> a(size);
     if (size == 0)
        break;
     int as = 0;
     cin >> as;

     for (int i = 0; i < size; i++)
         cin >> a[i];
  
          int l = 0;
          int r = size;
         bool found = false;
          while (l <= r)
          {
             int m = (r + l)/2;
             if (a[m] == as)
             {
                found = true;
                cout << m << endl;
                break;
             } 
             else if (a[m] > as)
                r = m-1;
             else 
                l = m+1;
          }
       
        if (found == false)
         cout << -1 << endl;
       
  }
}


