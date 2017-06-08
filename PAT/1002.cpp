#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	float a[1001] = { 0 }, b[1001] = { 0 };
	int n, max_k = 0, not_zero = 0;
	cin >> n;
	while(n--) {
		int tmp1;
		float tmp2;
		cin >> tmp1 >> tmp2;
		a[tmp1] = tmp2;
		if(tmp1 > max_k) max_k = tmp1;
	}
	cin >> n;
	while(n--) {
		int tmp1;
		float tmp2;
		cin >> tmp1 >> tmp2;
		b[tmp1] = tmp2;
		if(tmp1 > max_k) max_k = tmp1;
	}
	for (int i = 0; i <= max_k; i++) {
		a[i] += b[i];
		if(a[i]) not_zero++;
	}
	cout << not_zero;
	cout << setiosflags(ios::fixed) << setprecision(1);
	for (int i = max_k; i >= 0; i--)
		if(a[i]) cout << " " << i << " " << a[i];
}
