#include <iostream>
#include <list>
#include <vector>
#include <limits>
#include <cstddef>
using namespace std;




void matrixChainOrder(int *p, int size){
	int n = size-1;
	int i,l,j=0,k,q=0;
	int m[n][n];

	vector< vector<int> > s;
	s.resize(n);

	for(i=0; i < n; i++){
		s[i].resize(n);
	}

	for(i=0; i < n; i++){
		m[i][i]=0;
	}

	for(l=2; l <= n;l++){
		for(i=0; i <= n-l; i++){
			j = i+l-1;
			m[i][j]=INT_MAX;
			for(k=i; k < j; k++){
				q=m[i][k] + m[k+1][j] + p[i]*p[k+1]*p[j+1];
				if(q < m[i][j]){
					m[i][j]=q;
					s[i][j]=k;
				}
			}
		}
	}

	cout << m[0][n-1] << endl;
}
int main ()
{
	int n = -1, input =0;
	while (n != 0)
	{
		cin >> n;
		if (n == 0)
		   break;
		int p[n];
		for (int i = 0; i < (n+1); i++)
		{
			cin >> p[i];

		}
		matrixChainOrder(p,n+1);
	}
}
