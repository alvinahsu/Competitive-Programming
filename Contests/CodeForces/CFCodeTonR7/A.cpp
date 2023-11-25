/*
*  File: CFCodeTonR7A
*  Author: Alvin Hsu
*  Date: 11/25/2023 06:28:12
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
		vector<int> v(n);
		for (auto &it : v){
			cin >> it;
		}
		cout << (v[0] == 1 ? "YES" : "NO") << '\n';
	}
	return 0;
}
	