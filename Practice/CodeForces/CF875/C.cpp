/*
*  File: CF875C
*  Author: Alvin Hsu
*  Date: 05/29/2023 14:02:52
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
		vector<vector<pair<int,int>>> g(n+1);
		vector<pair<int,int>> q(n-1);
		for (int i = 0; i < n-1; i++){
			int u,v;
			cin >> u >> v;
			q[i] = {u,v};
			g[u].push_back({v,i});
			g[v].push_back({u,i});
		}
		vector<int> time(n+1);
		time[1] = 1;
		function<void(int,int)> dfs = [&](int curr, int i){
			for (auto &[nxt,idx] : g[curr]){
				if (time[nxt]) {
					continue;
				}
				time[nxt] = idx < i ? time[curr] + 1 : time[curr];
				dfs(nxt, idx);
			}
		};
		for (int i = 0; i < n-1; i++){
			auto &[u,v] = q[i];
			if (time[u]){
				dfs(u,i);
			}
			if (time[v]){
				dfs(v,i);
			}
		}
		cout << *max_element(time.begin(), time.end()) << '\n';
	}
	return 0;
}
