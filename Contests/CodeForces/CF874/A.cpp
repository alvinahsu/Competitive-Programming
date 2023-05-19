/*
*  File: CF874A
*  Author: Alvin Hsu
*  Date: 05/19/2023 07:31:18
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
		string s;
		cin >> n >> s;
		set<string> st;
		for (int i = 0; i+1 < n; i++){
			st.insert(s.substr(i, 2));
		}
		cout << st.size() << '\n';
	}
	return 0;
}
