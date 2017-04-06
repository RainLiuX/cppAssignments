#include <iostream>
#include <cmath>
using namespace std;

float root(float s, float t);
int main()
{
	cout<<root(0.0, 1.0);
}
float root(float s, float t)
{
	if (t-s < 0.00001)
		return (int)(t*10000+0.5)/10000.0f;
	else
	{
		float mid = (s+t)/2;
		return mid*exp(mid)-1 < 0 ? root(mid, t): root(s, mid);
	}
}

