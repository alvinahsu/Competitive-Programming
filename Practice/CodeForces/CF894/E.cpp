/*
*  File: CF894E
*  Author: Alvin Hsu
*  Date: 08/24/2023 13:32:25
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
		int n,m,d;
		cin >> n >> m >> d;
		vector<int> a(n);
		long long ans = 0;
		for (int i = 0; i < n; i++){
			cin >> a[i];
		}
		priority_queue<int, vector<int>, greater<>> pq;
		long long tot = 0;
		for (int i = 0; i < n; i++){
			if (a[i] < 0) continue;
			tot += a[i];
			pq.push(a[i]);
			if (pq.size() > m) {
				tot -= pq.top();
				pq.pop();
			}
			ans = max(ans, tot - 1ll * (i+1) * d);
		}
		cout << ans << '\n';
	}
	return 0;
}
