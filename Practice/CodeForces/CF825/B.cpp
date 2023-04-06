/*
*  File: CF825B
*  Author: Alvin Hsu
*  Date: 06/04/2023 16:11:26
*/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../../Templates/debug.h"
#else
#define dbg(...)
#endif

//gcd = a * lcm / b
//lcm = gcd * b / a
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
		bool ok = true;
		for (int i = 1; i < n-1; i++){
			if (v[i] % gcd(v[i-1], v[i+1])) ok = false;
		}
		
		cout << (ok ? "YES" : "NO") << '\n';		
	}
	return 0;	
}
