/*
*  File: CFEDU158B
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
		int n;
		cin >> n;
		vector<int> v(n);
		for (int i = 0; i < n; i++){
			cin >> v[i];
		}
		int ans = 0;
		for (int i = 0; i < n; i++){
			int l = !i ? 0 : v[i-1];
			if (v[i] > l) ans += v[i] - l;
		}
		cout << ans - 1 << '\n';
	}
	return 0;
}
