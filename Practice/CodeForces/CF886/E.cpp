/*
*  File: CF886E
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
		long long n,c;
		cin >> n >> c;
		vector<int> v(n);
		for (auto &a : v){
			cin >> a;
		}
		long long l = 0, r = 1e9;
		while(l < r){
			long long w = l + (r - l + 1) / 2;
			long long rem = c;
			bool down = false;
			for (int  i = 0; i < n; i++){
				long long nv = v[i] + w;
				rem -= (nv * nv);
				if (rem < 0){
					down = true;
					break;
				}
			}
			if (down){
				r = w-1;
			}
			else {
				l = w;
			}
		}
		cout << l/2 << '\n';
	}
	return 0;
}
