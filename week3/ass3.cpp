#include <iostream>
using namespace std;

int main()
{
	float a[4], mean = 0.0f;
	for(int i = 0; i < 4; i++)
	{
		cin>>a[i];
		mean += a[i];
	}
	cout<<(mean/=4)<<endl;
	cout<<((int)(mean + 0.5));
	
}
