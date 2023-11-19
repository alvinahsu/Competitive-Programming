/*
*  File: CF910B
*  Author: Alvin Hsu
*  Date: 11/19/2023 06:28:26
*/
 
#include <bits/stdc++.h>
using namespace std;
 
#ifdef LOCAL
#include "../../Templates/debug.h"
#else
#define dbg(...)
#endif
 
int main(){
	#define int long long
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
		int ans = 0;
		for (int i = n-2; i >= 0; i--){
			int k = (v[i]+v[i+1]-1)/v[i+1]-1;
			ans += k;
			v[i] /=(k+1);
		}
		cout << ans << '\n';
	}
	return 0;
}