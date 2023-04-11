/*
*  File: UCSDSP23_0E
*  Author: Alvin Hsu
*  Date: 11/04/2023 16:12:20
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
	int n;
	cin >> n;
	vector<vector<int>>g(n+1);
	for (int i = 0; i < n-1; i++){
		int u,v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vector<pair<int,int>> ans(n+1);
	vector<int> cnt(n+1);
	function<int(int,int)> dfs = [&](int curr, int par){
		int leaves = g[curr].size() == 1 && g[curr].back() == par;
		for (auto &next : g[curr]){
			if (next != par){
				leaves += dfs(next, curr);
			}
		}
		return cnt[curr] = leaves;
	};
	dfs(1,1);
	function<void(int,int,int)> dfs2 = [&](int curr, int par, int l){
		ans[curr] = {l, l+cnt[curr]-1};
		for (auto &next : g[curr]){
			if (next != par){
				dfs2(next, curr, l);
				l += (cnt[next]);
			}
		}
	};
	dfs2(1,1,1);
	for (int i = 1; i <= n; i++){
		cout << ans[i].first << " " << ans[i].second << '\n';
	}
	return 0;
}
