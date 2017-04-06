#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int main()
{
	int n, m, s, d;	//city num, path num, src, des
	cin>>n>>m>>s>>d;
	const int nc = 500;
	int len[nc][nc] = {0};
	int cost[nc][nc] = {0};
	int dist[nc];
	int total[nc];
	int inq[nc] = {0};
	int pre[nc];
	for(int i = 0; i < nc; i++)
	{
		dist[i] = 1000;
		total[i] = 1000;
		pre[i] = -1;
	}
	for(int i = 0; i < nc ;i++)
		for(int j = 0; j < nc; j++)
	 		len[i][j] = 10000;
	for(int i = 0; i < m; i++)
	{
		int t1, t2, t3, t4;
		cin>>t1>>t2>>t3>>t4;
		len[t1][t2] = len[t2][t1] = t3;
		cost[t1][t2] = cost[t2][t1] = t4;
	}
	queue<int> q;
	q.push(s);
	inq[s] = 1;
	dist[s] = 0;
	total[s] = 0;
	while(!q.empty())
	{
		int c = q.front();
		q.pop();
		inq[c] = 0;
		for(int i = 0; i < n; i++)
		{
			//cout<<"c "<<c<<" i "<<i<<" len "<<len[c][i]<<endl;
			if(dist[i] > dist[c] + len[c][i] || ((dist[i] == dist[c] + len[c][i]) && (total[i] > total[c] +cost[c][i])))
			{
				//cout<<"relaxed"<<endl;
				pre[i] = c;
				dist[i] = dist[c] + len[c][i];
				total[i] = total[c] +cost[c][i];
				if(!inq[i]) q.push(i);
				inq[i] = 1;
				//cout<<"dist of "<<i<<" is "<<dist[i]<<endl;
			}
		}
	}
	//output
	int a[128], k=d, p=0;
	a[p] = d;
	while(k != s)
	{
		p++;
		a[p] = pre[k];
		k = pre[k];
	}
	for(int j = p; j >= 0; j--)
		cout<<a[j]<<' ';
	cout<<dist[d]<<' '<<total[d];
}
