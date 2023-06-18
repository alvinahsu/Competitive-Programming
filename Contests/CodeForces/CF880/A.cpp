/*
*  File: CF880A
*  Author: Alvin Hsu
*  Date: 06/18/2023 10:25:10
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
		vector<int> cnt(101);
		int n;
		cin >> n;
		for (int i = 0; i < n; i++){
			int x;
			cin >> x;
			cnt[x]++;
		}
		bool ok = true;
		for (int i = 1; i <= 101; i++){
			ok &= (cnt[i-1] >= cnt[i]);
		}
		cout << (ok ? "YES" : "NO") << '\n';
	}
	return 0;
}
