/*
*  File: CF871H
*  Author: Alvin Hsu
*  Date: 05/06/2023 07:41:20
*/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../../Templates/debug.h"
#else
#define dbg(...)
#endif

int MOD = (int)1e9+7;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t;
	cin >> t;
	while(t--){
		int n,k;
		cin >> n >> k;
		long long ans = 0;
		vector<int>v(n), vis(64);		
		for (auto &a : v){
			cin >> a;
		}
		vector<vector<long long>>dp(n+1, vector<long long>(64));
		for (int i = 1; i <= n; i++){
			//start a new sequence
			(dp[i][v[i-1]] += 1) %= MOD;
			for (int j = 0; j < 64; j++){
				//don't use
				(dp[i][j] += dp[i-1][j]) %= MOD;
				//use with previous sequence
				(dp[i][j&v[i-1]] += dp[i-1][j]) %= MOD;
			}
		}
		for (int i = 0; i < 64; i++){
			if (__builtin_popcount(i) == k) {
				(ans += dp[n][i]) %= MOD;
			}
		}		
		cout << ans << '\n';
	}
	return 0;
}
