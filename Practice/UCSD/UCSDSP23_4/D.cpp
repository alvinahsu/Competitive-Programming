/*
*  File: UCSDSP23_4D
*  Author: Alvin Hsu
*  Date: 05/08/2023 20:22:09
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
	int n;
	cin >> n;
	vector<pair<int,int>> v(n);
	for (auto &a : v){
		cin >> a.first >> a.second;
	}
	sort(v.begin(), v.end());
	vector<pair<int,int>> ans;
	for (int i = 0; i < n; i++){
		auto [start,end] = v[i];
		if (ans.empty() || start > ans.back().second){
			ans.push_back(v[i]);
		}
		else {
			ans.back().second = max(ans.back().second, end);
		}
	}
	for (int i = 0; i < ans.size(); i++){
		cout << ans[i].first << " " << ans[i].second << '\n';
	}
	return 0;
}
