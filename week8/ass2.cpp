#include <iostream>
#include <cstdio>
using namespace std;

long gcd(long, long);
int main() {
	int n;
	cin >> n;
	long num[100], den[100];
	for (int i = 0; i < n; i++)
		scanf("%d/%d", num + i, den + i);
	long lcm = den[0];
	for (int i = 1; i < n; i++) {
		long tmp = gcd(lcm, den[i]);
		lcm = lcm * den[i] / tmp;
	}
	long sum = 0;
	for (int i = 0; i < n; i++)
		sum += num[i] * lcm / den[i];
	long tmp = gcd(sum, lcm);
	sum /= tmp;
	lcm /= tmp;
	if (sum / lcm) cout << sum / lcm << " ";
	if (sum % lcm) cout << sum % lcm << "/" << lcm; 
}
long gcd(long a, long b) {
	return a % b ? gcd(b, a % b) : b;
}
