#include <iostream>
#include <cstring>
using namespace std;

void mystrrev(char string[]);
int main()
{
	char string[128];
	cin.get(string, 128);
	mystrrev(string);
}
void mystrrev(char string[])
{
	int i = 0, j = strlen(string) - 1;
	while(i < j)
	{
		int temp;
		temp = string[i];
		string[i] = string[j];
		string[j] = temp;
		i++; j--;
	}
	cout<<string;
}
