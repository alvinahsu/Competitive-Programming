/*
*  File: CF824B
*  Author: Alvin Hsu
*  Date: 05/02/2023 14:40:02
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
		sort(v.begin(), v.end());
		int up = v[0] * 2 - 1;
		int ans = 0;
		for (int i = 0; i < n; i++){
			if (v[i] > up){
				ans += (v[i]-1) / up;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}