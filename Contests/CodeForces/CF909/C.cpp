/*
*  File: CF909C
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
		int ans = v[0], curr = v[0];
		for (int i = 1; i < n; i++){
			if ((v[i]&1) == (v[i-1]&1)){
				curr = v[i];
			}
			else {
				curr = max(curr + v[i], v[i]);
			}
			ans = max(ans, curr);
		}
		cout << ans << '\n';
	}
	return 0;
}
