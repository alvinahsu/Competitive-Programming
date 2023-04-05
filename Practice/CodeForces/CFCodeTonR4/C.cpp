/*
*  File: CFCodeTonR4C
*  Author: Alvin Hsu
*  Date: 05/04/2023 16:48:24
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
		int n,c,d;
		cin >> n >> c >> d;
		vector<int>v(n);
		set<int> seen;
		long long ans = 0;
		for (auto &a : v){
			cin >> a;
			if (!seen.insert(a).second) {
				ans += c;
			}
		}
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
		long long add = 1ll * v.size() * c + d;
		long long curr = 0;
		for (int i = 0; i < v.size(); i++){
			int prev = i-1 >= 0 ? v[i-1] : 0;
			int diff = v[i] - prev - 1;
			curr += (1ll * diff * d);
			add = min(add, curr + 1ll * ((int)v.size() - i - 1) * (c));
		}
		ans += add;
		cout << ans << '\n';
		
	}
	return 0;	
}
