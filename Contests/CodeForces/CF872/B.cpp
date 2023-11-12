/*
*  File: CF872B
*  Author: Alvin Hsu
*  Date: 05/08/2023 05:01:11
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
		int n,m;
		cin >> n >> m;
		vector<int>v(n*m);
		for (auto &a : v){
			cin >> a;
		}
		sort(v.begin(), v.end());
		if (n > m) swap(n, m);
		int ans = 0;
		//max top left
		ans += (m-1) * (v.back() - v[0]);
		ans += (n-1) * (v.back() - v[1]);
		ans += (m-1) * (n-1) * (v.back() - min(v[0], v[1]));
		int ans2 = 0;
		//min top left
		ans2 += (m-1) * (v.back() - v[0]);
		ans2 += (n-1) * (v[n*m-2] - v[0]);
		ans2 += (m-1) * (n-1) * (max(v.back(), v[n*m-2]) - v[0]);
		
		cout << max(ans, ans2) << '\n';
	}
	return 0;
}
