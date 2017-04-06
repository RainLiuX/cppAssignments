#include <iostream>
using namespace std;

int main()
{
	int a[128], i = 0;
	while(cin>>a[i])
		i++;
	int temp = a[0];
	for(int j = 1; j < i; j++)
		temp = max(temp, a[j]);
	cout<<temp;
	return 0;
}
