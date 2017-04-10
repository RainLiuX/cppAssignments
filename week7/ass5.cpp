#include <iostream>
#include <cstring>
using namespace std;
char num[10][10] = {"zero ", "one ", "two ", "three ", "four ", "five ",
		"six ", "seven ", "eight ", "nine "};
int main() {
	char str[101];
	cin >> str;
	int sum = 0;
	for (int i = 0 ;i < strlen(str); i++)
		sum += str[i] - 48;
	const char * output[3];
	int n = 0;
	for (int i = 0; ; i++) {
		int tmp = sum % 10;
		output[i] = num[tmp];
		n++;
		if (!(sum /= 10)) break;
	}
	for (int i = n - 1; i >= 0; i--)
		cout << output[i];
}
