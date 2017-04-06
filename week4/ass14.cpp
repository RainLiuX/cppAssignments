#include <iostream>
using namespace std;

int gcd(int, int);
int main()
{
	int a, b, c;
	cin>>a>>b>>c;
	int tmp1 = gcd(a, b);
	int tmp2 = a*b/tmp1;
	tmp1 = gcd(tmp1, c);
	tmp2 = tmp2*c/gcd(tmp2, c);
	cout<<tmp1<<" "<<tmp2;
}
int gcd(int a, int b)
{
	int tmp = a%b;
	a = b;
	b = tmp;
	if(b == 0) return a;
	else return gcd(a, b);
}
