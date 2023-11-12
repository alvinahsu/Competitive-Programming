/*
*  File: CF873B
*  Author: Alvin Hsu
*  Date: 05/14/2023 07:33:14
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
			a--;
		}
		int g = 0;
		for (int i = 0; i < n; i++) {
			g = gcd(g, abs(v[i] - i));
		}
		cout << g << '\n';
	}
	return 0;
}
