#include <iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int a = 1, b = 1;
	int sum = 2;
	if(n == 1)
	{
		cout<<1<<" "<<1;
	}
	else if(n == 2)
	{
		cout<<1<<" "<<2;
	}
	else
	{
		for(int i = 0; i < n-2; i++)
		{
			int tmp = a + b;
			a = b;
			b = tmp;
			sum += tmp;
		}
		cout<<b<<" "<<sum;
	}
	return 0;
}
