/*
*  File: CF870B
*  Author: Alvin Hsu
*  Date: 05/05/2023 07:28:53
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
		vector<int>v(n);
		for (auto &a : v){
			cin >> a;
		}
		int g = 0;
		for (int i = 0; i < n - i - 1; i++){
			int mx = max(v[i], v[n-i-1]) - min(v[i], v[n-i-1]);
			g = gcd(mx, g);
		}
		cout << g << '\n';
		
	}
	return 0;
}
