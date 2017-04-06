#include <iostream>
using namespace std;

int  main()
{
	int n, i = 2;
	cin>>n;
	cout<<"1";
	while(i <= n)
	{
		if(!(n%i)) 
		{
			cout<<"*"<<i;
			n /= i;
		}
		else
			i++;
	}
	return 0;
}
