/*
*  File: CF885B
*  Author: Alvin Hsu
*  Date: 07/16/2023 10:04:19
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
		int n,k;
		cin >> n >> k;
		vector<int> v(n);
		for (auto &a : v){
			cin >> a;
		}
		vector<multiset<int>> mx(k+1);
		vector<int>last(k+1), ok(k+1);
		for (int i = 0; i < n; i++){
			int l = i - last[v[i]] - (ok[v[i]] ? 1 : 0);
			ok[v[i]] = 1;
			last[v[i]] = i;
			mx[v[i]].insert(l);
		}
		for (int i = 1; i <= k; i++){
			if (ok[i]) {
				int l = n - last[i] - 1;
				mx[i].insert(l);
			}
		}
		int ans = 1e9;
		for (int i = 1; i <= k; i++){
			if (ok[i]){
				assert(mx[i].size());
				auto l = *--mx[i].end();
				mx[i].erase(--mx[i].end());
				mx[i].insert(l/2);
				ans = min(ans, *--mx[i].end());
			}			
		}
		cout << ans << '\n';
	}
	return 0;
}
