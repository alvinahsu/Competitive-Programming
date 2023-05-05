/*
*  File: CF870A
*  Author: Alvin Hsu
*  Date: 05/05/2023 07:28:53
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
		for (auto &a : v){
			cin >> a;
		}
		sort(v.begin(), v.end());
		int ans = -1;
		//# of liars
		for (int i = 0; i <= n; i++){
			auto truth = upper_bound(v.begin(), v.end(), i) - v.begin();
			if (n - truth == i){
				ans = i;
				break;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
