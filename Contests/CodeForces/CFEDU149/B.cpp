/*
*  File: CFEDU149B
*  Author: Alvin Hsu
*  Date: 05/25/2023 07:22:49
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
		string s;
		cin >> s;
		int sz = 2;
		vector<int> seg;
		for (int i = 1; i < n; i++){
			if (s[i] == s[i-1]) sz++;
			else {
				seg.push_back(sz);
				sz = 2;
			}
		}
		seg.push_back(sz);
		cout << *max_element(seg.begin(), seg.end()) << '\n';
	}
	return 0;
}