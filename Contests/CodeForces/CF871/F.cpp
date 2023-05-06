/*
*  File: CF871F
*  Author: Alvin Hsu
*  Date: 05/06/2023 07:41:20
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
		vector<vector<int>>g(n+1);
		for (int i = 0; i < m; i++){
			int u,v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		for (int i = 1; i <= n; i++){
			int x = g[i].size();
			int y = g[g[i][0]].size()-1;
			if (x <= 1 || y <= 1) continue;
			bool ok = true;
			for (auto &nxt : g[i]){
				ok &= (g[nxt].size()-1 == y);
				for (auto &c : g[nxt]){
					if (!(c == nxt || c == i)){
						ok &= (g[c].size()-1 == 0);
					}
				}
			}
			if (ok) {
				cout << x << " " << y << '\n';
			}
		}
	}
	return 0;
}
