/*
*  File: CF900E
*  Author: Alvin Hsu
*  Date: 09/26/2023 07:25:15
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
		vector<int> v(n);
		vector<vector<int>> have(32);
		for (int i = 0; i < n; i++){
			cin >> v[i];
			for (int j = 0; j < 31; j++){
				if (!(v[i]&(1 << j))){
					have[j].push_back(i);
				}
			}
		}
		int q;
		cin >> q;
		while(q--){
			int l,k;
			cin >> l >> k;
			l--;
			int L = l, R = n-1;
			while(L < R){
				int m = L + (R - L + 1) / 2;
				int curr = 0;
				for (int i = 0; i < 31; i++){
					if (v[l]&(1 << i)){
						auto nxtBad = lower_bound(have[i].begin(), have[i].end(), l);
						int idx = nxtBad == have[i].end() ? n : *nxtBad;
						if (idx > m){
							curr |= (1 << i);
						}
					}
				}
				if (curr >= k){
					L = m;
				}
				else {
					R = m-1;
				}
			}
			int curr = 0;
			for (int i = 0; i < 31; i++){
				if (v[l]&(1 << i)){
					auto nxtBad = lower_bound(have[i].begin(), have[i].end(), l);
					int idx = nxtBad == have[i].end() ? n : *nxtBad;
					if (idx > L){
						curr |= (1 << i);
					}
				}
			}
			if (curr >= k){
				cout << L + 1 << ' ';
			}
			else {
				cout << -1 << ' ';
			}
		}
		cout << '\n';
		
	}
	return 0;
}
