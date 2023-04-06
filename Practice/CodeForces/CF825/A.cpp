/*
*  File: CF825A
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

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int>a(n), b(n);
		vector<int>cntA(2), cntB(2);
		for (auto &x : a){
			cin >> x;
			cntA[x]++;
		}
		for (auto &x : b){
			cin >> x;
			cntB[x]++;
		}
		int diff = 0;
		for (int i = 0; i < n; i++) {
			diff += a[i] != b[i];
		}
		if (diff == 0){
			cout << 0 << '\n';
		}
		else if (cntA == cntB){
			cout << 1 << '\n';
		}
		else {
			cout << min(1 + (abs(cntA[0] - cntB[0])), diff) << '\n';
		}
		
	}
	return 0;	
}
