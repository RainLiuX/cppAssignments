#include <iostream>
#include <cstring>
using namespace std;

bool legal(int);
void legalize(int, int);
const int key[10][2] = {{3, 1}, {0, 0}, {0, 1}, {0, 2}, {1, 0},
	{1, 1}, {1, 2}, {2, 0}, {2, 1}, {2, 2}};
char num[501];
int main() {
	int n;
	cin >> n;
	while (n--) {
		cin >> num;
		for (int i = 0; i < strlen(num); i++)
			if(!legal(i)) legalize(i, strlen(num));
		cout << num << endl;
	}
}
bool legal(int p) {
	return p ? key[num[p] - 48][0] >= key[num[p - 1] - 48][0]
		&& key[num[p] - 48][1] >= key[num[p - 1] - 48][1] : 1;
}
void legalize(int p, int n) {
	while(--num[p] != 0 + 48)
		if (legal(p)) {
			for (int i = p + 1; i < n; i++)
				num[i] = 9 + 48;
			return;
			}
	if (legal(p)) {
		for (int i = p + 1; i < n; i++)
				num[i] = 0 + 48;
			return;
			}
	legalize(p - 1, n);
}
