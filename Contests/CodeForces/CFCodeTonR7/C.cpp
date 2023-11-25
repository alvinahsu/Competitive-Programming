/*
*  File: CFCodeTonR7C
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
		int n,x;
		cin >> n >> x;
		vector<int> a(n), b(n);
		for (int i = 0; i < n; i++){
			cin >> a[i];
		}
		for (int i = 0; i < n; i++){
			cin >> b[i];
		}
		vector<int> idx(n);
		iota(idx.begin(), idx.end(), 0);
		sort(idx.begin(), idx.end(), [&](int i, int j){
			return a[i] > a[j];
		});
		sort(b.begin(), b.end());
		reverse(b.begin(), b.end());
		// dbg(b, idx);
		vector<int> newB(n);
		bool ok = true;
		for (int i = 0, j = n-x, k = 0; i < n; i++){
			// dbg(j);
			if (j >= 0 && j < n){
				ok &= (a[idx[i]] > b[j]);
				newB[idx[i]] = b[j];
				j++;
			}
			else {
				ok &= (a[idx[i]] <= b[k]);
				newB[idx[i]] = b[k];
				k++;
			}
		}
		// dbg(newB);
		if (ok){
			cout << "YES" << '\n';
			for (int i = 0; i < n; i++){
				cout << newB[i] << " \n"[i == n-1];
			}
		}
		else{
			cout << "NO" << '\n';
		}
	}
	return 0;
}
