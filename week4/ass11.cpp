#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int a, n;
	cin>>a>>n;
	int sum = 0;
	for(int i = n; i >= 1; i--)
	{
		for(int j = i; j >= 1; j--)
			sum += a*pow(10, (double)(j-1));
	}
	cout<<sum;
}
