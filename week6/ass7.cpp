#include <iostream>
#include <cstring>
using namespace std;

char * mystrcmp(char *, char *);
int main() {
	char a[128], b[128];
	cin >> a >> b;
	cout << mystrcmp(a, b);
	return 0;
}
char * mystrcmp(char * a, char * b) {
	int l = min(strlen(a), strlen(b));
	for (int i = 0; i < l; i++)
		if (a[i] != b[i]) return a[i] < b[i] ? a : b;
	return strlen(a) <= strlen(b) ? a : b; 
}
