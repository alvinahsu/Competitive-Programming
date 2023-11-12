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
						//can only cut vertices if their size is 3
						if (sz[nxt] == 3){
							ans.push_back(j);
						}
						else {
							sz[curr] += sz[nxt];
						}
					}
				}
				//should have cut all vertices that pertain to one branch
				//for this to be one branch, it needs to have <= 3 vertices
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
