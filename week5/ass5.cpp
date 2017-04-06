#include <iostream>
#include <cstring> 
using namespace std;

int main()
{
	char s[128];
	cin>>s;
	int i = 0, j = strlen(s) - 1;
	while(j > i)
	{
		int temp = s[i];
		s[i] = s[j];
		s[j] = temp;
		j --; i ++;
	}
	cout<<s;
	return 0;
}
