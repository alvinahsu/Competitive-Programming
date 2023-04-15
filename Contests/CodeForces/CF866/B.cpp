/*
*  File: CF866B
*  Author: Alvin Hsu
*  Date: 15/04/2023 17:01:56
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
		string s;
		cin >> s;
		int n = s.size();
		s += s;
		int mx = 0, curr = 0;
		for (int i = 0; i < s.size(); i++){
			if (s[i] == '1') {
				curr++;
			}
			else {
				mx = max(mx, curr);
				curr = 0;
			}
		}
		mx = max(curr, mx);
		if (mx == 2*n){
			cout << 1ll*n*n << '\n';
		}
		else {
			long long ans = 0;
			for (int i = 1; i <= mx; i++){
				ans = max(ans, 1ll*(mx-i+1)*i);
			}
			cout << ans << '\n';
		}
	}
	return 0;
}
