/*
*  File: CF886C
*  Author: Alvin Hsu
*  Date: 07/23/2023 15:07:49
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
		vector<string> v(8);
		for (auto &a : v){
			cin >> a;
		}
		string ans;
		bool done = false;
		for (int i = 0; !done && i < 8; i++){
			for (int j = 0; !done && j < 8; j++){
				if (v[i][j] != '.'){
					ans += v[i][j];
					while(i+1 < 8 && v[i+1][j] != '.'){
						ans += v[i+1][j];
						i++;
						done = true;
					}
					while(j+1 < 8 && v[i][j+1] != '.'){
						ans += v[i][j+1];
						j++;
						done = true;
					}
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
