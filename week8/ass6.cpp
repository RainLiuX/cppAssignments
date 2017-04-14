#include <iostream>
#include <cstring>
using namespace std;

int main() {
	char s[81];
	cin >> s;
	int n, m, l = strlen(s);
	n = (l + 2) / 3 - 1;
	m = l - 2 * n;
	for (int i = 0; i < n; i++) {
		cout << s[i];
		for (int j = 0; j < m - 2; j++)
			cout << " ";
		cout << s[l - 1 - i] << endl;
	}
	for (int i = n; i < n + m; i++)
		cout << s[i];
	cout << endl;
	return 0;
} 
