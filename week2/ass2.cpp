#include <iostream>
#define G 6.67E-11
using namespace std;
int main()
{
	float f,m1,m2,r;
	cin>>m1>>m2>>r;
	f= G*m1*m2/r/r;
	cout<<f;
	return 0;
}
