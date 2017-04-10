#include <cstdio>
#include <iostream>
using namespace std;

int main() {
	char str[32];
	//cin >> str;
	int tmp[3];
	scanf("%d:%d:%d", tmp, tmp + 1, tmp + 2);
	scanf("%d:%d:%d", tmp, tmp + 1, tmp + 2);
	//cin >> tmp[0] >> tmp[1] >> tmp[2];
	for (int i = 0; i < 3; i++)
		cout << tmp[i] <<" ";
	cout << -11 % 5;
}
