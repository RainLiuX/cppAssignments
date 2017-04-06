#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	char s[128];
	cin>>s;
	for(int i = 0; i < strlen(s); i++)
		if(s[i] >= 97 && s[i] <= 122)
			s[i] -= 32;
	cout<<s;
}
