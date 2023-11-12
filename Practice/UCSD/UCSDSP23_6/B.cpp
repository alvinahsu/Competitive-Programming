/*
*  File: UCSDSP23_6B
*  Author: Alvin Hsu
*  Date: 05/22/2023 18:10:15
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
		int n,x;
		cin >> n >> x;
		vector<int>v(n);
		for (auto &a : v){
			cin >> a;
		}
		int ans = 0, mn = 1e9+5, mx = -1e9+5;
		for (int i = 0; i < n; i++){
			mx = max(mx, v[i]);
			mn = min(mn, v[i]);
			if (mx - mn > 2*x){
				ans++;
				mn = mx = v[i];
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
