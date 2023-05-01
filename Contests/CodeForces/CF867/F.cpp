/*
*  File: CF867F
*  Author: Alvin Hsu
*  Date: 05/01/2023 11:47:12
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
		int n,k,c;
		cin >> n >> k >> c;
		vector<vector<int>> g(n+1);
		for (int i = 0; i < n-1; i++){
			int u,v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		vector<int> f(n+1), x(n+1), level(n+1);
		vector<vector<pair<int,int>>> child(n+1);
		function<void(int,int,int)> dfs = [&](int u, int p, int d){
			vector<pair<int,int>> v;
			level[u] = d;
			for (auto &nxt : g[u]){
				if (nxt != p){
					dfs(nxt, u, d+1);
					v.push_back({f[nxt],nxt});
				}
			}
			sort(v.begin(), v.end());
			child[u] = v;
			if (v.size()) {
				f[u] = v.back().first + 1;
			}
		};
		function<void(int,int,int)> dfs2 = [&](int u, int p, int prev){
			auto v = child[u];
			x[u] = prev;
			for (auto &nxt : g[u]){
				if (nxt != p){
					int nextPrev = prev+1;
					if (v.size() > 0){
						if (v.back().second != nxt) {
							nextPrev = max(nextPrev, v.back().first+2);
						}
					}
					if (v.size() > 1){
						if (v[v.size()-2].second != nxt) {
							nextPrev = max(nextPrev, v[v.size()-2].first+2);
						}
					}
					dfs2(nxt, u, nextPrev);
				}
			}
		};
		dfs(1,1,0);
		dfs2(1,1,0);
		long long ans = 0;
		for (int i = 1; i <= n; i++){
			ans = max(ans, (1ll * max(f[i],x[i]) * k) - (1ll * c * level[i]));
		}
		cout << ans << '\n';
	}
	return 0;
}
