/*
*  File: CF818D
*  Author: Alvin Hsu
*  Date: 04/28/2023 08:06:22
*/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../../Templates/debug.h"
#else
#define dbg(...)
#endif

const int MAXN = 2e5;
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
	init(MAXN);
	int n,k;
	cin >> n >> k;
	long long ans = 0;
	for (int i = 0; i <= min(n,k); i++){
		(ans += nck(n, i)) %= MOD;
	}
	cout << ans%MOD << '\n';
	return 0;
}
