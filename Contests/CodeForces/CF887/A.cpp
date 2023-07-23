/*
*  File: CF887A
*  Author: Alvin Hsu
*  Date: 07/23/2023 10:22:36
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
		for (auto &a : v){
			cin >> a;
		}
		int ans = 1e9;
		for (int i = 1; i < n; i++){
			if (v[i] < v[i-1]) ans = 0;
			else {
				ans = min(ans, (v[i] - v[i-1])/2 + 1);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
