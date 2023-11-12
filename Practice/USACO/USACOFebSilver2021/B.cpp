/*
*  File: USACOFebSilver2021B
*  Author: Alvin Hsu
*  Date: 08/28/2023 19:22:54
*/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../../Templates/debug.h"
#else
#define dbg(...)
#endif

//Since we can only go from/to at multiples of 12
//if an ancestor lies within some segment [x:x+12],
//it makes sense to teleport if these segments are disjoint
//thus, we remove the k-1 largest segments we possibly can

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,k;
	cin >> n >> k;
	vector<int> v(n);
	for (auto &a : v){
		cin >> a;
	}
	set<pair<int,int>> gap;
	for (int i = 0; i < n; i++){
		int prev = v[i] / 12 * 12;
		int next = (v[i]+11) / 12 * 12;
		gap.insert({prev,next});
	}
	vector<int> seg;
	int last = 0;
	for (auto it = gap.begin(); it != gap.end(); it++){
		assert(it -> first >= last);
		seg.push_back(it -> first - last);
		last = it -> second;
	}
	sort(seg.rbegin(), seg.rend());
	int mx = *max_element(v.begin(), v.end());
	int start = (mx+11) / 12 * 12;
	for (int i = 0; i < min((int)seg.size(),k-1); i++){
		start -= seg[i];
	}
	cout << start << '\n';
	return 0;
}
