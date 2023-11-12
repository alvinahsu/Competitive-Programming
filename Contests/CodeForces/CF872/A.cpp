/*
*  File: CF872A
*  Author: Alvin Hsu
*  Date: 05/08/2023 05:01:11
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
		int cnt = count(s.begin(), s.end(), s[0]);
		if (cnt == s.size()){
			cout << -1 << '\n';
			continue;
		}
		cout << s.size() - 1 << '\n';
	}
	return 0;
}
