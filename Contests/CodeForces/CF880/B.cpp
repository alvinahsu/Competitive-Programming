/*
*  File: CF880B
*  Author: Alvin Hsu
*  Date: 06/18/2023 10:25:10
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
		long long n,k,g;
		cin >> n >> k >> g;
		long long half = (g+1) / 2 - 1;
		long long tot = 1ll* k * g;
		long long take = min(n-1, !half ? n-1 : tot / half);
		long long ans = half * take;
		long long x = tot - half * take;
		long long r = x % g;
		if (r >= (g+1)/2){
			ans += (x - (x + (g - r)));
		}
		else {
			ans += (x - (x - r));
		}
		cout << ans << '\n';
	}
	return 0;
}
