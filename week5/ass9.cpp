#include <iostream>
using namespace std;

int main()
{ 
	int a[2][3][4];
	for(int i = 0; i < 2; i ++)
		for(int j = 0; j < 3; j ++)
			for(int k = 0; k < 4; k ++)
				cin>>a[i][j][k];
	for(int j = 0; j < 3; j ++)
	{
		a[0][j][0] += a[1][j][0];
		cout<<a[0][j][0];
		for(int k = 1; k < 4; k ++)
		{
			a[0][j][k] += a[1][j][k];
			cout<<' '<<a[0][j][k];
		}
		cout<<endl;
	}
}
