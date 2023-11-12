/*
*  File: CF891D
*  Author: Alvin Hsu
*  Date: 08/07/2023 09:56:12
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
		vector<int> a(n), b(n);
		for (int i = 0; i < n; i++){
			cin >> a[i];
		}
		for (int i = 0; i < n; i++){
			cin >> b[i];
		}
		vector<pair<int,int>> diff(n);
		int mx = INT_MIN;
		for (int i = 0; i < n; i++){
			diff[i] = {a[i] - b[i], i};
			mx = max(mx, diff[i].first);
		}
		sort(diff.begin(), diff.end());
		vector<int> ans;
		for (int i = 0; i < n; i++){
			if (diff[i].first == mx){
				ans.push_back(diff[i].second);
			}
		}
		sort(ans.begin(), ans.end());
		cout << ans.size() << '\n';
		for (int i = 0; i < ans.size(); i++){
			cout << ans[i]+1 << " \n"[i == ans.size()-1];
		}
	}
	return 0;
}
