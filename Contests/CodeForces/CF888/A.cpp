/*
*  File: CF888A
*  Author: Alvin Hsu
*  Date: 07/25/2023 10:28:24
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
		int n,m,k,h;
		cin >> n >> m >> k >> h;
		vector<int> v(n);
		for (auto &a : v){
			cin >> a;
		}
		int ans = 0;
		for (int i = 0; i < n; i++){
			bool ok = false;
			for (int j = 1; j <= m; j++){
				for (int l = j+1; l <= m; l++){
					long long diff = k * (abs(j - l));
					ok |= (abs(h - v[i]) == diff);
				}
			}
			ans += ok;
		}
		cout << ans << '\n';
	}
	return 0;
}
