/*
*  File: CF876B
*  Author: Alvin Hsu
*  Date: 06/03/2023 10:12:28
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
		vector<pair<int,int>> v(n);
		for (int i = 0; i < n; i++){
			cin >> v[i].first >> v[i].second;
		}
		sort(v.begin(), v.end(), [&](auto f, auto s){
			if (f.first == s.first) return f.second > s.second;
			return f.first < s.first;
		});
		long long ans = 0;
		int on = 0;
		priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
		for (int i = 0; i < n; ){
			if (i < n){
				on++;
				pq.push(v[i]);
				ans += v[i].second;
			}
			int rem = 0;
			while(pq.size() && pq.top().first <= on){
				pq.pop();
				rem++;
			}
			bool add = true;
			while(i < n && v[i].first <= on) {
				add = false;
				i++;
			}
			i += add;
			on -= rem;
		}
		cout << ans << '\n';
	}
	return 0;
}
