#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	float a[3][4];
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 4; j++)
			cin>>a[i][j];
	for(int j = 3; j >=0; j--)
	{
		a[1][j] -= (a[0][j]/a[0][0])*a[1][0];
		a[2][j] -= (a[0][j]/a[0][0])*a[2][0];
	}
	for(int j = 3; j >= 1; j--)
		a[2][j] -= a[1][j]/a[1][1]*a[2][1];
	for(int i = 0; i < 3; i++)
	{
		for(int j = 3; j >= 1; j--)
			a[i][j] /= a[i][i];
	}
	a[1][3] -= a[2][3]/a[2][2]*a[1][2]; a[1][2] = 0;
	a[0][3] -= a[2][3]/a[2][2]*a[0][2] + a[1][3]/a[1][1]*a[0][1];
	a[0][1] = a[0][1] = 0;
	cout.setf(ios::fixed);
	for(int i = 0 ;i < 3; i ++)
		cout<<setprecision(2)<<a[i][3]<<" ";
}
