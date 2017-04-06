#include <iostream>
using namespace std;

int main()
{
	int a[128][5], flag = 0, n = 0;
	for(int i = 0; i < 128; i++)
	{
		for(int j = 0; j < 4; j++)
			if(!(cin>>a[i][j]))
			{
				flag = 1;
				break;
			}
		if(flag) break;
		n++;
	}
	for(int i = 0; i < n; i++)
		a[i][4] = (a[i][1] + a[i][2] + a[i][3])/3;
	//output
	cout<<a[0][0];
	for(int j = 1; j < 5; j++)
			cout<<' '<<a[0][j];
	for(int i = 1; i < n; i++)
	{
		cout<<endl<<a[i][0];
		for(int j = 1; j < 5; j++)
			cout<<' '<<a[i][j];
	}
}
