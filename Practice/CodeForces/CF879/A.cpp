/*
*  File: CF879A
*  Author: Alvin Hsu
*  Date: 06/19/2023 13:38:36
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
		int neg = 0, pos = 0;
		for (int i = 0; i < n; i++){
			int x;
			cin >> x;
			if (x < 0) neg++;
			else pos++;
		}
		int ans = 0;
		while(pos < neg){
			pos++;
			neg--;
			ans++;
		}
		assert(pos >= neg);
		if (neg&1) ans++;
		cout << ans << '\n';
	}
	return 0;
}
