#include <bits/stdc++.h>
using namespace std;

const int N = 2e5;
vector<int> color(N);
vector<int> g[N];

void dfs (int u) {
	color[u] = 1;
	for (auto &v : g[u]){
		if (color[v] == 1){
			//cycle
		}
		if (!color[v]){
			dfs(v);
		}
	}
	color[u] = 2;
};

/*
for (int i = 1; i <= n; i++){
	if (!color[i]){
		dfs(dfs,i);
	}
}
*/