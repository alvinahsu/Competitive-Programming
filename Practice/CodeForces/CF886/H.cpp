/*
*  File: CF886H
*  Author: Alvin Hsu
*  Date: 07/23/2023 15:07:49
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
		vector<vector<pair<int,long long>>> g(n+1), rg(n+1);
		for (int i = 0; i < m; i++){
			int a,b,d;
			cin >> a >> b >> d;
			rg[a].push_back({b,-d});
			rg[b].push_back({a,d});
		}
		bool ok = true;
		vector<long long>vis(n+1), cord(n+1);
		auto rdfs = [&](auto self, int curr, long long at) -> void{
			vis[curr] = 1;
			cord[curr] = at;
			for (auto &[nxt,d] : rg[curr]){
				if (vis[nxt]){
					ok &= (cord[curr] - cord[nxt] == d);
				}
				else {
					self(self,nxt,at-d);
				}
			}
		};
		for (int i = 1; i <= n; i++){
			if (!vis[i]){
				rdfs(rdfs,i,0);
			}
		}
		cout << (ok ? "YES" : "NO") << '\n';
	}
	return 0;
}
