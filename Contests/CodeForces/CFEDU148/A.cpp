/*
*  File: CFEDU148A
*  Author: Alvin Hsu
*  Date: 05/12/2023 07:33:53
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
		if (cnt == s.size() || cnt == s.size()-1){
			cout << "NO" << '\n';
		}
		else {
			cout << "YES" << '\n';
		}
	}
	return 0;
}
