#include <iostream> 
#include <cmath>
using namespace std;

int main()
{
	float a, b, c;
	cin>>a>>b>>c; 
	float p = (a + b + c)/2;
	cout<<(sqrt(p*(p-a)*(p-b)*(p-c)));
	return 0;
}
