/*
*  File: CF888D
*  Author: Alvin Hsu
*  Date: 07/25/2023 10:28:24
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
		vector<long long> v(n-1), diff(n-1);
		for (int i = 0; i < n-1; i++){
			cin >> v[i];
			diff[i] = i ? v[i] - v[i-1] : v[i];
		}
		sort(diff.begin(), diff.end());
		int ok = true, dup = 0;
		for (int i = 0; i+1 < n-1; i++){
			if (diff[i] == diff[i+1]){
				dup++;
				if (diff[i] == 1) ok = false;
			}
		}
		ok &= (dup <= 1);
		if (!ok){
			cout << "NO" << '\n';
			continue;
		}
		vector<int> ans(n+1);
		for (int i = 0; i < n-1; i++){
			if (diff[i] <= n) ans[diff[i]]++;
		}
		int missing = 0;
		int cnt = 0;
		for (int i = 1; i <= n; i++){
			if (!ans[i]) {
				missing+=i;
				cnt++;
			}
		}
		ok &= cnt <= 2;
		if (cnt == 2){
			if (dup){
				for (int i = 1; i <= n; i++){
					if (ans[i] == 2){
						ok &= (i == missing);
					}
				}
			}
			else {
				ok &= (diff.back() == missing);
			}
		}
		cout << (ok ? "YES" : "NO") << '\n';
		
	}
	return 0;
}
