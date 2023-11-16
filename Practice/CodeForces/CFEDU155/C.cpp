/*
*  File: CFEDU155C
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

const int MAXN = 2e6+5;
const int MOD = 998244353;
long long factorial[MAXN];

int inv(int i) {
  return i <= 1 ? i : MOD - (long long)(MOD/i) * inv(MOD % i) % MOD;
}

long long nck(int n, int k) {
	if (k > n) return 0;
	return factorial[n] * inv(factorial[k] * factorial[n - k] % MOD) % MOD;
}

void init(int N){
	factorial[0] = 1;
	for (int i = 1; i < N; i++) {
	    factorial[i] = factorial[i - 1] * i % MOD;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	init(MAXN);
	while(t--){
		string s;
		cin >> s;
		int n = s.size();
		vector<long long> seg;
		char c = s[0];
		int cnt = 0;
		for (int i = 0; i < n; i++){
			if (s[i] != c){
				seg.push_back(cnt);
				cnt = 1;
				c = s[i];
			}
			else {
				cnt++;
			}
		}
		seg.push_back(cnt);
		long long ans = 0, ways = 1;
		for (int i = 0; i < seg.size(); i++){
			ways = (ways * seg[i]) % MOD;
			ans += (seg[i]-1);
		}
		ways = (ways * factorial[ans]) % MOD;
		cout << ans << " " << ways << '\n';
	}
	return 0;
}
