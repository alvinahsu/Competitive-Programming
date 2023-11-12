/*
*  File: CFEDU147A
*  Author: Alvin Hsu
*  Date: 04/20/2023 22:27:43
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
		long long ans = 1;
		for (int i = 0; i < s.size(); i++){
			if (i == 0 && s[i] == '0') {
				ans = 0;
				break;
			}
			if (i == 0 && s[i] == '?') {
				ans *= 9;
			}
			else if (s[i] == '?') {
				ans *= 10;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}

