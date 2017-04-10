#include <iostream>
using namespace std;

int main() {
	char str[128];
	cin.getline(str, 128);
	int cap_num = 0, low_num = 0, num_num = 0, otr_num = 0;
	for (char * p = str; *p; p++) {
		if (*p >= 65 && *p <= 65 + 26) cap_num++;
		else if (*p >= 97 && *p <= 97 + 26) low_num++;
		else if (*p >= 48 && *p <= 48 + 10) num_num++;
		else otr_num++; 
	}
	cout << cap_num << endl << low_num << endl
		<< num_num << endl << otr_num << endl << cap_num + low_num + num_num + otr_num;
}
