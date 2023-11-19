/*
*  File: CF910A
*  Author: Alvin Hsu
*  Date: 11/19/2023 06:28:26
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
		int n,k;
		cin >> n >> k;
		string s;
		cin >> s;
		int cntB = count(s.begin(), s.end(), 'B');
		if (cntB == k) {
			cout << 0 << '\n';
		}
		else if (cntB > k){
			//remove cntB - k
			cout << "1" << '\n';
			int diff = cntB - k;
			int i = 0;
			for (; diff && i < n; i++){
				if (s[i] == 'B') diff--;
			}
			cout << i << " " << "A" << '\n';
		}
		else {
			cout << "1" << '\n';
			int diff = k - cntB;
			int i = 0;
			for (; diff && i < n; i++){
				if (s[i] == 'A') diff--;
			}
			cout << i << " " << "B" << '\n';
		}
	}
	return 0;
}
