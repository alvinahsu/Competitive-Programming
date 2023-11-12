/*
*  File: CF887C
*  Author: Alvin Hsu
*  Date: 07/23/2023 10:22:36
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
		if (v[0] != 1){
			cout << 1 << '\n';
			continue;
		}
		long long diff = 0, ans = 1ll * v.back() * k + 1;
		for (int i = 1; i < n; i++){
			diff += (v[i] - v[i-1] - 1);
		}
		if (!diff){
			cout << ans << '\n';
			continue;
		}
		diff *= k;
		ans -= diff;
		for (int i = 1; i < n; i++){
			if (v[i] - v[i-1]-1)
				ans -= (v[i] - v[i-1] + 1);
		}		
		cout << ans << '\n';
	}
	return 0;
}
