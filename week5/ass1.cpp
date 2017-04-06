#include <iostream>
using namespace std;

int main()
{
	int a[128], n;
	cin>>n;
	for(int i = 0; i < n; i++)
		cin>>a[i];
	for(int i = 0; i < n; i++)
		for(int j = n-1; j > i; j--)
			/*if(a[j] < a[j-1])
			{
				int temp = a[j];
				a[j] = a[j-1];
				a[j-1] = temp;
			}*/
				a[j] ^= a[j-1] ^= a[j] ^= a[j-1];
	cout<<a[0];
	for(int i = 1; i < n; i++)
		cout<<' '<<a[i];
}
