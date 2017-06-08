#include <iostream>
#include <cstring>
using namespace std;

const int MAX_N = 500, MAX_INT = 0x7F7F7F;
int main () {
	int n, m, s, d;	//city num, path num, start, terminal
	cin >> n >> m >> s >> d;
	int len[MAX_N][MAX_N];
	int dist[MAX_N], man[MAX_N], minm[MAX_N] = { 0 }, pre[MAX_N];
	memset(len, 0x7F, sizeof(len));
	for (int i = 0; i < n; i++)
		cin >> man[i];
	while (m--) {
		int from, to, l;
		cin >> from >> to >> l;
		len[from][to] = len[to][from] = l;
	}
	int cases = 0, total_man = 0, flag = 1, min_dist = MAX_INT;
	while(1) {
		memset(dist, 0x7F, sizeof(dist));
		memset(minm, 0, sizeof(minm));
		int c = s;
		dist[s] = 0;
		minm[s] = 1;
		while(!minm[d]) {
			int c_tmp = -1;
			for (int i = 0, minlen = MAX_INT; i < n; i++) {
				if (dist[i] > dist[c] + len[i][c]) {
						dist[i] = dist[c] + len[i][c];
						pre[i] = c;
					}
				if (!minm[i] && dist[i] < minlen) {
					c_tmp = i;
					minlen = dist[i];
				}
			}
			if (c_tmp == -1) break;	//nothing found
			c = c_tmp;
			minm[c] = 1;
		}
		if (dist[d] > min_dist) break;
		cases++;
		min_dist = dist[d];
		int tmp = 0;
		for (int i = d, path_n = 0; i != s; i = pre[i], path_n++) {
			len[i][pre[i]] = MAX_INT;
			tmp += man[i];
		}
		if (tmp + man[s] > total_man)
			total_man = tmp + man[s];
	}
	cout << cases << " " << total_man << endl;
}
