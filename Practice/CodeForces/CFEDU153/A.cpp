/*
*  File: CFEDU153A
*  Author: Alvin Hsu
*  Date: 08/20/2023 10:44:49
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
		int bal = 0;
		int n = s.size();
		bool ok = s == "()";
		if (!ok){
			cout << "YES" << '\n';
			string s1, s2;
			for (int i = 0; i < 2*n; i++){
				if (i < n){
					s1 += '(';
				}
				else {
					s1 += ')';
				}
				s2 += (i%2==0 ? '(' : ')');
			}
			if (s2.find(s) == string::npos){
				cout << s2 << '\n';
			}
			else {
				assert(s1.find(s) == string::npos);
				cout << s1 << '\n';
			}
		}
		else {
			cout << "NO" << '\n';
		}
	}
	return 0;
}
