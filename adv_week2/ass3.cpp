#include<iostream>
#include<string>
using namespace std;

int main()
{
	string str;
	getline(cin, str);
	int flag = 0;
	for (int i = 0; i < str.size(); i++)
	{
		
		if ((str[i] == '>') && (flag == 1))
		{
			str[i-1] = '\r';
			str[i] = '\r';
			str[i-2] -=  32;
		}
		if (str[i] == '-')
			flag = 1;
		else
			flag = 0;
	}
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] != '\r')
			putchar(str[i]);
	}
}
