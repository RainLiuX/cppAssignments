#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	for(int i = 0; i < 2; i++)
	{
		float a, b, c;
		cin>>a>>b>>c;
		float delta = b*b - 4*a*c;
		int sign;	//0 real 1 imagine
		if(delta > 0)
		{
			sign = 0;
			delta = sqrt(delta);
		}
		else
		{
			sign = 1;
			delta = sqrt(-delta);
		}
		if(sign)
			cout<<(-b/2/a)<<"+j"<<(delta/2/a)<<endl
				<<(-b/2/a)<<"-j"<<(delta/2/a)<<endl;
		else
			cout<<((-b+delta)/2/a)<<endl<<((-b-delta)/2/a)<<endl;
	}
	return 0;
}
