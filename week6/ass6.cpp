#include <iostream>
using namespace std;

int gen_int(char *, char *);
void sort(int [], int);
int main() {
	int times = 0;
	for(char str[1024]; cin.getline(str, 1024);) {
		int a[512];
		int s = 0, t = 0, p = 0;
		while (1) {
			if (!str[t]) {
				if (s != t) {
					a[p] = gen_int(str + s, str + t);
					p++;
				}
				break;
			}
			if (str[t] == 48 + 5) {
				if (s != t) {
					a[p] = gen_int(str + s, str + t);
					p++;
				}
				s = ++t;
			} else t++;
		}
		sort(a, p);
		if (times) cout << endl;
		times++;
		cout << a[0];
		for(int i = 1; i < p; i++)
			cout << " " << a[i];
	}
	return 0;
}
int gen_int(char * s, char * t) {
	int n = 0;
	for (; s != t; s++)
		n = n * 10 + (*s - 48);
	return n;
}
void sort(int a[], int n) {
	for (int i = 0; i < n - 1; i++)
		for (int j = n - 1; j > i; j--)
			if (a[j] < a[j - 1]) {
				int tmp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = tmp;
			}
}
