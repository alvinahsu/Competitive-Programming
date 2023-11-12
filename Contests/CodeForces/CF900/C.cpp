/*
*  File: CF900C
*  Author: Alvin Hsu
*  Date: 09/26/2023 07:25:15
*/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../../Templates/debug.h"
#else
#define dbg(...)
#endif

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		long long n,k,x;
		cin >> n >> k >> x;
		long long lb = k * (k + 1) / 2;
		long long up = n * (n + 1) / 2 - ((n - k) * (n - k + 1) / 2);
		assert(lb <= up);
		bool ok = lb <= x && x <= up;
		cout << (ok ? "YES" : "NO") << '\n';
	}
	return 0;
}
