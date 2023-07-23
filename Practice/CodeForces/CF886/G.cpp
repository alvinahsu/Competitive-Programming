/*
*  File: CF886G
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
		int n;
		cin >> n;
		vector<pair<int,int>> v(n);
		map<int,long long> X,Y,L,R;
		for (int i = 0; i < n; i++){
			cin >> v[i].first >> v[i].second;
			X[v[i].first]++;
			Y[v[i].second]++;
			L[v[i].first-v[i].second]++;
			R[v[i].first+v[i].second]++;
		}
		long long ans = 0;
		for (auto [_,x] : X){
			ans += x * (x - 1);
		}
		for (auto [_,x] : Y){
			ans += x * (x - 1);
		}
		for (auto [_,x] : L){
			ans += x * (x - 1);
		}
		for (auto [_,x] : R){
			ans += x * (x - 1);
		}
		cout << ans << '\n';
	}
	return 0;
}
