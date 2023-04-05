/*
*  File: CF863A
*  Author: Alvin Hsu 
*  Date: 04/04/2023 18:36:29
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
		char d;
		cin >> n >> d;
		string s;
		cin >> s;
		bool end = true;
		for (int i = 0; i < n; i++){
			if (d > s[i] && end) {
				end = false;
				cout << d;
			}
			cout << s[i];
		}
		if (end){
			cout << d;
		}
		cout << '\n';
	}
	return 0;	
}
