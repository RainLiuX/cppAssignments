#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const int MAX_C = 128;
const int MAX_R = 128;
struct customer {
	char name[21];
	char on_str[MAX_R][9];
	char off_str[MAX_R][9];
	char time[MAX_R];	//maximum 128 records for each customer
	char price[MAX_R];
	int p;
	bool online;
};
void my_count(customer *);
void my_sort(customer *);
char month[3] = {0};
int main() {
	customer clist[MAX_C];
	for (int i = 0; i < MAX_R; i++) {
		clist[i].online = false;
		clist[i].p = 0;
	}
	for (int i )
	static int cost[24];
	for (int i = 0; i < 24; i++)
		cin >> cost[i];
	int n, cnum = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		char tmp[20];
		cin >> tmp;
		bool is_recorded = false;
		customer * curr;
		for (int j = 0; j < cnum; j++)
			if (!strcmp(tmp, clist[j].name)) {
				is_recorded = true;
				curr = clist + i;
				break;
			}
		if (!is_recorded) {
			strcpy(clist[cnum].name, tmp);
			cnum++;
			curr = clist + cnum;
		}
		char tmp1[9], tmp2[9];	//input
		cin >> tmp1 >> tmp2;
		bool online_ = !strcmp(tmp2, "on-line");
		if (online_ != curr->online) {
			if (online_) {
				strcpy(curr->off_str[curr->p++], tmp1);
				my_count(curr);
			}
			else strcpy(curr->on_str[curr->p], tmp1);
		} else {
			if (online_) strcpy(curr->on_str[curr->p], tmp1);
			//if !curr_online do nothing
		}	
	}
	month[0] = clist[0].on_str[0][0];
	month[1] = clist[0].on_str[0][1];
	my_sort(consumer *);
	for(int i = 0; i < cnum; i++) {
		customer & curr = clist[i];
		cout << curr.name << " " << month;
		int sum = 0;
		for (int j = 0; j < curr.p; j++) {
			cout << curr.on_str[j] << " " << curr.off_str[j] << " " <<
			curr.time[j] << " $" << curr.price[j];
			sum += curr.price[j];
		}
	}
}
