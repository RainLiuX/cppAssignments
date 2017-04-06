#include <iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int r = 1;
	for(int i = 0; i < n; i++)
		r *= (i+1);
	cout<<r;
}
