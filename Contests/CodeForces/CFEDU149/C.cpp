/*
*  File: CFEDU149C
*  Author: Alvin Hsu
*  Date: 05/25/2023 07:22:49
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
		string ans = s;
		int n = s.size();
		for (int i = 0; i < n; i++){
			if (s[i] == '?') s[i] = '0';
			else break;
		}
		for (int i = n-1; i >= 0; i--){
			if (s[i] == '?') s[i] = '1';
			else break;
		}
		for (int i = 0; i <  n; i++){
			if (s[i] == '?'){
				s[i] = s[i-1];
			}
		}
		cout << s << '\n';
	}
	return 0;
}
