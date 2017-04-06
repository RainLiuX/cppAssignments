#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	char s[128];
	cin>>s;
	for(int i = 0; i < strlen(s); i++)
	{
		if(s[i] >96)
			s[i] = (s[i] + 3 - 97)%26 + 65;
		else
			s[i] = (s[i] + 3 - 65)%26 + 97;
	}
	cout<<s;
}
