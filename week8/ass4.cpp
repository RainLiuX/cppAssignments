#include <cstdio>
#include <cstring>
struct record {
	char name[21], s[12];
	bool online;
	int time, price;
};
int cost[24];
int main() {
	for (int i = 0; i < 24; i++)
		scanf("%d", cost + i);
	record clist[2014];
	int n;
	scanf("%d", &n);
	for (int i = 0, j; i < n; i++) {
		char tmps[21];
		scanf("%s %s %s", clist[i].name, clist[i].s, tmps);
		clist[i].online = tmps[1] == 'n';
	}
	char month[3]; sscanf(clist[0].s, "%2s", month);
	for (int i = 0; i < n - 1; i++)
		for (int j = n - 1; j > i; j--)
			if (strcmp(clist[j].name, clist[j - 1].name) < 0 || !strcmp(clist[j].name, clist[j - 1].name) && strcmp(clist[j].s, clist[j - 1].s) < 0) {
					record tmpr = clist[j];
					clist[j] = clist[j - 1];
					clist[j - 1] = tmpr;
				}
	for (int i = 1; i < n; i++)
		if (!clist[i].online && clist[i - 1].online && !strcmp(clist[i].name, clist[i - 1].name)) {
			int d_, h_, f_, d, h, f, t1, t2, t3;
			sscanf(clist[i - 1].s + 3, "%d:%d:%d", &d_, &h_, &f_);
			sscanf(clist[i].s + 3, "%d:%d:%d", &d, &h, &f);
			t1 = d_ * 24 * 60 + h_ * 60 + f_;
			t2 = d * 24 * 60 + h * 60 + f;
			t3 = t1 - t1 % 60 + 60;
			clist[i].time = t2 - t1;
			clist[i].price = (t3 - t1) * cost[(t3 / 60 - 1) % 24];
			while (t2 > t3) {
				clist[i].price += 60 * cost[t3 / 60 % 24];
				t3 += 60;
			}
			clist[i].price -= (t3 - t2) * cost[(t3 / 60 - 1) % 24];
		}
	for (int i = 0, sum = 0; i < n; i++) {
		if (!i || strcmp(clist[i].name, clist[i - 1].name)) {
			printf("%s %s\n", clist[i].name, month);
			sum = 0; 
		} 
		if (!clist[i].online && clist[i - 1].online && !strcmp(clist[i].name, clist[i - 1].name)) {
			printf("%s %s %d $%.2f\n", clist[i - 1].s + 3, clist[i].s + 3, clist[i].time, clist[i].price/ 100.0f);
			sum += clist[i].price;
		}
		if (i == n - 1 || strcmp(clist[i].name, clist[i + 1].name)) printf("Total amount: $%.2f\n", sum / 100.0f);
	}
}
