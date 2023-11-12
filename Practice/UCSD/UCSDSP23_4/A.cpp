/*
*  File: UCSDSP23_4A
*  Author: Alvin Hsu
*  Date: 05/08/2023 20:22:09
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
	long long x,a,d,n;
	cin >> x >> a >> d >> n;
	long long ans = abs(x-a);
	if ((x <= a && d >= 0) || (x >= a && d <= 0)) {
	}
	else {
		assert(d != 0);
		long long diff = abs(x-a), times = min(n-1,abs(diff / d));
		assert(times <= n);
		long long low = a + times * d, hi = a + (min(n-1,times + 1)) * d, mid = a + max(0ll, times - 1) * d;
		ans = min({abs(x - low), abs(x - hi), abs(x - mid)});
	}
	cout << ans << '\n';
	return 0;
}