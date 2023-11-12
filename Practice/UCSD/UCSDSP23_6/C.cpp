/*
*  File: UCSDSP23_6C
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
		int n;
		cin >> n;
		vector<int>v(n);
		for (auto &a : v){
			cin >> a;
		}
		sort(v.begin(), v.end());
		if (v[0] == v[n-1]){
			cout << n / 2 << '\n';
			continue;
		}
		long long mx = 0;
		for (int i = 0; i < n; i++){
			auto up = upper_bound(v.begin(), v.end(), v[i]) - v.begin();
			mx = max(mx, 1ll*(n-up) * up);
		}
		cout << mx << '\n';
	}
	return 0;
}
