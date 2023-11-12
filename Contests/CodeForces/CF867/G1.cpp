/*
*  File: CF867G1
*  Author: Alvin Hsu
*  Date: 04/24/2023 08:41:33
*/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../../Templates/debug.h"
#else
#define dbg(...)
#endif
const int MAXN = 2e5 + 5;
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
	for (int i = 1; i <= N; i++) {
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
		int n;
		cin >> n;
		vector<int>v(n);
		for (auto &a : v){
			cin >> a;
		}
		sort(v.begin(), v.end());
		map<long long,long long> cnt;
		long long ans = 0;
		for (int i = 0; i < n; i++){
			for (int b = 2; b*b <= v[i]; b++){
				if (v[i] % b == 0){
					int j = v[i] / b;
					if (j % b == 0){
						ans += (cnt[j] * cnt[j / b]);
					}
					if (v[i] / b != b){
						int tryB = v[i] / b;
						if (j % tryB == 0){
							int dj = v[i] / tryB;
							if (dj % tryB == 0){
								ans += (cnt[dj] * cnt[dj / tryB]);
							}
						}
					}
				}
			}
			cnt[v[i]]++;
		}
		for (auto &a : cnt){
			if (a.second >= 3){
				ans += a.second * (a.second - 1) * (a.second-2);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
