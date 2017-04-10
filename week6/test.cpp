#include <iostream>
using namespace std;

int main() {
	int n, a[0][3];
	cin >> n;
	for (int j = 0; j < 6; j++)
		for (int i = 0; i < 3; i++)
			cin >> a[j][i];
			//cout << a[j][i] << endl;
	cout << n << endl;
}
