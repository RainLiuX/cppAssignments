#include <iostream>
#include <cmath> 
using namespace std;

int main()
{
	float x = 1.0f, u;
	do
	{
		u = (x*exp(x) - 1)/exp(x)/(1 + x);
		x -= u;
	}while(u > 0.0001);	
	cout<<(int)(x*10000 + 0.5)/10000.0;
	return 0;
}
