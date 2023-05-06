/*
*  File: CF871D
*  Author: Alvin Hsu
*  Date: 05/06/2023 07:33:44
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
	vector<pair<int,int>> v(1e7+5);
	for (int i = 1; i <= 1e7; i++){
		int nxt = i + 2 * i;
		if (nxt <= 1e7) v[nxt] = {i, 2*i};
	}
	int t;
	cin >> t;
	function<bool(int,int)> dfs = [&](int n, int m){
		if (n == m) return true;
		auto p = v[n];
		if (!p.first && !p.second) return n == m;
		assert(p.first && p.second);
		return dfs(p.first,m) || dfs(p.second, m);	
	};
	while(t--) {
		int n,m;
		cin >> n >> m;
		bool ok = dfs(n,m);
		cout << (ok ? "YES" : "NO") << '\n';
	}
	return 0;
}
