/*
*  File: CF865C
*  Author: Alvin Hsu
*  Date: 09/04/2023 21:13:12
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
		vector<long long>v(n);
		for (auto &a : v){
			cin >> a;
		}
		for (int i = 0; i+1 < n; i++){
			long long diff = 0ll - v[i];
			v[i] += diff;
			v[i+1] += diff;
		}
		assert(count(v.begin(),v.end(), 0) >= n-1);
		bool ok = (v[n-2] <= v[n-1] || (n&1));
		cout << (ok ? "YES" : "NO") << '\n';
	}
	return 0;	
}
