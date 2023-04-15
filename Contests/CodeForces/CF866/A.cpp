/*
*  File: CF866A
*  Author: Alvin Hsu
*  Date: 15/04/2023 17:01:56
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
		string curr = "";
		for (int i = 0; i < s.size(); i++){
			if (curr.empty() && s[i] != '^') {
				curr += "^";
			}
			curr += s[i];
			if (curr.back() == '_') {
				if (i+1 < s.size()){
					if (s[i+1] != '^') {
						curr += "^";
					}
				}
				else {
					curr += "^";
				}
			}
		}
		if (curr.size() == 1){
			assert(curr[0] == '^');
			curr += "^";
		}
		cout << (int)curr.size() - (int)s.size() << '\n';
	}
	return 0;
}
