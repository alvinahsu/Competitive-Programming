/*
*  File: CF879C
*  Author: Alvin Hsu
*  Date: 06/19/2023 13:38:36
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
	int tt;
	cin >> tt;
	while(tt--){
		int n;
		cin >> n;
		string s,t;
		cin >> s >> t;
		int revDiff = 0, diff = 0;
		for (int i = 0; i < n; i++){
			revDiff += s[i] != t[n-i-1];
			diff += s[i] != t[i];			
		}
		if (diff <= 1) {
			cout << diff << '\n';
			continue;
		}
		if (!revDiff) {
			cout << 2 << '\n';
			continue;
		}
		
		//we want reverse, so revDiff-1 being odd guarantees one is already in reverse
		int revAns = 2 * revDiff - (revDiff%2 == 0);
		//already in place (diff-1 makes same parity), we don't reverse
		int diffAns = 2 * diff - (diff&1);
		cout << min(revAns, diffAns) << '\n';
	}
	return 0;
}