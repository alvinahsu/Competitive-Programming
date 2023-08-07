/*
*  File: CF891E
*  Author: Alvin Hsu
*  Date: 08/07/2023 09:56:12
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
		vector<long long> v(n), pref(n+1);
		for (int i = 0; i < n; i++){
			cin >> v[i];
		}
		auto s = v;
		sort(s.begin(), s.end());
		for (int i = 0; i < n; i++){
			pref[i+1] = pref[i] + s[i];
		}
		vector<long long> ans(n);
		for (int i = 0; i < n; i++){
			auto it = upper_bound(s.begin(), s.end(), v[i]) - s.begin() - 1;
			long long l = pref[it+1];
			long long r = pref[n] - pref[it+1];
			long long szL = it + 1, szR = n - szL;
			long long L = szL * v[i], R = szR * v[i];
			ans[i] = abs(L - l) + abs(R - r) + n;
		}
		for (long long i = 0; i < n; i++){
			cout << ans[i] << " \n"[i == n-1];
		}
	}
	return 0;
}
