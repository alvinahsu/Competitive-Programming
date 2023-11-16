/*
*  File: CFEDU155D
*  Author: Alvin Hsu
*  Date: 11/14/2023 20:33:57
*/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../../Templates/debug.h"
#else
#define dbg(...)
#endif

const int MOD = 998244353;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	long long ans = 0;	
	for (int b = 0; b < 31; b++){
		long long sum[2] = {0,0};
		//0 is even, 1 is odd
		int cnt[2] = {0,0};
		//empty prefix is 0
		cnt[0] = 1;
		int f = 0;
		long long contr = 0;
		for (int i = 0; i < n; i++){
			//flip opposite
			if ((a[i]>>b)&1) f ^= 1;
			//sum of r = total comb * r
			long long pos = (1ll * cnt[f^1] * (i+1)) % MOD;
			//sum of l = sum of opposite
			(contr += pos - sum[f^1] + MOD) %= MOD; 
			(sum[f] += (i+1)) %= MOD;
			cnt[f]++;
		}
		(ans += ((1 << b) * contr) % MOD) %= MOD;
	}
	cout << ans << '\n';
	return 0;
}
