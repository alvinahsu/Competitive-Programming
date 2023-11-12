/*
*  File: CF873C
*  Author: Alvin Hsu
*  Date: 05/14/2023 07:33:14
*/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../../Templates/debug.h"
#else
#define dbg(...)
#endif
int MOD = (int)1e9 + 7;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int>a(n), b(n);
		for (int i = 0; i < n; i++){
			cin >> a[i];
		}
		for (int i = 0; i < n; i++){
			cin >> b[i];
		}
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		long long ans = 1;
		for (int i = 0; i < n; i++){
			auto l = lower_bound(b.begin()+i, b.end(), a[i]) - b.begin() - i;
			(ans *= l) %= MOD;
		}
		cout << ans << '\n';
	}
	return 0;
}
