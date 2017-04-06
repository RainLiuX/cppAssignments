#include <iostream>
#include <cstring>
using namespace std;

void trans(int ,int);
int main()
{
	int n;
	cin>>n;
	trans(n, 2);
	cout<<endl;
	trans(n, 8);
	cout<<endl;
	trans(n, 16);
	return 0;
}
void trans(int n, int t)
{
	int i = 0;
	char s[128];
	if(!n) cout<<0;
	while(n)
	{
		s[i] = (n%t < 10) ? n%t +48 : n%t + 55;
		n /= t;
		i++;
	}
	s[i] = '\0';
	int j = 0;
	i --;
	while(i - j > 0)
	{
		int temp;
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
		i --; j ++;
	}
	cout<<s;
}
