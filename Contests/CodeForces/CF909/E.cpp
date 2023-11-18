/*
*  File: CF909E
*  Author: Alvin Hsu
*  Date: 11/17/2023 00:21:57
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
		for (int i = 0; i < n; i++){
			cin >> v[i];
		}
		int mn = *min_element(v.begin(), v.end());
		int idx = 0;
		bool ok = true;
		while(v[idx] != mn) idx++;
		for (int i = idx+1; i < n; i++){
			ok &= (v[i] >= v[i-1]);
		}
		if (!ok){
			cout << -1 << '\n';
			continue;
		}
		cout << idx << '\n';
		
	}
	return 0;
}
