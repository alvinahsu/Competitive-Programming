/*
*  File: UCSDSP23_2D
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
	int n,m;
	cin >> n >> m;
	vector<set<int>> pos(2e5+5);
	auto getT = [&](int n, int i){
		int l = 0, r = 2e5+5;
		while(l < r){
			int m = l + (r - l) / 2;
			if (n + (1ll * m * i) >= 0){
				r = m;
			}
			else {
				l = m+1;
			}
		}
		return l;
	};
	for (int i = 0; i < n; i++){
		int a;
		cin >> a;
		int t = getT(a, i+1);
		if (t <= (int)2e5){
			a += t * (i+1);
		}
		else {
			continue;
		}
		while(t <= 2e5 && a <= (int)2e5){
			pos[t].insert(a);
			a += (i+1);
			t++;
		}
	}
	for (int i = 1; i <= m; i++){
		int mex = 0;
		for (auto &j : pos[i]){
			if (j != mex) break;
			mex++;
		}
		cout << mex << '\n';
	}
	return 0;
}
