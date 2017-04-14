#include <iostream>
#include <cstring>
using namespace std;

bool permmit(char *, int [][2]);
void num_minus(char *);
int main() {
	char number[501];
	int key[10][2] = {{3, 1}, {0, 0}, {0, 1}, {0, 2}, {1, 0}, {1, 1}, {1, 2}, {2, 0}, {2, 1}, {2, 2}};
	int n;
	cin >> n;
	while(n--) {
		cin >> number;
		char * num_end = number + strlen(number) - 1;
		while(!permmit(number, key))
			num_minus(num_end);
		cout << number << endl;
	}
} 
bool permmit(char * number, int key[][2]) {
	for (int i = strlen(number) - 1; i > 0; i--)
		if (key[number[i] - 48][0] < key[number[i - 1] - 48][0]
			|| key[number[i] - 48][1] < key[number[i - 1] - 48][1])
			return false;
	return true;
}
void num_minus(char * number) {
	if (*number == 48) {
		*number = 48 + 9;
		num_minus(number - 1); 
	} else *number -= 1;
}
