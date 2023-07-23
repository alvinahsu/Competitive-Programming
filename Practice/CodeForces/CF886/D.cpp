/*
*  File: CF886D
*  Author: Alvin Hsu
*  Date: 07/23/2023 15:07:49
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
		int n,k;
		cin >> n >> k;
		vector<int>v(n);
		for (auto &a : v){
			cin >> a;
		}
		sort(v.begin(), v.end());
		int seg = 1, ans = n;
		for (int i = 1; i < n; i++){
			if (v[i] - v[i-1] > k){
				ans = min(n - seg, ans);
				seg = 1;
			}
			else {
				seg++;
			}
		}
		ans = min(n - seg, ans);
		cout << ans << '\n';
	}
	return 0;
}
