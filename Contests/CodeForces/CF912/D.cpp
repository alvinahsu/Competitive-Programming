/*
*  File: CF912D
*  Author: Alvin Hsu
*  Date: 11/30/2023 08:28:47
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
	#define int long long
	int n,q;
	cin >> n >> q;
	vector<int> v(n);
	for (int i = 0; i < n; i++){
		cin >> v[i];
	}
	while(q--){
		int k;
		cin >> k;
		int ans = 0;
		vector<int> vv = v;
		//try to have bit i included
		for (int i = 62; i >= 0; i--){
			int tot = 0;
			int mask = 0;
			for (int j = 0; j <= i; j++){
				mask |= (1ll << j);
			}
			vector<int> curr(n);
			for (int j = 0; j < n; j++){
				int l = 0, r = (1ll<<i) - (vv[j]&mask);
				int upper = mask;
				while(l < r){
					int m = l + (r - l) / 2;
					int newNum = (vv[j]&mask) + m;
					if (newNum > upper){
						r = m-1;
					}
					else if (newNum&(1ll<<i)){
						r = m;
					}
					else {
						l = m+1;
					}
				}
				if (tot > k) break;
				curr[j] = l;
				tot += l;
			}
			if (tot <= k){
				for (int j = 0; j < n; j++){
					vv[j] += curr[j];
				}
				k -= tot;
				ans |= (1ll << i);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
