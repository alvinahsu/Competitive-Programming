/*
*  File: CFEDU153C
*  Author: Alvin Hsu
*  Date: 08/20/2023 10:44:49
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
		vector<int> p(n);
		int mn = 1e9, win = 1e9;
		int ans = 0;
		for (int i = 0; i < n; i++){
			cin >> p[i];
			
			//we can move and we move to losing move for opponent
			if (p[i] > mn && p[i] < win) {
				ans++;
				win = p[i];
			}
			
			mn = min(mn, p[i]);
		}
		cout << ans << '\n';
	}
	return 0;
}
