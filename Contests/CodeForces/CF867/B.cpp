/*
*  File: CF867B
*  Author: Alvin Hsu
*  Date: 04/24/2023 07:33:46
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
		vector<int>v(n);
		for (auto &a : v) {
			cin >> a;
		}
		sort(v.begin(), v.end());
		cout << max(1ll * v[0] * v[1], 1ll * v[n-1] * v[n-2]) << '\n';
	}
	return 0;
}
