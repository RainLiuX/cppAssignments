#include <iostream>
#include <string>
using namespace std;

char num[10][10] = {"", "one ", "two ", "three ", "four ", "five ",
		"six ", "seven ", "eight ", "nine "};
char tens[10][20] = {"", "", "twenty ", "thirty ", "forty ", "fifty ",
	"sixty ", "seventy ", "eighty ", "ninety "};
char teen[10][20] = {"", "eleven ", "twelve ", "thirteen ", "fourteen ", "fifteen "
	"sixteen ", "seventeen ", "eighteen ", "nineteen "};
char powe[4][10] = {"", "thousand ", "million ", "billion "};
const char * gen_num(int);
int main() {
	long long a;
	cin >> a;
	string str;
	int n = 0;
	while (a) {
		str = powe[n] + str;
		string tmp = gen_num(a % 1000);
		a /= 1000;
		str = tmp + str;
		n++;
	}
	cout << str;
}
const char * gen_num(int a) {
	int h = a / 100, t = (a / 10) % 10, n = a % 10;
	string str;
	if (h) str += num[h] + string("hundred ");
	str += tens[t];
	if (t == 1) str += teen[n];
	else str += num[n];
	return str.c_str();
}
