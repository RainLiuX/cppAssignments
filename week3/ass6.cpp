#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	float x, y;
	for(int i = 0; i < 2; i++)
	{
		cin>>x>>y;
		float a = sin(fabs(x) + fabs(y));
		float b = fabs(cos(x + y));
		if(b <= 1.0e-5)
			cout<<"divided by zero!"<<endl;
		else
			cout<<(a/sqrt(b))<<endl;
	}
	return 0;
}
