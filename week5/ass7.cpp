#include <iostream>
using namespace std;

int main()
{
	int n, m;
	cin>>n>>m;
	const int k = n;
	int a[k];
	for(int i = 0; i < n; i++)
		cin>>a[i];
	for(int i = 0; i < m; i++)
	{
		int temp = a[n-1];
		for(int j = n-2; j >= 0; j--)
			a[j+1] = a[j];
		a[0] = temp;
	}
	cout<<a[0];
	for(int i = 1; i < n; i++)
		cout<<' '<<a[i];
}
