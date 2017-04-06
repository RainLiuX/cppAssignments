#include <iostream>
using namespace std;

int gcd(int, int);
int main()
{
	int a, b;
	cin>>a>>b;
	cout<<gcd(a,b);
}
int gcd(int a, int b)
{
	int tmp = a%b;
	a = b;
	b = tmp;
	if(b == 0) return a;
	else return gcd(a, b);
}
