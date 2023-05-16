/*
*  File: UCSDSP23_5B
*  Author: Alvin Hsu
*  Date: 05/15/2023 18:17:26
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
	string n;
	cin >> n;
	int ans = 0;
	for (int i = 1; i <= 1e6+5; i++){
		string s = to_string(i);
		if (s.size()*2 <= n.size()){
			if (stoll(s+s) <= stoll(n)) ans++;
		}
	}
	cout << ans << '\n';
	return 0;
}
