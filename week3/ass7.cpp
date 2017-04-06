#include <iostream>
using namespace std;

int main()
{
	char s[5] = "Love";
	int n;
	cin>>n;
	s[0] = (s[0] - 'A' + n)%26 + 'A';
	for(int i = 1; i < 4; i++)
		s[i] = (s[i] - 'a' + n)%26 + 'a';
	cout<<s;
}
