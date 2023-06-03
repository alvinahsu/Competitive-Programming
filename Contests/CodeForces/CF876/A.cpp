/*
*  File: CF876A
*  Author: Alvin Hsu
*  Date: 06/03/2023 10:12:28
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
	int t;
	cin >> t;
	init(MAXN);
	while(t--){
		int n,k;
		cin >> n >> k;
		int l = 1, r = 100;
		auto check = [&](int m){
			int cntL = 0, cntR = 0;
			vector<int> a(n+1);
			for (int i = 1; i <= n; i++){
				cntL += a[i];
				cntR += a[n-i+1];
				int up = (i + k - 1) / k;
				bool markL = false, markR = false;
				if (cntL < up){
					if (a[i] == 1) return false;
					markL = true;
					cntL++;
				}
				if (cntR < up){
					if (a[n-i+1] == 1) return false;
					markR = true;
					cntR++;
				}
				a[i] = markL;
				a[n-i+1] = markR;
			}
			return cntL <= m;
		};
		while(l < r){
			int m = l + (r - l) / 2;
			if (check(m)){
				r = m;
			}
			else {
				l = m+1;
			}
		}
		cout << l << '\n';
	}
	return 0;
}
