#include <iostream>
using namespace std;

const int UPTIME = 6;
const int DOWNTIME = 4;
int main() {
	int times = 0; 
	while (1) {
		int a[128], n;
		cin >>n;
		if (!n) break;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		int time = 0;
		time += a[0] * UPTIME;
		for (int i = 1; i < n; i++)
			time += (a[i] > a[i - 1]) ? (a[i] - a[i - 1]) * UPTIME : (a[i - 1] - a[i]) *DOWNTIME;
		time += n * 5;
		if (times) cout << endl;
		cout << time; 
		times ++;
	}
	return 0;
}
