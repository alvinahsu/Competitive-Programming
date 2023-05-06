/*
*  File: CF871C
*  Author: Alvin Hsu
*  Date: 05/06/2023 07:33:44
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
		map<string,int> m;
		m["00"] = m["01"] = m["10"] = m["11"] = 1e8;
		while(n--){
			int x;
			string s;
			cin >> x >> s;
			m[s] = min(m[s], x);
		}
		int ans = (int)1e8;
		ans = min(ans, m["01"] + m["10"]);
		ans = min(ans, m["11"]);
		cout << (ans == (int)1e8 ? -1 : ans) << '\n';
		
	}
	return 0;
}
