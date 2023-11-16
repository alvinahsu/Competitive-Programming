/*
*  File: CFEDU155A
*  Author: Alvin Hsu
*  Date: 11/14/2023 20:33:57
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
		vector<int> s(n), e(n);
		for (int i = 0; i < n; i++){
			cin >> s[i] >> e[i];
		}
		int w = s[0], m = e[0];
		bool ok = true;
		for (int i = 1; i < n; i++){
			if (s[i] >= w){
				ok &= (e[i] < m);
			}
		}
		cout << (ok ? w : -1) << '\n';
	}
	return 0;
}
