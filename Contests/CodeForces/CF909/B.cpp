/*
*  File: CF909B
*  Author: Alvin Hsu
*  Date: 11/17/2023 00:21:57
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
		vector<int> v(n);
		for (int i = 0; i < n; i++){
			cin >> v[i];
		}
		long long ans = *max_element(v.begin(), v.end()) - *min_element(v.begin(), v.end());
		auto check = [&](int k){
			long long mn = 1e18, mx = -1e18;
			long long curr = 0;
			for (int i = 0; i < n; i++){
				curr += v[i];
				if ((i+1)%k == 0){
					mn = min(mn, curr);
					mx = max(mx, curr);
					curr = 0;
				}
			}
			return mx - mn;
		};
		for (int i = 2; i*i <= n; i++){
			if (n%i == 0){
				ans = max(ans, check(i));
				ans = max(ans, check(n/i));
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
