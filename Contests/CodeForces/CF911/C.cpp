/*
*  File: CF911C
*  Author: Alvin Hsu
*  Date: 11/26/2023 06:27:44
*/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../../Templates/debug.h"
#else
#define dbg(...)
#endif

struct Node {
	int p,l,r;
	char op;
};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n;
		string s;
		cin >> n >> s;
		vector<Node> g(n+1);
		for (int i = 1; i <= n; i++){
			int l,r;
			cin >> l >> r;
			g[l].p = g[r].p = i;
			g[i].l = l;
			g[i].r = r;
			g[i].op = s[i-1];
		}
		vector<int> vis(n+1);
		int mnCost = 1e9;
		function<void(int,int)> dfs = [&](int u, int cost){
			auto node = g[u];
			if (g[u].l == 0 && g[u].r == 0){
				mnCost = min(mnCost, cost);
			}
			if (g[u].l){
				dfs(g[u].l, cost+(g[u].op != 'L'));
			}
			if (g[u].r){
				dfs(g[u].r, cost+(g[u].op != 'R'));
			}
		};
		dfs(1,0);
		cout << mnCost << '\n';
	}
	return 0;
}
