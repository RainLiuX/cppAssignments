#include <iostream>
using namespace std;

int main() {
	int num, b, a[7], n = 0;
	cin >> num >> b;
	while (num) {
		a[n] = num % b;
		num /= b;
		n++;
	}
	bool p = true;
	for (int i = 0, j = n - 1; i < j; i++, j--)
		if (a[i] != a[j]) {
			p = false;
			break;
		}
	cout << (p ? "Yes" : "No") << endl;
	cout << (n ? a[n - 1] : 0);
	for (int i = n - 2; i >= 0; i--)
		cout << " " << a[i];
	return 0;
} 
