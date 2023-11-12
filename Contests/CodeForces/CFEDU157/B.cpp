/*
*  File: CFEDU157B
*  Author: Alvin Hsu
*  Date: 11/03/2023 07:32:05
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
		vector<int> v(2*n);
		for (auto &it : v){
			cin >> it;
		}
		sort(v.begin(), v.end());
		int ans = 0;
		vector<pair<int,int>> ret;
		for (int i = 0, j = 2*n-1; i < j; i++,j--){
			ret.push_back({v[i],v[j]});
		}
		assert(ret.size() == n);
		for (int i = 1; i < n; i++){
			ans += abs(ret[i].first - ret[i-1].first);
			ans += abs(ret[i].second - ret[i-1].second);
		}
		cout << ans << '\n';
		for (int i = 0; i < n; i++){
			cout << ret[i].first << " " << ret[i].second << '\n';
		}
	}
	return 0;
}
