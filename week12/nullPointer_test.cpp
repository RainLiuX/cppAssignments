#include <iostream>
using namespace std;

int main() {
	int *p = NULL;
	cout << "value of *p: " << (p == 0 ? -1 : *p) << endl;
	return 0;
} 
