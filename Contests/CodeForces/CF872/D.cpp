/*
*  File: CF872D
*  Author: Alvin Hsu
*  Date: 05/08/2023 05:01:11
*/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../../Templates/debug.h"
#else
#define dbg(...)
#endif
#include <bits/stdc++.h>
using namespace std;

int MOD = 1e9+7;
int inv(int i) {
  return i <= 1 ? i : MOD - (long long)(MOD/i) * inv(MOD % i) % MOD;
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,k;
	cin >> n >> k;
	for (int i = 0; i < n-1; i++){
		int u,v;
		cin >> u >> v;
	}
	if (k&1){
		cout << 1 << '\n';
	}
	else {
		long long p = (n-1)*(n-2) + n, q = n * (n-1) / 2;
		cout << (1ll * inv(q) * p)%MOD << '\n';
	}
	return 0;
}
