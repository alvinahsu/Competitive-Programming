/*
*  File: CF875A
*  Author: Alvin Hsu
*  Date: 05/29/2023 14:02:52
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
		vector<int>v(n);
		for (auto &a : v){
			cin >> a;
		}
		for (int i = 0; i < n; i++){
			cout << (n+1) - v[i] << ' ';
		}
		cout << '\n';
	}
	return 0;
}
