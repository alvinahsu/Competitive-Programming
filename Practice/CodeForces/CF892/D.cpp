/*
*  File: CF892D
*  Author: Alvin Hsu
*  Date: 08/14/2023 16:36:22
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
		vector<pair<int,int>> events;
		for (int i = 0; i < n; i++){
			int l,r,a,b;
			cin >> l >> r >> a >> b;
			//end of left bound
			events.emplace_back(l-1,-2);
			//right most bound for this segment
			events.emplace_back(b,-1);
		}
		int q;
		cin >> q;
		vector<int> ans(q);
		for (int i = 0; i < q; i++){
			int x;
			cin >> x;
			//start placement
			events.emplace_back(x,i);
		}
		sort(events.begin(), events.end(), [&](auto a, auto b){
			if (a.first == b.first) return a.second < b.second;
			return a.first > b.first;
		});
		int cnt = 0, mx = 0;
		for (auto &e : events){
			//cannot reach any segment
			if (e.second == -2){
				cnt--;
				if (!cnt) mx = 0;
			}
			//reachable segment
			else if (e.second == -1){
				cnt++;
				mx = max(mx, e.first);
			}
			else {
				ans[e.second] = max(e.first, mx);
			}
		}
		for (int i = 0; i < q; i++){
			cout << ans[i] << " \n"[i == q-1];
		}
	}
	return 0;
}
