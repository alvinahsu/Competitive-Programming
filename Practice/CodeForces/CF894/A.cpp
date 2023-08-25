/*
*  File: CF894A
*  Author: Alvin Hsu
*  Date: 08/24/2023 13:32:25
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
	string s = "vika";
	while(t--){
		int n,m;
		cin >> n >> m;
		vector<string> v(n);
		for (auto &a : v){
			cin >> a;
		}
		int k = 0;
		for (int i = 0; i < m; i++){
			bool ok = false;
			for (int j = 0; !ok && j < n; j++){
				if (k < 4 && v[j][i] == s[k]){
					ok = true;
					k++;
					break;
				}
			}
		}
		cout << (k == 4 ? "YES" : "NO") << '\n';
	}
	return 0;
}
