#include <iostream>
using namespace std;

int arr[9000];
void judge(int, int, int);
int main()
{
	int n;
	while(cin>>n, n)
	{
		for(int i = 0; i < 9001; i++)
		{
			arr[i] = 1;
		}
		for(int i = 0; i < n; i++)
		{
			int a, b, c;
			cin>>a>>b>>c;
			judge(a, b, c);
		}
		int count = 0, temp;
		for(int i = 0; i < 9000; i++)
			if(arr[i])
			{
				count ++;
				temp = i + 1000;
			}
		if(count == 1) cout<<temp<<endl;
		else cout<<"Not sure "<<endl;
	}
}
void judge(int a, int b, int c)
{
	int temp, temp2;
	int n , m;
	int p[4], q[4];
	for(int i = 0; i < 9000; i++)
	{
		temp = i + 1000;
		temp2 = a;
		n = 0; m = 0;
		for(int j = 0; j < 4; j++)
		{
			if(temp2%10 == temp%10) m++;
			p[j] = temp2%10;
			q[j] = temp%10;
			temp2 /= 10;
			temp /= 10;
		}
		for(int j = 0; j < 4; j++)
			for(int k = 0; k < 4; k++)
				if(p[j] == q[k])
				{
					n++;
					q[k] = -1;
					break;
				}
		if(n != b || m != c) arr[i] = 0;
	}
}
