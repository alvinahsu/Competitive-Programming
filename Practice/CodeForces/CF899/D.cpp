/*
*  File: CF899D
*  Author: Alvin Hsu
*  Date: 11/12/2023 20:02:28
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
		int n;
		cin >> n;
		vector<int> a(n+1);
		for (int i = 1; i <= n; i++){
			cin >> a[i];
		}
		vector<vector<int>> g(n+1);
		vector<int> in(n+1);
		for (int i = 0; i < n-1; i++){
			int u,v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
			in[u]++;
			in[v]++;
		}
		vector<int> sz(n+1,1), vis(n+1);
		vector<long long> contr(n+1), ans(n+1);
		stack<int> s;
		for (int i = 1; i <= n; i++){
			if (in[i] == 1){
				s.push(i);
			}
		}
		while(s.size()){
			auto u = s.top(); s.pop();
			vis[u] = 1;
			for (auto &v : g[u]){
				if (!vis[v]){
					if (--in[v] == 1){
						s.push(v);
					}
					sz[v] += sz[u];
					ans[v] += 1ll * (a[v]^a[u]) * sz[u] + ans[u];
					contr[u] += 1ll * (a[v]^a[u]) * sz[u] + ans[u];
				}
			}
		}
		auto dfs = [&](auto self, auto u, auto p) -> void {
			for (auto &v : g[u]){
				if (v == p) continue;
				int remSz = n - sz[v];
				ans[v] += 1ll * (a[u]^a[v]) * remSz + ans[u] - contr[v];
				self(self,v,u);
			}	
		};
		fill(vis.begin(), vis.end(), 0);
		assert(count(sz.begin()+1, sz.end(), n) == 1);
		auto it = find(sz.begin()+1, sz.end(), n) - sz.begin();
		dfs(dfs,it,it);
		for (int i = 1; i <= n; i++){
			cout << ans[i] << " \n"[i == n];
		}
	}
	return 0;
}
