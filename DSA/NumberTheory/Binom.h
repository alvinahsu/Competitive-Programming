#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e6+5;
const int MOD = 1e9+7;
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