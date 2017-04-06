#include <iostream>
using namespace std;

int main()
{
	int n, y, m;
	cin>>n;
	for(int i = 0; i < n; i++)
	{
		cin>>y>>m;
		y += y%4 ? 4 - y%4: 0;
		if(!(y%100) && y%400) y += 4;
		for(int j = 0; j < m - 1; j++)
		{
			y += 4;
			if(!(y%100) && y%400) y += 4;
		}
		cout<<y<<endl;
	}
}
