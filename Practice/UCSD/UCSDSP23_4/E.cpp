/*
*  File: UCSDSP23_4E
*  Author: Alvin Hsu
*  Date: 05/09/2023 11:17:38
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
	vector<int>pre(n+1), in(n+1), pi(n+1), ii(n+1);
	for (int i = 1; i <= n; i++){
		cin >> pre[i];
		pi[pre[i]] = i;
	}
	for (int i = 1; i <= n; i++){
		cin >> in[i];
		ii[in[i]] = i;
	}
	bool ok = pre[1] == 1;
	vector<pair<int,int>> ans(n+1, {0,0});
	//l,r -> pre, L,R -> in
	function<void(int,int,int,int)> dfs = [&](int l, int r, int L, int R){
		int root = pre[l];
		int idx = ii[root];
		int x = idx - L;
		int y = R - idx;
		if (r-l+1 != R-L+1 || x < 0 || y < 0){
			ok = false;
			return;
		}
		if (x) {
			ans[root].first = pre[l+1];
			dfs(l+1, l+x, L, idx-1);
		}
		if (y){
			ans[root].second = pre[l+x+1];
			dfs(l+x+1, r, idx+1, R);
		}
	};
	dfs(1,n, 1,n);
	if (!ok){
		cout << -1 << '\n';
	}
	else {
		for (int i = 1; i <= n; i++){
			cout << ans[i].first << " " << ans[i].second << '\n';
		}
	}
	return 0;
}
