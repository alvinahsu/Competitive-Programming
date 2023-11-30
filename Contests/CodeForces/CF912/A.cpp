/*
*  File: CF912A
*  Author: Alvin Hsu
*  Date: 11/30/2023 08:28:47
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
		int n,k;
		cin >> n >> k;
		vector<int> v(n);
		for (int i = 0; i < n; i++){
			cin >> v[i];
		}
		if (is_sorted(v.begin(), v.end()) || k > 1){
			cout << "YES" << '\n';
		}
		else {
			cout << "NO" << '\n';
		}
	}
	return 0;
}
