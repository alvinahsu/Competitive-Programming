/*
*  File: CF904B
*  Author: Alvin Hsu
*  Date: 10/21/2023 22:46:09
*/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../../Templates/debug.h"
#else
#define dbg(...)
#endif


int main(){
	#define int long long
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n;
		string s;
		cin >> n >> s;
		int gap = 0, j = n-1, sz = 0, ans = 0;
		for (int i = n-1; i >= 0; i--){
			if (!gap){
				while(j >= 0 && s[j] == '1'){
					sz++;
					j--;
				}
				while(j >= 0 && s[j] == '0'){
					gap++;
					j--;
				}
			}
			assert(gap >= 0);
			if (gap){
				gap--;
				ans += sz;
				cout << ans << ' ';
			}
			else {
				cout << -1 << ' ';
			}
		}
		cout << '\n';
	}
	return 0;
}
