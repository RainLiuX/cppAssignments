#include <iostream>
using namespace std;

int main()
{
	int m[4] = {50, 20, 10, 5};
	int t;
	cin>>t;
	for(int i = 0; i < 4; i++)
	{
		cout<<((int)(t/m[i]))<<endl;
		t %= m[i]; 
	}
	cout<<t;
}
