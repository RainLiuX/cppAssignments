#include <iostream>
using namespace std;

int main()
{
	int n, a[10000];
	cin>>n;
	for(int i = 0; i < n; i++)
		cin>>a[i];
	int result[3] ,sum;
	for(int i = 0; i < n; i++)
	{
		sum = 0;
		for(int j = i; j < n; j++)
		{
			sum += a[j];
			if(sum > *result)
			{
				result[0] = sum;
				result[1] = i;
				result[2] = j;
			}
		}
	}
	if(result[0] > 0)
		cout<<result[0]<<' '<<result[1]<<' '<<result[2];
	else
		cout<<0<<' '<<0<<' '<<n-1;
}
