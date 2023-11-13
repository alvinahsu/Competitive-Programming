/*
*  File: CF899C
*  Author: Alvin Hsu
*  Date: 11/12/2023 20:02:28
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
		long long ans = 0;
		vector<long long> pref(n+1);
		for (int i = 0; i < n; i++){
			pref[i+1] = pref[i] + max(0, v[i]);
		}
		for (int i = 0; i < n; i++){
			ans = max(ans, ((i+1)&1?v[i]:0)+(pref[n]-pref[i+1]));
		}
		cout << ans << '\n';
	}
	return 0;
}
