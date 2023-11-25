/*
*  File: CFCodeTonR7B
*  Author: Alvin Hsu
*  Date: 11/25/2023 06:28:12
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
		vector<int> vis(n);
		for (int i = n-2; i >= 0; i--){
			int j = i;
			while(j+1 < n && !vis[j] && s[j] == 'A' && s[j+1] == 'B'){
				vis[j] = 1;
				ans++;
				swap(s[j], s[j+1]);
				j++;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
