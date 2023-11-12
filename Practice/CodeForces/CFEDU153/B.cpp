/*
*  File: CFEDU153B
*  Author: Alvin Hsu
*  Date: 08/20/2023 10:44:49
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
		int m,k,a1,ak;
		cin >> m >> k >> a1 >> ak;
		//1,k
		int cnt = 0;
		int curr = min(ak,m/k) * k;
		int left = m - curr;
		assert(curr <= m);
		int next = curr % k;
		int need = m%k;
		int off = (m%k - next);
		if (off < 0) off += k;
		if (off > a1){
			cnt += (off - a1);
			a1 = 0;
		}
		else {
			a1 -= off;
		}
		curr += off;
		int take = min(a1 / k, (m - curr) / k);
		curr += take * k;
		assert((m - curr) % k == 0);
		cnt += (m - curr) / k;
		cout << cnt << '\n';
	}
	return 0;
}
