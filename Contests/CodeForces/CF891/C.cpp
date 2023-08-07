/*
*  File: CF891C
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

const int inf = 1e9+5;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> v(n * (n-1) / 2);
		map<int,int> cnt;
		for (auto &a : v){
			cin >> a;
			cnt[a]++;
		}
		set<int> rem;
		for (int i = 0; i < n; i++){
			rem.insert(i);
		}
		int i = n-1;
		vector<int> ans(n, -inf);
		for (auto [x,y] : cnt){
			while(y){
				auto it = rem.upper_bound(y);
				assert(it != rem.begin());
				it--;
				assert(ans[*it] == -inf);
				ans[*it] = x;
				y -= *it;
				rem.erase(it);
			}
		}
		assert(count(ans.begin(), ans.end(), -inf) <= 1);
		for (int j = 0; j < n; j++){
			if (ans[j] == -inf){
				ans[j] = 1e9;
			}
		}
		for (int j = 0; j < n; j++){
			cout << ans[j] << " \n"[j==n-1];
		}
	}
	return 0;
}
