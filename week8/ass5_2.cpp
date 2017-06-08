#include <iostream>
#include <cstring>
using namespace std;

const int MAX_N = 500, MAX_INT = 1 << 31 - 1;
int main () {
	int n, m, s, d;	//city num, path num, start, terminal
	cin >> n >> m >> s >> d;
	int len[MAX_N][MAX_N], price[MAX_N][MAX_N];
	int dist[MAX_N], cost[MAX_N], minm[MAX_N] = { 0 }, pre[MAX_N];
	memset(dist, 0x7F, sizeof(dist));
	memset(cost, 0x7F, sizeof(cost));
	memset(len, 0x7F, sizeof(len));
	memset(price, 0x7F, sizeof(price));
	while (m--) {
		int from, to, l, p;
		cin >> from >> to >> l >> p;
		len[from][to] = len[to][from] = l;
		price[from][to] = price[to][from] = p;
	}
	int c = s, c_tmp;
	dist[s] = cost[s] = 0;
	minm[s] = 1;
	while(!minm[d]) {
		for (int i = 0, minlen = MAX_INT; i < n; i++) {
			if (dist[i] > dist[c] + len[i][c] ||
				dist[i] == dist[c] + len[i][c] && cost[i] > cost[c] + price[i][c]) {
					dist[i] = dist[c] + len[i][c];
					cost[i] = cost[c] + price[i][c];
					pre[i] = c;
				}
			if (!minm[i] && dist[i] < minlen) {
				c_tmp = i;
				minlen = dist[i];
			}
		}
		c = c_tmp;
		minm[c] = 1;
	}
	int path[MAX_N], path_n = 0;
	for (int i = d; i != s; i = pre[i], path_n++)
		path[path_n] = i;
	cout << s;
	for (int i = path_n - 1; i >= 0; i--)
		cout << " " << path[i];
	cout << " " << dist[d] << " " << cost[d] << endl;
}
