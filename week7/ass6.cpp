#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

struct record {
	char id[32];
	int in_time;
	int out_time;
};
typedef vector<record> VR;
void readin(VR &);
bool cmp_in(const record &, const record &);
bool cmp_out(const record &, const record &);
int main() {
	int n;
	cin >> n;
	VR vec;
	while (n--)
		readin(vec);
	sort(vec.begin(), vec.end(), cmp_in);
	cout << vec[0].id << " ";
	sort(vec.begin(), vec.end(), cmp_out);
	cout << vec[0].id;
} 
void readin(VR & vec) {
	struct record rec;
	cin >> rec.id;
	int tmp[3];
	scanf("%d:%d:%d", tmp, tmp + 1, tmp +2);
	rec.in_time = tmp[0] * 60 * 3600 + tmp[1] * 3600 + tmp[2];
	scanf("%d:%d:%d", tmp, tmp + 1, tmp +2);
	rec.out_time = tmp[0] * 60 * 3600 + tmp[1] * 3600 + tmp[2];
	vec.push_back(rec);
}
bool cmp_in(const record & r1, const record & r2) {
	return r1.in_time < r2.in_time;
}
bool cmp_out(const record & r1, const record & r2) {
	return r1.out_time > r2.out_time;
}
