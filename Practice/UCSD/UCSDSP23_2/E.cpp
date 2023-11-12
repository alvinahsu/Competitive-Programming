/*
*  File: UCSDSP23_2E
*  Author: Alvin Hsu
*  Date: 04/24/2023 18:01:48
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
	vector<int>v(n);
	for (auto &a : v){
		cin >> a;
	}
	sort(v.begin(), v.end());
	vector<int> pos;
	for (int i = 1; i < n; i++){
		int m = v[i] - v[i-1];
		if (m >= 3) {
			pos.push_back(m);
		}
	}
	map<int, int> cnt;
	int ans = -1;
	for (auto &m : pos){
		cnt.clear();
		for (int i = 0; i < n; i++){
			cnt[v[i]%m]++;
		}
		for (auto &a : cnt){
			if (a.second >= n/2 + 1) {
				ans = m;
			}
		}
	}
	cout << ans << '\n';
	return 0;
}