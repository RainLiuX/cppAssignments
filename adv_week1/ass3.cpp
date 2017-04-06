#include <iostream>

int lcm(int, int);
int main()
{
	using namespace std;
	int a[16], i=0;
	while(cin>>a[i])
	{
		if(a[i] == -1) break;
		i++;
	}
	for(int i=0; 1; i++)
	{
		if(a[i+1] == -1)
		{
			cout<<a[i];
			break;
		}
		else
		{
			a[i+1] = lcm(a[i], a[i+1]);
		}
	}
}

int lcm(int x, int y)
{
	int a=x, b=y, r;
	do
	{
		r = a%b;
		a = b;
		b = r;
	}while(r != 0);
	return x*y/a;
}
