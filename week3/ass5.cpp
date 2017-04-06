#include <iostream>
#include <cstdio>

int main()
{
	using namespace std;
	char a[3];
	for (int i = 0; i < 3; i ++)
	{
		cin >> a[i];
		if (a[i] >= 'a' && a[i] <= 'z')
			a[i] -= 32;
		else if (a[i] >= 'A' && a[i] <= 'Z')
			a[i] += 32;
	}
	
	cout<<a[0]<<endl<<a[1]<<endl<<a[2];
	/*putchar(a[0]);
	for (int i=1; i<3; i++)
	{
		putchar('\n');
		putchar(a[i]);
	}*/ 
}
