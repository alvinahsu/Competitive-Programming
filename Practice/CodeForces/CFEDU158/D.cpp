/*
*  File: CFEDU158D
*  Author: Alvin Hsu
*  Date: 11/28/2023 20:12:02
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
	vector<int> v(n);
	for (int i = 0; i < n; i++){
		cin >> v[i];
	}
	vector<int> pref(n), suff(n);
	int currMx = 0;
	for (int i = 0; i < n; i++){
		currMx = max(v[i], currMx+1);
		pref[i] = currMx;
	}
	currMx = 0;
	for (int i = n-1; i >= 0; i--){
		currMx = max(v[i], currMx+1);
		suff[i] = currMx;
	}
	dbg(pref, suff);
	//if we start at i
	int ans = 2e9;
	for (int i = 0; i < n; i++){
		//start left
		int pos1 = pref[i];
		//then go right
		if (i+1 < n){
			int endAt = pos1 - (i+1);
			if (endAt < suff[i+1]) pos1 += suff[i+1] - endAt;
		}
		
		//start right
		int pos2 = suff[i];
		if (i-1 >= 0){
			int endAt = pos2 - (n - i);
			if (endAt < pref[i-1]) pos2 += pref[i-1] - endAt;
		}
		//then go left
		ans = min(ans, max(pos1, pos2));
	}
	cout << ans << '\n';	
	return 0;
}
