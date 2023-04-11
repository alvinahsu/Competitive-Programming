/*
*  File: UCSDSP23_0A
*  Author: Alvin Hsu
*  Date: 11/04/2023 09:24:55
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
	int n;
	cin >> n;
	vector<int> cnt(n+1);
	for (int i = 0; i < n-1; i++){
		int a,b;
		cin >> a >> b;
		cnt[a]++;
		cnt[b]++;
	}
	bool ok = false;
	for (int i = 1; i <= n; i++){
		if (cnt[i] == n-1){
			ok = true;
		}
	}
	cout << (ok ? "Yes" : "No") << '\n';
	return 0;	
}
