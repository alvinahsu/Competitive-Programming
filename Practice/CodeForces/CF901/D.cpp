/*
*  File: CF901D
*  Author: Alvin Hsu
*  Date: 11/11/2023 15:53:38
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
		unordered_map<int,long long> cnt, dp;
		vector<int> v(n);
		for (int i = 0; i < n; i++){
			cin >> v[i];
			cnt[v[i]]++;
		}
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
		int cnt0 = cnt[0];
		if (!cnt0){
			cout << 0 << '\n';
			continue;
		}
		int mex = 0;
		for (int i = 0; i < v.size(); i++){
			if (v[i] != mex){
				break;
			}
			mex++;
		}
		
		long long ans = 1ll * (cnt0-1) * mex;
		for (int i = v.size()-1; i >= 0; i--){
			int a = v[i], c = cnt[v[i]];
			dp[a] = 1ll * (c-1) * mex + min(mex,a);
			for (int j = i+1; j < v.size(); j++){
				int aa = v[j];
				dp[a] = min(dp[a], 1ll * (c-1) * min(mex, aa) + min(mex,a) + dp[aa]);
			}
			ans = min(ans, dp[a] + 1ll * (cnt0-1) * a);
		}
		cout << ans << '\n';
	}
	return 0;
}
