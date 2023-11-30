/*
*  File: CFEDU158A
*  Author: Alvin Hsu
*  Date: 11/28/2023 20:12:02
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
		int n,x;
		cin >> n >> x;
		vector<int> a(n);
		for (int i = 0; i < n; i++){
			cin >> a[i];
		}
		int ans = 0;
		for (int i = 0; i < n; i++){
			int need = a[i] - (!i ? 0 : a[i-1]);
			ans = max(ans, need);
		}
		ans = max(ans, 2 * (x - a[n-1]));
		cout << ans << '\n';
	}
	return 0;
}
