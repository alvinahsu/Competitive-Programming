/*
*  File: AC297A
*  Author: Alvin Hsu
*  Date: 11/04/2023 09:03:51
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
	int n,d;
	cin >> n >> d;
	vector<int>v(n);
	for (auto &a : v){
		cin >> a;
	}
	for (int i = 1; i < n; i++){
		if (v[i] - v[i-1] <= d){
			cout << v[i] << '\n';
			return 0;
		}
	}
	cout << -1 << '\n';
	return 0;	
}
