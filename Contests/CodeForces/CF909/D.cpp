/*
*  File: CF909D
*  Author: Alvin Hsu
*  Date: 11/17/2023 00:21:57
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
		int n;
		cin >> n;
		map<int,int> cnt;
		vector<int> a(n);
		for (int i = 0; i < n; i++){
			cin >> a[i];
			cnt[a[i]]++;
		}
		long long ans = 0;
		for (auto &[x,y] : cnt){
			ans += (1ll*y*(y-1)/2);
		}
		ans += 1ll*cnt[1] * cnt[2];
		cout << ans << '\n';
	}
	return 0;
}
