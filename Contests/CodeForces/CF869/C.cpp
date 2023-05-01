/*
*  File: CF869C
*  Author: Alvin Hsu
*  Date: 04/29/2023 07:30:07
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
	int n,q;
	cin >> n >> q;
	vector<int>v(n);
	for (int i = 0; i < n; i++){
		cin >> v[i];
	}
	vector<int> pref(n+1);
	for (int i = 0; i+2 < n; i++){
		pref[i+1] = pref[i];
		if (v[i] >= v[i+1] && v[i+1] >= v[i+2]){
			pref[i+1]++;
		}
	}
	for (int i = 0; i < q; i++){
		int l,r;
		cin >> l >> r;
		int rem = 0;
		if (r - l + 1 >= 3){
			rem = pref[r-2] - pref[l-1];
		}
		cout << r - l + 1 - rem << '\n';
	}
	return 0;
}
