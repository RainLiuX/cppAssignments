#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

struct record {
	char id[32];
	int in_time;
	int out_time;
};
void readin(record *, int);
void my_sort(record *, bool, int);
int main() {
	int n;
	cin >> n;
	record a[64];
	for (int i = 0; i < n; i++)
		readin(a, i);
	my_sort(a, 0, n);	//sort by in_time;
	cout << a[0].id << " ";
	my_sort(a, 1, n);	//reverse sort by out_time
	cout << a[0].id;
} 
void readin(record * a, int n) {
	struct record rec;
	cin >> rec.id;
	int tmp[3];
	scanf("%d:%d:%d", tmp, tmp + 1, tmp +2);
	rec.in_time = tmp[0] * 60 * 3600 + tmp[1] * 3600 + tmp[2];
	scanf("%d:%d:%d", tmp, tmp + 1, tmp +2);
	rec.out_time = tmp[0] * 60 * 3600 + tmp[1] * 3600 + tmp[2];
	a[n] = rec;
}
void my_sort(record * a, bool flag, int n) {
	for (int j = n - 1; j > 0; j--)
			if (!flag && a[j].in_time < a[j - 1].in_time ||
				flag && a[j].out_time > a[j - 1].out_time) {
				char tmp1[32];
				int tmp2, tmp3;
				strcpy(tmp1, a[j].id);
				tmp2 = a[j].in_time;
				tmp3 = a[j].out_time;
				strcpy(a[j].id, a[j - 1].id);
				a[j].in_time = a[j - 1].in_time;
				a[j].out_time = a[j - 1].out_time;
				strcpy(a[j - 1].id, tmp1);
				a[j - 1].in_time = tmp2;
				a[j - 1].out_time = tmp3;
			}
}
