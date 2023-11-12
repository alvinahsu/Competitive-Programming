/*
*  File: UCSDSP23_4B
*  Author: Alvin Hsu
*  Date: 05/08/2023 20:22:09
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
	int n,q;
	cin >> n >> q;
	vector<int>v(n);
	for (auto &a : v){
		cin >> a;
	}
	sort(v.begin(), v.end());
	vector<long long> pref(n+1);
	for (int i = 0; i < n; i++){
		pref[i+1] = pref[i] + v[i];
	}
	while(q--){
		int x;
		cin >> x;
		auto f = lower_bound(v.begin(), v.end(), x) - v.begin() + 1;
		auto s = upper_bound(v.begin(), v.end(), x) - v.begin();
		long long ps = pref[f-1] - pref[0], ss = pref[n] - pref[s];
		long long ans = ((1ll * (f-1) * x) - ps) + (ss - 1ll * (n - s) * x);
		cout << ans << '\n';
	}
	return 0;
}
