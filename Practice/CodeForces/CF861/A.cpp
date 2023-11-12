/*
*  File: CF861A
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
		int l,r;
		cin >> l >> r;
		int mx = -1, ans = 0;
		for (int i = l; i <= r; i++){
			string s = to_string(i);
			int mxNum = *max_element(s.begin(), s.end()) - '0';
			int mnNum = *min_element(s.begin(), s.end()) - '0';
			int sum = mxNum - mnNum;
			if (sum > mx){
				mx = sum;
				ans = i;
			}
			if (mx == 9) break;
		}
		cout << ans << '\n';
	}
	
	return 0;	
}
