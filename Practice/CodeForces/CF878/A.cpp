/*
*  File: CF878A
*  Author: Alvin Hsu
*  Date: 06/11/2023 10:24:26
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
		string s;
		cin >> s;
		string ans = "";
		for (int i = 0; i < n; ){
			char c = s[i++];
			ans += c;
			while(i < n && s[i] != c) i++;
			assert(s[i] == c);
			i++;
		}
		cout << ans << '\n';
	}
	return 0;
}
