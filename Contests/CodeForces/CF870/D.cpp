/*
*  File: CF870D
*  Author: Alvin Hsu
*  Date: 05/05/2023 07:28:53
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
		vector<int>v(n);
		for (auto &a : v){
			cin >> a;
		}
		vector<int> pref(n), suff(n);
		int mx = v[0];
		for (int i = 1; i < n; i++){
			mx--;
			pref[i] = v[i] + mx;
			mx = max(mx, v[i]);			
		}
		mx = v[n-1];
		for (int i = n-2; i >= 0; i--){
			mx--;
			suff[i] = v[i] + mx;
			mx = max(mx, v[i]);
		}
		int ans = 0;
		for (int i = 1; i < n-1; i++){
			ans = max(ans, pref[i] + suff[i] - v[i]);
		}
		cout << ans << '\n';
	}
	return 0;
}
