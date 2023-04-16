/*
*  File: GORAA
*  Author: Alvin Hsu
*  Date: 15/04/2023 21:08:25
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
	for (int t = 1; t <= tt; t++){
		vector<int>v(26);
		for (int i = 0; i < 26; i++) {
			cin >> v[i];
		}
		int q;
		cin >> q;
		set<string> st;
		bool ok = true;
		while(q--){
			string s;
			cin >> s;
			for (int i = 0; i < s.size(); i++){
				s[i] = v[s[i]-'A']+'0';
			}
			if (st.find(s) != st.end()){
				ok = false;
			}
			st.insert(s);
		}
		cout << "Case #" << t << ": " << (ok ? "NO" : "YES") << '\n';
	}
	return 0;
}
