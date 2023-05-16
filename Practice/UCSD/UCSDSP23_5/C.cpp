/*
*  File: UCSDSP23_5C
*  Author: Alvin Hsu
*  Date: 05/15/2023 18:17:26
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
	int up = 1 << n;
	int mn = 2e9;
	for (int i = 0; i < up; i++){
		int check = 0, curr = 0;
		for (int j = 0; j < n; j++){
			//start new
			if (i&(1 << j)) {
				check ^= curr;
				curr = v[n-j-1];
			}
			//keep
			else {
				curr |= v[n-j-1];
			}
		}
		check ^= curr;
		mn = min(mn, check);
	}
	cout << mn << '\n';
	return 0;
}
