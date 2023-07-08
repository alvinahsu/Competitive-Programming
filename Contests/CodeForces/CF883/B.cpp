/*
*  File: CF883B
*  Author: Alvin Hsu
*  Date: 07/07/2023 10:32:34
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
		vector<string> v(3);
		for (auto &a : v){
			cin >> a;
		}
		bool ok = false;
		string ans = "DRAW";
		for (int i = 0; !ok && i < 3; i++){
			bool nxt = true;
			for (int j = 1; j < 3; j++){
				nxt &= (v[j][i] == v[j-1][i]);
			}
			if (nxt && v[0][i] != '.'){
				ok = true;
				ans = v[0][i];
				break;
			}
		}
		for (int i = 0; !ok && i < 3; i++){
			bool nxt = true;
			for (int j = 1; j < 3; j++){
				nxt &= (v[i][j] == v[i][j-1]);
			}
			if (nxt && v[i][0] != '.'){
				ok = true;
				ans = v[i][0];
				break;
			}
		}
		if (!ok && v[1][1] != '.'){
			bool nxt = v[1][1] == v[0][0] && v[1][1] == v[2][2];
			
			nxt |= (v[1][1] == v[0][2] && v[1][1] == v[2][0]);
			if (nxt) ans = v[1][1];
		}
		cout << ans << '\n';
	}
	return 0;
}
