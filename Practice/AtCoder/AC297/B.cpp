/*
*  File: AC297B
*  Author: Alvin Hsu
*  Date: 11/04/2023 09:03:51
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
	string s;
	cin >> s;
	bool ok = true;
	for (int i = 0; i < s.size(); i++){
		for (int j = i+1; j < s.size(); j++){
			if (s[i] == 'B' && s[j] == 'B'){
				ok &= (((i+1)^(j+1))&1);
			}
			if (s[i] == 'R' && s[j] == 'R') {
				int k = find(s.begin(), s.end(), 'K') - s.begin();
				ok &= (k > i && k < j);
			}
		}
	}
	cout << (ok ? "Yes" : "No") << '\n';
	return 0;
}
