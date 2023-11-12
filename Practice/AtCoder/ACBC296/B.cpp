/*
*  File: ACBC296B
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
	
	string ans = "";
	for (int j = 8; j >= 1; j--){
		for (int i = (int)'a'; i <= 'a'+7; i++){
			char c;
			cin >> c;
			if (c == '*') {
				cout << (char)i << j << '\n';
			}
		}
	}
	
	return 0;	
}
