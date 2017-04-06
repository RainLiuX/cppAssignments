#include <iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int sum = 1;
	for(int i = 0; i < n-1; i++)
	{
		sum = 2*(sum + 1);
	}
	cout<<sum;
}
