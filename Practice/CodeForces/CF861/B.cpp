/*
*  File: CF861B
*  Author: Alvin Hsu
*  Date: 04/04/2023 20:17:54
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
		int n,m;
		cin >> n >> m;
		vector<vector<int>>v(n,vector<int>(m));
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				cin >> v[i][j];
			}
		}
		vector<vector<long long>> pref(n+1, vector<long long>(m));
		for (int i = 0; i < m; i++){
			for (int j = 0; j < n; j++){
				pref[j+1][i] = pref[j][i] + v[j][i];
			}
		}
		long long ans = 0;
		for (int i = 1; i <= n; i++){
			for (int j = 0; j < m; j++){
				long long tot = pref[n][j] - pref[i][j];
				dbg(tot);		
				tot -= (n - i) * v[i-1][j];
				ans += abs(tot);
			}
			dbg(ans);
		}
		cout << ans << '\n';
	}
	
	return 0;	
}
