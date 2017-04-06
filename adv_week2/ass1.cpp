#include <iostream> 
#include <fstream>

int main()
{
	using namespace std;
	
	//ifstream file("in.txt");
	
	int num = 0;
	string str, temp;
	getline(cin, str);
	while(getline(cin, temp))
	{
		str += temp + "\n";
	}
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == 32) num++;
	}
	//file.close();
	cout<<num;
	cin.get();
	return 0;
}
