	/*
	*  File: CF874G
	*  Author: Alvin Hsu
	*  Date: 05/19/2023 13:37:08
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
			vector<vector<pair<int,int>>>g(n+1);
			vector<int> vis(n+1), sz(n+1);
			for (int i = 0; i < n-1; i++){
				int u,v;
				cin >> u >> v;
				g[u].push_back({v,i+1});
				g[v].push_back({u,i+1});
			}
			vector<int> ans;
			bool ok = true;
			function<void(int)> dfs = [&](int curr){
				vis[curr] = 1, sz[curr] = 1;
				for (auto &[nxt,j] : g[curr]){
					if (!vis[nxt]){
						dfs(nxt);
						if (sz[nxt] == 3){
							ans.push_back(j);
							sz[nxt] = 0;
						}
						sz[curr] += sz[nxt];
					}
				}
				if (sz[curr] > 3){
					ok = false;
				}
			};
			dfs(1);
			ok &= (sz[1] == 3);
			if (!ok){
				cout << -1 << '\n';
			}
			else {
				cout << ans.size() << '\n';
				for (auto &a : ans){
					cout << a << " ";
				}
				cout << '\n';
			}
		}
		return 0;
	}
