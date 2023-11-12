/*
*  File: CFEDU147D
*  Author: Alvin Hsu
*  Date: 04/20/2023 22:27:43
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
		vector<int> l(n), r(n);
		for (int i = 0; i < n; i++){
			cin >> l[i];
		}
		int sum = 0;
		for (int i = 0; i < n; i++){
			cin >> r[i];
			sum += (r[i] - l[i] + 1);
		}
		if (sum < k){
			cout << -1 << '\n';
			continue;
		}
		priority_queue<int, vector<int>, greater<>> seg;
		int ans = 1e9+5, have = 0, curr = 0;
		for (int i = 0; i < n; i++){
			int sz = r[i] - l[i] + 1;
			assert(k - have >= 0);
			int take = min(k - have, sz);
			int left = sz - take;
			have += take;
			if (take){
				curr += (take + 1);
			}
			curr += (l[i] - (i ? r[i-1] : 0));	
			if (have == k){
				ans = min(ans, curr);
			}
			if (!take && seg.size() && seg.top() <= left){
				curr += 2;
			}
			bool f = take;
			while(seg.size() && seg.top() <= left){
				f = true;
				int top = seg.top();
				curr -= 2;
				have -= top;
				curr += min(top, left);
				have += min(top, left);
				left -= top;
				if (have == k) {
					ans = min(ans, curr);
				}
				seg.pop();
			}
			if (left < 0){
				have += left;
			}
			if (f) {
				seg.push(sz);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}