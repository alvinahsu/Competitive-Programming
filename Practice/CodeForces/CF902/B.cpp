/*
*  File: CF902B
*  Author: Alvin Hsu
*  Date: 11/09/2023 20:49:00
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
		int n,p;
		cin >> n >> p;
		vector<int> a(n), b(n);
		vector<pair<int,int>> v;
		
		for (int i = 0; i < n; i++){
			cin >> a[i];
		}
		for (int i = 0; i < n; i++){
			cin >> b[i];
			v.push_back({b[i], a[i]});
		}
		v.push_back({p, n});
		sort(v.begin(), v.end());
		long long ans = p;
		int rem = n-1;
		for (int i = 0; i < v.size(); i++){
			int take = min(rem, v[i].second);
			rem -= take;
			ans += 1ll * take * v[i].first;
		}
		cout << ans << '\n';
	}
	return 0;
}
