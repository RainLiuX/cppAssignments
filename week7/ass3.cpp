#include <iostream>
using namespace std;

void lwr(char *);
bool cmp(char *, char *);
int main() {
	char a[64], b[64];
	cin >> a >> b;
	lwr(a);
	lwr(b);
	cout << (cmp(a, b) ? "same" : "different");
} 
void lwr(char * s) {
	for (char * p = s; *p; p++)
		if (*p >= 65 && *p <= 91) *p += 32;
}
bool cmp(char * s1, char * s2) {
	
	for (int i = 0; s1[i] && s2[i]; i++)
		if (s1[i] != s2[i]) return false;
	return true;
}

