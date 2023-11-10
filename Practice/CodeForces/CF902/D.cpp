/*
*  File: CF902D
*  Author: Alvin Hsu
*  Date: 11/09/2023 20:49:00
*/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../../Templates/debug.h"
#else
#define dbg(...)
#endif

const int MOD = 998244353;

long long fastpow(long long a, long long b){
	long long ans = 1;
	while(b){
		if (b&1) (ans *= a) %=  MOD;
		(a *= a) %= MOD;
		b >>= 1;
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> v(n+1);
	for (int i = 1; i <= n; i++){
		cin >> v[i];
	}
	vector<int> mx(n+1), cnt(1e6);
	mx[0] = -1;
	set<int> m;
	for (int i = 1; i <= n; i++){
		for (int j = i; j <= n; j+=i){
			mx[i] = max(mx[i], v[j]);
		}
		cnt[mx[i]]++;
		m.insert(mx[i]);
	}
	sort(mx.begin(), mx.end());
	long long ans = 0;
	for (auto &it : m){
		auto tot = lower_bound(mx.begin(), mx.end(), it) - mx.begin() - 1;
		long long cnt1 = (fastpow(2, tot)) * (fastpow(2, cnt[it]) - 1) % MOD;
		(ans += (it * cnt1) % MOD) %= MOD;
	}
	cout << ans << '\n';
	return 0;
}
