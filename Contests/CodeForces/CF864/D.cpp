/*
*  File: CF864D
*  Author: Alvin Hsu
*  Date: 08/04/2023 21:59:37
*/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../../Templates/debug.h"
#else
#define dbg(...)
#endif

int main(){
	// ios::sync_with_stdio(false);
	// cin.tie(0);
	int n,m;
	cin >> n >> m;
	vector<int> a(n+1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	vector<set<int>> g(n+1), child(n+1);
	vector<int> par(n+1);
	for (int i = 0; i < n-1; i++){
		int u,v;
		cin >> u >> v;
		g[u].insert(v);
		g[v].insert(u);
	}
	vector<long long> imp(n+1);
	auto cmp = [](auto a, auto b) { 
		if (a.first == b.first) {
			return a.second > b.second;
		}
		return a.first < b.first;
	};
	vector<set<pair<int,int>, decltype(cmp)>> nodeImp(n+1);
	vector<int>nodeSize(n+1, 1);
	function<long long(int,int)> dfs = [&](int curr, int prev) {
		long long sum = a[curr];
		for (auto &next : g[curr]) {
			if (next != prev) {
				par[next] = curr;
				child[curr].insert(next);
				sum += dfs(next, curr);
				nodeSize[curr] += nodeSize[next];
			}
		}
		for (auto &next : child[curr]){
			nodeImp[curr].insert({nodeSize[next], next});
		}
		return imp[curr] = sum;
	};
	dfs(1, 1);
	for (int i = 0; i < m; i++){
		int q,x;
		cin >> q >> x;
		if (q == 1){
			cout << imp[x] << '\n';
		}
		else {
			if (nodeSize[x] == 1) continue;
			auto rem = --nodeImp[x].end();
			pair<int,int> temp = *rem;
			int &childSize = temp.first;
			int &childIdx = temp.second;
			long long childImp = imp[childIdx];
			int p = par[x];
			
			nodeImp[p].erase(nodeImp[p].find({nodeSize[x], x}));
			nodeImp[x].erase(rem);
			
			childImp = imp[x];
			imp[x] -= imp[childIdx];
			imp[childIdx] = childImp;
			
			int xSize = nodeSize[x];
			nodeImp[p].insert({xSize, childIdx});
			nodeImp[childIdx].insert({xSize - childSize, x});
			
			nodeSize[childIdx] = xSize;
			nodeSize[x] -= childSize;
			
			par[childIdx] = p;
			par[x] = childIdx;
		}
	}
	return 0;
}
