/*
*  File: CF893C
*  Author: Alvin Hsu
*  Date: 08/15/2023 16:30:02
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
		vector<int> vis(n+1);
		for (int i = 1; i <= n; i++){
			int curr = i;
			while(curr <= n && !vis[curr]){
				cout << curr << ' ';
				vis[curr] = 1;
				curr *= 2;
			}
		}
		cout << '\n';
	}
	return 0;
}
