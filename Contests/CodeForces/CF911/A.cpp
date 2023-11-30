/*
*  File: CF911A
*  Author: Alvin Hsu
*  Date: 11/26/2023 06:27:44
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
		string s;
		cin >> s;
		int ans = 0;
		int curr = 0;
		bool fill = 0;
		for (int i = 0; i < n; i++){
			if (s[i] == '.'){
				if (curr < 2){
					curr++;
					ans++;
				}
				else {
					fill = 1;
				}
			}
			else {
				curr = 0;
				
			}
		}
		if (fill) ans = 2;
		cout << ans << '\n';
	}
	return 0;
}
