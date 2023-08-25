/*
*  File: CF894F
*  Author: Alvin Hsu
*  Date: 08/24/2023 13:32:25
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
		int w,f;
		cin >> w >> f;
		int n;
		cin >> n;
		vector<int> s(n);
		for (int i = 0; i < n; i++){
			cin >> s[i];
		}
		const int N = 1e6+5;
		bitset<N> dp;
		dp[0] = 1;
		for (int i = 0; i < n; i++){
			dp |= (dp << s[i]);
		}
		int sum = accumulate(s.begin(), s.end(), 0);
		int l = 1, r = 1e9;
		while(l < r){
			int mid = l + (r - l) / 2;
			long long wt = 1ll * w * mid, ft = 1ll * f * mid;
			bool ok = false;
			for (int i = 0; i < N; i++){
				if (dp[i]){
					if (i <= wt){
						int rem = sum - i;
						if (ft >= rem) ok = true;
					}
					if (i <= ft){
						int rem = sum - i;
						if (wt >= rem) ok = true;
					}
				}
			}
			if (ok){
				r = mid;
			}
			else {
				l = mid+1;
			}
		}
		cout << l << '\n';
	}
	return 0;
}
