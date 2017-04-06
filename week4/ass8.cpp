#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	float x;
	cin>>x;
	float u = 1, sum = x, tmp = x;
	int n = 1;
	while(fabs(u*tmp) >= 1.0e-12)
	{
		u *= (float)(2*n-1)*(2*n-1)/2/n/(2*n+1);
		tmp *= x*x;
		sum += u*tmp;
		n++;
	}
	cout<<sum;
	return 0;
}
