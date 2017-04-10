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
void gen_num(int);
int main() {
	long long a;
	cin >> a;
	int b, c, d;
	d = a % 1000;	//n
	a /= 1000;
	c = a % 1000;	//thousand
	a /= 1000;
	b = a % 1000;	//million
	a /= 1000;	//billion
	if (a) {
		gen_num(a);
		cout << powe[3];
	}
	if (b) {
		gen_num(b);
		cout << powe[2];
	}
	if (c) {
		gen_num(c);
		cout << powe[1];
	}
	gen_num(d);
}
void gen_num(int a) {
	int h = a / 100, t = (a / 10) % 10, n = a % 10;
	if (h) cout << num[h] << "hundred ";
	cout << tens[t];
	if (t == 1) cout << teen[n];
	else cout << num[n];
}
