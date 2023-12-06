/*
*  File: CFEDU159C
*  Author: Alvin Hsu
*  Date: 12/04/2023 13:44:28
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
	#define int long long
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> v(n);
		set<int> have;
		
		for (int i = 0; i < n; i++){
			cin >> v[i];
			have.insert(v[i]);
		}
		if (n == 1){
			cout << 1 << '\n';
			continue;
		}
		sort(v.begin(), v.end());
		int g = 0;
		for (int i = 1; i < n; i++){
			g = gcd(g, v[i] - v[i-1]);
		}
		int x = v.back();
		while(have.find(x) != have.end()){
			x -= g;
		}
		int ans = (v.back() - x) / g;
		for (int i = 0; i < n; i++){
			ans += (v.back() - v[i]) / g;
		}
		cout << ans << '\n';
	}
	return 0;
}
