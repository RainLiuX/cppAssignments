#include <iostream>
using namespace std;

int main()
{
	int a, b, r;
	cin>>a>>b;
	r = b;
	do
	{
		r = a%b;
		a = b;
		b = r;
	}while(r!=0);
	if(a == 1) cout<<"Yes\n";
	else cout<<"No\n";
	return 0;
}
