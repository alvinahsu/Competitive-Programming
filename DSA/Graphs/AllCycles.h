#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
int color[N], par[N];
vector<int> g[N];

//O(N+M)
void dfs(int u, int p){
	//already completed
	if (color[u] == 2) return;
	//seen, not yet completed (cycle)
	if (color[u] == 1){
		//vertices in cycle
		set<int> v = {p};
		//edges in cycle
		vector<pair<int,int>> pos;
		int curr = p;
		//cycle back to current node
		while(curr != u){
			pos.push_back({curr, par[curr]});
			curr = par[curr];
			v.insert(curr);
		}
		pos.push_back({curr, p});
		return;
	}
	//set the parent for this run
	par[u] = p;
	color[u] = 1;
	//dfs search the other nodes
	for (auto &v : g[u]){
		if (v != p){
			dfs(v, u);
		}
	}
	color[u] = 2;
}

/*
function<void(int,int)> dfs = [&](int u, int p){
	if (color[u] == 2) return;
	if (color[u] == 1){
		cycle[p] = 1;
		while(p != u){
			p = par[p];
			cycle[p] = 1;
		}
		return;
	}
	par[u] = p;
	color[u] = 1;
	for (auto v : g[u]){
		if (v == p) continue;
		dfs(v,u);
	}
	color[u] = 2;
};
*/