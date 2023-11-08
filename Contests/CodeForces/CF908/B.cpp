/*
*  File: CF908B
*  Author: Alvin Hsu
*  Date: 11/07/2023 06:28:00
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
		vector<int> a(n);
		vector<int> cnt(101);
		for (auto &it : a){
			cin >> it;
			cnt[it]++;
		}
		int have = 0;
		for (int i = 1; i <= 100; i++){
			if (cnt[i] > 1) have++;
		}
		if (have < 2){
			cout << -1 << '\n';
			continue;
		}
		vector<int> mp(101, -1);
		vector<int> ans(n);
		bool ok = true;
		bool f = false;
		for (int i = 0; i < n; i++){
			if (mp[a[i]] == -1 && cnt[a[i]] > 1){
				if (!f){
					mp[a[i]] = 2;
					f^=1;
				}
				else {
					mp[a[i]] = 3;
				}
				ans[i] = mp[a[i]];
			}
			else {
				ans[i] = 1;
			}
		}
		for (int i = 0; i < n; i++){
			cout << ans[i] << " \n"[i == n-1];
		}
	}
	return 0;
}
