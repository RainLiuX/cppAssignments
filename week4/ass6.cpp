#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	float a, b;
	cin>>a>>b;
	cout<<(-cos(b) + cos(a) + exp(b) - exp(a));
	return 0;
}
