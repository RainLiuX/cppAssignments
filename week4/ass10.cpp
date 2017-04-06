#include <iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int a = 2, b = 1;
	float sum = 0;
	for(int i = 0; i < n; i++)
	{
		sum += (float)a/b;
		a = a + b;
		b = a - b;
	}
	cout<<sum;
}
