/*
*  File: CF874F
*  Author: Alvin Hsu
*  Date: 05/19/2023 07:31:18
*/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../../Templates/debug.h"
#else
#define dbg(...)
#endif

const int MAXN = 2e6+5;
long long factorial[MAXN];
int MOD = (int)1e9+7;

int inv(int i) {
  return i <= 1 ? i : MOD - (long long)(MOD/i) * inv(MOD % i) % MOD;
}

long long nck(int n, int k) {
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
	init(MAXN);
	int t;
	cin >> t;
	while(t--){
		int n,m;
		cin >> n >> m;
		vector<int>v(n);
		map<int,int> cnt;
		for (auto &a : v){
			cin >> a;
			cnt[a]++;
		}
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
		long long ans = 0;
		int l = 0;
		long long fact = 1;
		int i = 0;
		for (; i < v.size(); i++){
			if (v[i] - v[l] >= m){
				if (i - l >= m){
					(ans += nck(i-l, m) * fact) %= MOD;
				}
			}
			(fact *= cnt[v[i]]) %= MOD;
			while(l < i && v[i] - v[l] >= m) {
				fact = (fact*inv(cnt[v[l]])) % MOD;
				l++;
			}
			assert(fact >= 1);
		}
		if (v[i-1] - v[l] < m){
			if (i - l >= m){
				(ans += nck(i-l, m) * fact) %= MOD;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
