#include <iostream>
#include <iomanip> 
#include <sstream>
#include <cmath>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	int c = a + b;
	bool sign = c < 0;
	c = abs(c);
	string str;
	while (c >= 1000) {
		stringstream tmp;
		tmp << setfill('0') << setw(3) << c % 1000;
		c /= 1000;
		str = "," + tmp.str() + str;
	}
	stringstream tmp;
	tmp << c % 1000;
	str = tmp.str() + str; 
	cout << (sign ? "-" : "") << str.c_str();
}
