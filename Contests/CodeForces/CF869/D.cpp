/*
*  File: CF869D
*  Author: Alvin Hsu
*  Date: 04/29/2023 07:30:07
*/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../../Templates/debug.h"
#else
#define dbg(...)
#endif

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n,m;
		cin >> n >> m;
		vector<set<int>>g(n+1);
		for (int i = 0; i < m; i++){
			int u,v;
			cin >> u >> v;
			g[u].insert(v);
			g[v].insert(u);
		}
		vector<int>color(n+1), par(n+1);
		bool ok = false;
		vector<pair<int,int>> ans;
		function<void(int,int)> dfs = [&](int u, int p){
			if (ok) return;
			if (color[u] == 2) return;
			if (color[u] == 1){
				set<int> v = {p};
				vector<pair<int,int>> pos;
				int curr = p;
				while(curr != u){
					pos.push_back({curr, par[curr]});
					curr = par[curr];
					v.insert(curr);
				}
				pos.push_back({curr, p});
				for (auto &node : v){
					vector<pair<int,int>> check;
					for (auto &nxt : g[node]){
						if (v.find(nxt) == v.end()) {
							check.push_back({nxt, node});
							if (check.size() == 2) break;
						}
					}
					if (check.size() == 2) {
						for (int i = 0; i < check.size(); i++){
							pos.push_back(check[i]);
						}
						ans = pos;
						ok = true;
						break;
					}
				}
				return;
			}
			par[u] = p;
			color[u] = 1;
			for (auto &v : g[u]){
				if (v != par[u]){
					dfs(v, u);
				}
			}
			color[u] = 2;
		};
		for (int i = 1; i <= n; i++){
			if (!color[i]) {
				dfs(i, i);
			}
		}
		cout << (ok ? "YES" : "NO") << '\n';
		if (ok){
			cout << ans.size() << '\n';
			for (int i = 0; i < ans.size(); i++){
				cout << ans[i].first << " " << ans[i].second << '\n';
			}
		}
	}
	return 0;
}
