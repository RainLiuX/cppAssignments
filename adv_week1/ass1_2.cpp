#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	string str;
	getline(cin, str);
	int p=0, i=0;
	stack<string> sta;
	while(1)
	{
		if(str[i] == 32)
		{
			sta.push(str.substr(p, i-p));
			p=i+1;
		}
		else if(str[i] == '#') break;
		i++;
	}
	while(!sta.empty())
	{
		cout<<sta.top()<<" ";
		sta.pop();
	}
	return 0;
}
