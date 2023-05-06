/*
*  File: CF871G
*  Author: Alvin Hsu
*  Date: 05/06/2023 07:41:20
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
	vector<vector<int>> p;
	map<int,pair<int,int>> idx;
	int sz = 1, i = 1;
	while(i <= (int)1e6) {
		vector<int> curr;
		for (int j = 0; j < sz; j++){
			idx[i] = {sz-1, j};
			curr.push_back(i++);
		}
		p.push_back(curr);
		sz++;
	}
	auto S = [&](long long curr){
		return curr * (curr + 1) * (2 * curr + 1) / 6;
	};
	auto getSum = [&](long long l, long long r) {
		return S(r) - S(l);
	};
	function<long long(int,int,int)> branch = [&](int row, int lj, int rj) {
		long long ans = getSum(p[row][lj]-1, p[row][rj]);
		if (row == 0) return ans;
		row--;
		lj = max(0, lj-1);
		rj = min((int)p[row].size()-1, rj);
		ans += branch(row, lj, rj);
		return ans;
	};
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		auto id = idx[n];
		long long ans = branch(id.first, id.second, id.second);
		cout << ans << '\n';		
	}
	return 0;
}
