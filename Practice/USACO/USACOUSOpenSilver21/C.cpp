/*
*  File: USACOUSOpenSilver21C
*  Author: Alvin Hsu
*  Date: 07/30/2023 14:00:47
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
	int n,k,l;
	cin >> n >> k >> l;
	vector<int> v(n);
	for (auto &a : v){
		cin >> a;
	}
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	int L = 0, R = 1e5;
	while(L < R){
		int m = L + (R - L + 1) / 2;
		long long tot = 1ll * l * k;
		int cnt = 0;
		for  (int i = 0; i < n; i++){
			if (v[i] < m){
				int need = m - v[i];
				if (k < need) continue;
				if (tot >= need){
					tot -= need;
					cnt++;
				}
			}
			else {
				cnt++;
			}
		}
		if (cnt >= m){
			L = m;
		}
		else {
			R = m-1;
		}
	}
	cout << L << '\n';
	return 0;
}
