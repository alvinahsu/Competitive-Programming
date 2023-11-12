/*
*  File: ACBC296A
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
	
	int n;
	string s;
	cin >> n >> s;
	char c = '0';
	for (int i = 0; i < n; i++){
		if (c == s[i]){
			cout << "No" << '\n';
			return 0;
		}
		c = s[i];
	}
	cout << "Yes" << '\n';
	
	return 0;	
}
