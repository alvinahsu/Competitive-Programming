/*
*  File: ACBC296C
*  Author: Alvin Hsu 
*  Date: 04/04/2023 18:37:10
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
	
	int n,x;
	cin >> n >> x;
	vector<int> v(n);
	for (auto &a : v){
		cin >> a;
	}
	sort(v.begin(), v.end());
	bool ok = false;
	for (auto &a : v){
		int find = x + a;
		ok |= (binary_search(v.begin(), v.end(), find));
	}
	cout << (ok ? "Yes" : "No") << '\n';
		
	return 0;	
}
