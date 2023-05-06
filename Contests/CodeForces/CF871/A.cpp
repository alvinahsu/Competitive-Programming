/*
*  File: CF871A
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
	string s = "codeforces";
	while(t--){
		string str;
		cin >> str;
		int cnt = 0;
		for (int i = 0; i < s.size(); i++){
			cnt += s[i] != str[i];
		}
		cout << cnt << '\n';
	}
	return 0;
}
