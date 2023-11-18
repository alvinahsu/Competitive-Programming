/*
*  File: CF909G
*  Author: Alvin Hsu
*  Date: 11/17/2023 00:21:57
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
		int n,q;
		cin >> n >> q;
		vector<vector<int>> g(n+1);
		vector<set<int>> s(n+1);
		for (int i = 0; i < n - 1; i++){
			int u,v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		vector<int> idx(n+1);
		vector<vector<array<int,3>>> at(n+1);
		for (int i = 0; i < n; i++){
			int p;
			cin >> p;
			idx[p] = i+1;
		}
		for (int i = 0; i < q; i++){
			int l,r,x;
			cin >> l >> r >> x;
			at[x].push_back({l,r,i});
		}
		auto merge = [&](set<int> &s1, set<int>&s2){
			if (s1.size() < s2.size()) swap(s1, s2);
			for (auto i : s2) s1.insert(i);
		};
		vector<int> ans(q);
		function<void(int,int)> dfs = [&](int u, int p){
			s[u].insert(idx[u]);
			for (auto &v : g[u]){
				if (v == p) continue;
				dfs(v, u);
				merge(s[u], s[v]);
			}
			for (auto [l,r,i] : at[u]){
				auto it = s[u].lower_bound(l);
				ans[i] = it != s[u].end() && *it <= r; 
			}
		};
		dfs(1,1);
		for (int i = 0; i < q; i++){
			cout << (ans[i]?"YES":"NO") << '\n';
		}
		cout << '\n';
	}
	return 0;
}
