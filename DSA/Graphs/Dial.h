#include <bits/stdc++.h>
using namespace std;

const int K = 2e5 + 5;
queue<int> bfs[K];
int d[K], used[K];
vector<pair<int,int>> g[K];
int k = 10, start = 0;

// O(N*K + M)
void Dial(){
	bfs[0].push(start);
	d[start] = 0;
	int pos = 0, num = 1;
	while (num > 0) {
		//get next non-empty bucket
		while (bfs[pos % (k + 1)].empty()) {
			++pos;
		}
		int u = bfs[pos % (k + 1)].front(); 
		bfs[pos % (k + 1)].pop();
		--num;
		if (used[u]) {
			continue;
		}
		used[u] = true;
		for (pair<int, int> edge : g[u]) {
			int cost = edge.first, w = edge.second;
			if (d[u] + cost < d[w]) {
				d[w] = d[u] + cost;
				//push to next corresponding bucket
				bfs[d[w] % (k + 1)].push(w);
				++num;
			}
		}
	}
}