#include <iostream>
using namespace std;

int main()
{
	int a[10], b[10], c[10], i, j;
	cin>>i;
	for(int m = 0; m < i; m++)
		cin>>a[m];
	cin>>j;
	for(int n = 0; n < j; n++)
		cin>>b[n];
	int flag, p = 0;
	for(int m = 0; m < i; m++)
	{
		flag = 0;
		for(int n = 0; n < j; n++)
			if(a[m] == b[n]) flag = 1;
		if(!flag)
		{
		c[p] = a[m];
		p++;
		}
	}
	for(int m = 0; m < j; m++)
	{
		flag = 0;
		for(int n = 0; n < i; n++)
			if(b[m] == a[n]) flag = 1;
		if(!flag)
		{
		c[p] = b[m];
		p++;
		}
	}
	for(int m = 0; m < p; m++)
		for(int n = p - 1; n > m; n--)
			if(c[n] < c[n - 1])
			{
				int temp = c[n];
				c[n] = c[n - 1];
				c[n - 1] = temp;
			}
	for(int m = 0; m < p; m++)
		cout<<c[m]<<" ";
}
