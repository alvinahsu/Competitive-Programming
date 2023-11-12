/*
*  File: CF867D
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
		set<int> seen;
		vector<int> m(n);
		int l = 0, r = n-1;
		for (int i = 0; i < n; i++){
			if (i%2 == 0){
				m[i] = l++;
			}
			else {
				m[i] = r--;
			}
		}
		long long sum = n;
		bool ok = true;
		vector<int> ans(n);
		ans[0] = n;
		for (int i = 1; i < n; i++){
			int have = sum%n;
			if (have > m[i]){
				int take = n + m[i] - have;
				if (seen.count(take)) ok = false;
				ans[i] = take;
				seen.insert(take);
				sum += take;
			}
			else {
				int take = m[i] - have;
				if (seen.count(take)) ok = false;
				ans[i] = take;
				seen.insert(take);
				sum += take;
			}
		}
		if (!ok){
			cout << -1 << '\n';
		}
		else {
			for (int i = 0; i < n; i++){
				cout << ans[i] << " ";
			}
			cout << '\n';
		}
		
	}
	return 0;
}
