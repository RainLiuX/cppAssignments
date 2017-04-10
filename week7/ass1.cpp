#include <iostream>
#include <sstream>
#include <cmath>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	int c = a + b;
	bool sign = c < 0;
	string str;
	while (c) {
		stringstream tmp;
		tmp << abs(c % 1000);
		c /= 1000;
		str = "," + tmp.str() + str;
	}
	cout << (sign ? "-" : "") << str.c_str() + 1;
}
